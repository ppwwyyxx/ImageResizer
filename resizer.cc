//File: resizer.cc
//Date: Sat Dec 28 13:04:58 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <limits>
#include "resizer.hh"
#include "render/filerender.hh"

void ImageResizer::resize(int w, int h) {
	result = orig_img;
	if (w < greyimg.w)
		remove_column(greyimg.w - w);
}

// repeatly remove n=number columns
void ImageResizer::remove_column(int number) {
	print_debug("Removing %d columns...\n", number);
	HWTimer timer("Removing columns");
	REP(k, number) {
		remove_one_column();
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
	REP(i, energy.h) REP(j, energy.w) {
		energy.get(i, j) = convolve(i, j);
	}
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
	Img ret(result.w - 1, result.h);
	REP(i, result.h)
		REP(j, result.w - 1)
			ret.set_pixel(i, j, result.get_pixel(i, (j < p[i]) ? j : j + 1));

	Matrix new_weight(weight_mask.w - 1, weight_mask.h);
	REP(i, weight_mask.h)
		REP(j, weight_mask.w - 1)
			new_weight.get(i, j) = weight_mask.get(i, (j < p[i]) ? j : j + 1);
	weight_mask = new_weight;


	/*
	 *imgptr test = make_shared<Img>(result);
	 *REP(i, result.h)
	 *    test->set_pixel(i, p[i], Color(0, 0, 0));
	 *static int i = 0;
	 *FileRender rd(test, ("path" + string_format("%02d", (i ++)) + ".png").c_str());
	 *rd.finish();
	 */

	result = ret;
	greyimg = GreyImg(result);
//	cal_all_energy();
	update_energy(p);
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
