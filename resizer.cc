//File: resizer.cc
//Date: Sun Dec 22 15:03:21 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <limits>
#include "resizer.hh"
#include "render/filerender.hh"
#include "filter.hh"

Img ImageResizer::resize(int w, int h) {
	Img i(1, 1);
	if (w == greyimg.w and h == greyimg.h)
		return orig_img;
	if (w < greyimg.w)
		remove_column(greyimg.w - w);
	return i;
}

// repeatly remove n=number columns
void ImageResizer::remove_column(int number) {
	print_debug("Removing %d columns...\n", number);
	result = orig_img;
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

Matrix ImageResizer::cal_all_energy() const {
	Matrix m(greyimg.w, greyimg.h);
	REP(i, m.h) REP(j, m.w) {
		m.get(i, j) = Filter::prewitt_convolve(greyimg, i, j);
	}
	return m;
}

Path ImageResizer::get_path(const Matrix& e, int min_i) {
	Path ret(e.h);
	ret[e.h - 1] = min_i;
	int nowx = min_i;
	for (int i = e.h - 2; i >= 0; i --) {
		real_t min = e.get(i, nowx);
		if (nowx != 0)
			if (update_min(min, e.get(i, nowx - 1)))
				nowx --;
		if (nowx != e.w - 1)
			if (update_min(min, e.get(i, nowx + 1)))
				nowx ++;
		ret[i] = nowx;
	}
	return ret;
}

void ImageResizer::remove_vert_path(const Path& p) {
	Img ret(result.w - 1, result.h);
	REP(i, result.h) {
		REP(j, result.w - 1)
			ret.set_pixel(i, j, result.get_pixel(i, j < p[i] ? j : j + 1));
	}

	imgptr test = make_shared<Img>(result);
	REP(i, result.h)
		test->set_pixel(i, p[i], Color(0, 0, 0));
	static int i = 0;
	FileRender rd(test, ("path" + to_string(i++) + ".png").c_str());
	rd.finish();

	result = ret;
	greyimg = GreyImg(result);
	energy = cal_all_energy();
}
