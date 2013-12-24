//File: resizer.hh
//Date: Tue Dec 24 23:41:18 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include <functional>
#include "matrix.hh"
#include "filter.hh"
#include "image.hh"

enum class CONV_T {
	PREWITT, V_SQURARE, SOBEL, LAPLACIAN
};

typedef vector<int> Path;

class ImageResizer {
	public:
	const Img& orig_img;

	GreyImg greyimg;
	Matrix weight_mask;
	Img result;

	Matrix energy;

	CONV_T conv_t = CONV_T::PREWITT;

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

		void set_conv(CONV_T c) { conv_t = c; }

	protected:
		// caller release memory
		void cal_all_energy();

		static Path get_path(const Matrix& e, int min_i);

		void remove_one_column();

		// remove path from orig_img, greyimg, weight_mask, update energy, record to removedPoint
		void remove_vert_path(const Path& p);

		void update_energy(const Path& p);

		inline real_t convolve(int i, int j) const {
			switch (conv_t) {
				case CONV_T::PREWITT:
					return Filter::prewitt_convolve(greyimg, i, j);
				case CONV_T::V_SQURARE:
					return Filter::vsquare_convolve(greyimg, i, j);
				case CONV_T::SOBEL:
					return Filter::sobel_convolve(greyimg, i, j);
				case CONV_T::LAPLACIAN:
					return Filter::laplacian_convolve(greyimg, i, j);
				default:
					m_assert(false);
			}
		}
};
