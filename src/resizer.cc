//File: resizer.cc
//Date: Sun Dec 29 02:42:21 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <limits>
#include <future>
#include "prgReporter.hh"
#include "resizer.hh"
#include "imgDist.hh"
#include "render/filerender.hh"

void ImageResizer::resize(int w, int h) {
	result = orig_img;
	if (w < greyimg.w)
		remove_column(greyimg.w - w);
	if (h < greyimg.h)
		remove_row(greyimg.h - h);
}


void ImageResizer::remove_row(int number) {
	print_debug("Removing %d row...\n", number);
	weight_mask = weight_mask.transpose();
	energy = energy.transpose();
	result = img_transpose(result);
	greyimg = img_transpose(greyimg);
	remove_column(number);
	result = img_transpose(result);
	greyimg = img_transpose(greyimg);
}

// repeatly remove n=number columns
void ImageResizer::remove_column(int number) {
	int target_w = result.w - number;
	ImageDist* result_set;
	if (optimized)
		result_set = new ImageDist(result, number);

	print_debug("Removing %d columns...\n", number);
	ProgressReporter prg(number);
	HWTimer timer("Removing columns");
	REP(k, number) {
		remove_one_column();
		if (optimized)
			result_set->results.push_back(result.get_resized(target_w, result.h));
		prg.update(1);
	}

	if (optimized) {
		result_set->calculate();
		delete result_set;
	}
}

void ImageResizer::remove_one_column() {
	int w = greyimg.w, h = greyimg.h;
	Matrix acc_energy(greyimg.w, greyimg.h);	// TODO can be used incrementally

	auto point_weight = [&](int i, int j) {
		return energy.get(i, j) + weight_mask.get(i, j);
	};

	REP(j, w) {		// first row
		acc_energy.get(0, j) = point_weight(0, j);
	}
	REPL(i, 1, h) {
		acc_energy.get(i, 0) = min(acc_energy.get(i - 1, 0), acc_energy.get(i - 1, 1))
			+ point_weight(i, 0);
		acc_energy.get(i, w - 1) = min(acc_energy.get(i - 1, w - 1), acc_energy.get(i - 1, w - 2))
			+ point_weight(i, w - 1);
		REPL(j, 1, w - 1)
			acc_energy.get(i, j) = min(acc_energy.get(i - 1, j - 1), acc_energy.get(i - 1, j), acc_energy.get(i - 1, j + 1))
				+ point_weight(i, j);
	}
	real_t min_e = numeric_limits<real_t>::max();
	int min_i;
	REP(j, w)
		if (update_min(min_e, acc_energy.get(h - 1, j)))
			min_i = j;
	auto path = ImageResizer::get_path(acc_energy, min_i);
	remove_vert_path(path);
}

void ImageResizer::cal_all_energy() {
	energy = Matrix(greyimg.w, greyimg.h);
	REP(i, energy.h) REP(j, energy.w)
		energy.get(i, j) = convolve(i, j);
}

Path ImageResizer::get_path(const Matrix& e, int min_i) {
	Path ret(e.h);
	ret[e.h - 1] = min_i;
	int nowx = min_i;
	for (int i = e.h - 2; i >= 0; i --) {
		real_t min = e.get(i, nowx);
		int minx = nowx;
		if (nowx != 0)
			if (update_min(min, e.get(i, nowx - 1)))
				minx = nowx - 1;
		if (nowx != e.w - 1)
			if (update_min(min, e.get(i, nowx + 1)))
				minx = nowx + 1;
		ret[i] = minx;
		nowx = minx;
	}
	return ret;
}

void ImageResizer::remove_vert_path(const Path& p) {
//	HWTimer timer("remove one path");

	// update result
	Img ret(result.w - 1, result.h);
	REP(i, result.h) {
		memcpy(&ret.get_pixel(i, 0), &result.get_pixel(i, 0), (p[i] * sizeof(Color)));
		if (p[i] != result.w - 1)
			memcpy(&ret.get_pixel(i, p[i]), &result.get_pixel(i, p[i] + 1), (result.w - p[i] - 1) * sizeof(Color));
	}
	/*
	 *imgptr test = make_shared<Img>(result);
	 *REP(i, result.h)
	 *    test->set_pixel(i, p[i], Color(0, 0, 0));
	 *static int i = 0;
	 *FileRender rd(test, ("path" + string_format("%02d", (i ++)) + ".png").c_str());
	 *rd.finish();
	 */

	result = move(ret);
	greyimg = GreyImg(result);
	//cal_all_energy();
	update_energy(p);

	// update weight
	Matrix new_weight(weight_mask.w - 1, weight_mask.h);
	REP(i, weight_mask.h) {
		memcpy(&new_weight.get(i, 0), &weight_mask.get(i, 0), p[i] * sizeof(Matrix::vtype));
		if (p[i] != weight_mask.w - 1)
			memcpy(&new_weight.get(i, p[i]), &weight_mask.get(i, p[i] + 1), (weight_mask.w - p[i] - 1) * sizeof(Matrix::vtype));
	}
	weight_mask = move(new_weight);
}

// update energy, after greyimg is correctly updated
void ImageResizer::update_energy(const Path& p) {
	Matrix newe(energy.w - 1, energy.h);
	REP(i, energy.h) REP(j, energy.w - 1) {
		int del_index = p[i];
		if (j < del_index - 1)
			newe.get(i, j) = energy.get(i, j);
		else if (j == del_index - 1 or j == del_index)
			newe.get(i, j) = convolve(i, j);
		else
			newe.get(i, j) = energy.get(i, j + 1);
	}
	energy = move(newe);
}


void ImageResizer::update_mask(const Img& mask_img) {
	REP(i, mask_img.h) REP(j, mask_img.w) {
		const Color& c = mask_img.get_pixel(i, j);
		if (c.x - c.get_min() > MASK_COLOR_THRES) {		// red, discard
			weight_mask.get(i, j) = -MASK_WEIGHT;
		}
		if (c.y - c.get_min() > MASK_COLOR_THRES) {		// green, keep
			weight_mask.get(i, j) = MASK_WEIGHT;
		}
	}
	weight_mask = ImageResizer::blurMatrix(weight_mask);
}

Matrix ImageResizer::blurMatrix(const Matrix& m) {
	GreyImg img(m);
	img = Filter::GaussianBlur(img);
	Matrix ret(m.w, m.h);
	REP(i, m.h) REP(j, m.w)
		ret.get(i, j) = img.get_pixel(i, j);
	return ret;
}
