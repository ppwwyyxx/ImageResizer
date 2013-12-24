//File: resizer.hh
//Date: Tue Dec 24 11:53:13 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include <functional>
#include "matrix.hh"
#include "filter.hh"
#include "image.hh"

typedef vector<int> Path;

class ImageResizer {
	public:
	const Img& orig_img;

	GreyImg greyimg;
	Matrix weight_mask;
	Img result;

	Matrix energy;

	vector<Path> removed_path;

	public:
		ImageResizer(const Img& _orig_img):
			orig_img(_orig_img), greyimg(_orig_img),
			weight_mask(_orig_img.w, _orig_img.h), result(_orig_img) {
			cal_all_energy();
		}

		~ImageResizer() { }

		void resize(int w, int h);

		void remove_column(int number);


	protected:
		// caller release memory
		void cal_all_energy();

		static Path get_path(const Matrix& e, int min_i);

		void remove_one_column();

		// remove path from orig_img, greyimg, weight_mask, update energy, record to removedPoint
		void remove_vert_path(const Path& p);

		void update_energy(const Path& p);

		inline real_t convolve(int i, int j) const {
			return Filter::prewitt_convolve(greyimg, i, j);
		}
};
