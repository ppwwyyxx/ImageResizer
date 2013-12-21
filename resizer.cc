//File: resizer.cc
//Date: Sun Dec 22 02:43:09 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include "resizer.hh"
#include "filter.hh"

imgptr ImageResizer::resize(int w, int h) {
	if (w == orig_img->w and h == orig_img->h)
		return orig_img;
	imgptr ret;

	if (w < orig_img->w)
		ret = remove_column(orig_img, orig_img->w - w);
}

// repeatly remove n=number columns
imgptr ImageResizer::remove_column(const imgptr& img, int number) {

}

Matrix* ImageResizer::cal_all_energy() const {
	Matrix m(greyimg.w, greyimg.h);
	REP(i, m.w) REP(j, m.h) {
		bool inside = (between(i, 1, m.w - 1) && between(j, 1, m.h - 1));
		m.get(i, j) = Filter::prewitt_convolve(greyimg, i, j, inside);
	}
	return new Matrix(move(m));
}
