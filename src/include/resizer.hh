//File: resizer.hh
//Date: Sun Dec 29 19:35:07 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include <functional>
#include "matrix.hh"
#include "filter.hh"
#include "image.hh"

const double MASK_COLOR_THRES = 50.0 / 255;
const double MASK_WEIGHT = 20;

enum class CONV_T {
	PREWITT, V_SQURARE, SOBEL, LAPLACIAN
};

typedef vector<int> Path;

class ImageResizer {
	public:
	static Matrix blurMatrix(const Matrix& m);

	const Img& orig_img;

	bool optimized = false;
	bool video = false;

	GreyImg greyimg;
	Matrix weight_mask;
	Img result;

	Matrix energy;

	CONV_T conv_t = CONV_T::PREWITT;

	public:
		ImageResizer(const Img& _orig_img, CONV_T m_conv_t):
			orig_img(_orig_img), greyimg(_orig_img),
			weight_mask(_orig_img.w, _orig_img.h), result(_orig_img), conv_t(m_conv_t) {
			cal_all_energy();
		}

		~ImageResizer() { }

		void resize(int w, int h);

		void remove_column(int number);

		void remove_row(int number);

		void set_conv(CONV_T c) { conv_t = c; }

		void update_mask(const Img& mask_img);

	protected:

		template <typename T>
		static T img_transpose(const T& img) {
			T ret(img.h, img.w);
			REP(i, img.h) REP(j, img.w)
				ret.get_pixel(j, i) = img.get_pixel(i, j);
			return ret;
		}

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
					return Filter::prewitt_convolve(result, i, j);
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
