//File: resizer.cc
//Date: Sun Dec 22 12:42:17 2013 +0800
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
	number = 1;
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
		acc_energy.get(i, h - 1) = min(acc_energy.get(i - 1, h - 1), acc_energy.get(i - 1, h - 2))
			+ point_weight(i, h - 1);
		REPL(j, 1, w - 1)
			acc_energy.get(i, j) = min(acc_energy.get(i - 1, j - 1), acc_energy.get(i - 1, j), acc_energy.get(i - 1, j + 1))
				+ point_weight(i, j);
	}
	real_t min_e = numeric_limits<real_t>::max();
	int min_i;
	REP(j, w)
		if (update_min(min_e, acc_energy.get(h - 1, j)))
			min_i = j;
	auto path = ImageResizer::get_path(acc_energy, min_e, min_i);
	remove_vert_path(path);
}

Matrix ImageResizer::cal_all_energy() const {
	Matrix m(greyimg.w, greyimg.h);
	REP(i, m.w) REP(j, m.h) {
		bool inside = (between(i, 1, m.w - 1) && between(j, 1, m.h - 1));
		m.get(i, j) = Filter::prewitt_convolve(greyimg, i, j, inside);
	}
	return m;
}

Path ImageResizer::get_path(const Matrix& e, real_t min_e, int min_i) {
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
	//Img new_img(orig_img.w - 1, orig_img.h);
	imgptr pathed = make_shared<Img>(orig_img);
	REP(i, orig_img.h) {
		pathed->set_pixel(i, p[i], Color(0, 0, 0));
	}
	FileRender render(pathed, "path.png");
	render.finish();
}
