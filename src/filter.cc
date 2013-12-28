// File: filter.cc
// Date: Sat Dec 28 17:35:09 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <functional>
#include "filter.hh"
#include "utils.hh"
#include "render/MImageRender.hh"
using namespace std::placeholders;
using namespace Magick;
using namespace std;


shared_ptr<GreyImg> Filter::GreyScale(const shared_ptr<Img> img) {
	shared_ptr<GreyImg> ret = make_shared<GreyImg>(*img);
	return move(ret);
}

real_t Filter::to_grey(const ::Color& c) {
	/*
	 *real_t ret = 0.299 * c.x + 0.587 * c.y + 0.114 * c.z;
	 */
	real_t ret = (c.x + c.y + c.z) / 3;
	return ret;
}

real_t Filter::prewitt_convolve(const GreyImg& img, int i, int j) {
	bool inside = (between(i, 1, img.h - 1) && between(j, 1, img.w - 1));
	auto get = bind(inside ? &GreyImg::get_pixel : &GreyImg::get_pixel_safe, &img, _1, _2);

	auto ret = fabs(get(i + 1, j + 1) + get(i + 1, j) + get(i + 1, j - 1)
					- get(i - 1, j - 1) - get(i - 1, j) - get(i - 1, j + 1))
				+ fabs(get(i + 1, j + 1) + get(i, j + 1) + get(i - 1, j + 1)
					- get(i + 1, j - 1) - get(i, j - 1) - get(i - 1, j - 1));
	return ret;
}

real_t Filter::prewitt_convolve(const Img& img, int i, int j) {
	bool inside = (between(i, 1, img.h - 1) && between(j, 1, img.w - 1));
	auto get = [&](int i, int j) {
		return inside ? img.get_pixel(i, j) : img.get_pixel_safe(i, j);
	};

	auto ret = (get(i + 1, j + 1) + get(i + 1, j) + get(i + 1, j - 1)
					- get(i - 1, j - 1) - get(i - 1, j) - get(i - 1, j + 1)).abs()
				+ (get(i + 1, j + 1) + get(i, j + 1) + get(i - 1, j + 1)
					- get(i + 1, j - 1) - get(i, j - 1) - get(i - 1, j - 1)).abs();
	return ret.sqr();
	return ret.x + ret.y + ret.z;
}

real_t Filter::vsquare_convolve(const GreyImg& img, int i, int j) {
	bool inside = (between(i, 1, img.h - 1) && between(j, 1, img.w - 1));
	auto get = bind(inside ? &GreyImg::get_pixel : &GreyImg::get_pixel_safe, &img, _1, _2);
	auto ret = sqr(get(i + 1, j + 1) + get(i + 1, j) + get(i + 1, j - 1)
					- get(i - 1, j - 1) - get(i - 1, j) - get(i - 1, j + 1));
	/*
	 *auto ret = sqr(get(i - 1, j + 1) + get(i, j + 1) + get(i + 1, j + 1)
	 *                - get(i - 1, j - 1) - get(i, j - 1) - get(i + 1, j - 1));
	 */
	return ret;
}

real_t Filter::sobel_convolve(const GreyImg& img, int i, int j) {
	bool inside = (between(i, 1, img.h - 1) && between(j, 1, img.w - 1));
	auto get = bind(inside ? &GreyImg::get_pixel : &GreyImg::get_pixel_safe, &img, _1, _2);
	auto ret = fabs(get(i + 1, j + 1) + 2 * get(i + 1, j) + get(i + 1, j - 1)
					- get(i - 1, j - 1) - 2 * get(i - 1, j) - get(i - 1, j + 1))
				+ fabs(get(i + 1, j + 1) + 2 * get(i, j + 1) + get(i - 1, j + 1)
					- get(i + 1, j - 1) - 2 * get(i, j - 1) - get(i - 1, j - 1));
	return ret;
}

real_t Filter::laplacian_convolve(const GreyImg& img, int i, int j) {
	bool inside = (between(i, 1, img.h - 1) && between(j, 1, img.w - 1));
	auto get = bind(inside ? &GreyImg::get_pixel : &GreyImg::get_pixel_safe, &img, _1, _2);
	auto ret = fabs(get(i + 1, j) + get(i - 1, j) + get(i, j - 1) + get(i, j + 1)
			- 4 * get(i, j));
	return ret;
}


class GaussKernel {
const double GAUSS_WINDOW_FACTOR = 6;
	public:
		real_t ** kernel;
		real_t kernel_tot;
		real_t normalization_factor;
		int kw;

		GaussKernel() {

			real_t sigma = 2;
			kw = ceil(0.3 * (sigma / 2 - 1) + 0.8) * GAUSS_WINDOW_FACTOR;
			// TODO decide window size ?

			const int center = kw / 2;
			normalization_factor = 2 * M_PI * sqr(sigma);
			kernel_tot = 0;

			kernel = new real_t*[kw];
			REP(i, kw) {
				kernel[i] = new real_t[kw];
				REP(j, kw) {
					real_t x = i - center,
						   y = j - center;
					kernel[i][j] = exp(-(sqr(x) + sqr(y)) / (2 * sqr(sigma)));
					kernel[i][j] /= normalization_factor;
					kernel_tot += kernel[i][j];
				}
			}
		}

		~GaussKernel()
		{ free_2d<real_t>(kernel, kw);}
};


GreyImg Filter::GaussianBlur(const GreyImg& img) {
	// TODO decide window size ?
	//
	static GaussKernel gauss;

	const int w = img.w, h = img.h;
	GreyImg ret(w, h);

	const int kw = gauss.kw;
	const int center = kw / 2;
	real_t ** kernel = gauss.kernel;


	REP(i, h) REP(j, w) {
		int x_bound = min(kw, h + center - i),
			y_bound = min(kw, w + center - j);
		real_t kernel_tot = 0;
		if (j >= center && x_bound == kw && i >= center && y_bound == kw)
			kernel_tot = gauss.kernel_tot;
		else {
			for (int x = max(center - i, 0); x < x_bound; x ++)
				for (int y = max(center - j, 0); y < y_bound; y ++)
					kernel_tot += kernel[x][y];
		}

		real_t compensation = 1.0 / kernel_tot;
		real_t newvalue = 0;
		for (int x = max(0, center - i); x < x_bound; x ++)
			for (int y = max(0, center - j); y < y_bound; y ++) {
				int dj = y - center + j,
					di = x - center + i;
				real_t curr = img.get_pixel(di, dj);
				newvalue += curr * kernel[x][y] * compensation;
			}
		ret.get_pixel(i, j) = newvalue;
	}
	return move(ret);
}
