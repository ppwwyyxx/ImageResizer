// File: filter.cc
// Date: Sun Dec 22 14:13:13 2013 +0800
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

	auto ret = abs(get(i + 1, j + 1) + get(i + 1, j) + get(i + 1, j - 1)
					- get(i - 1, j - 1) - get(i - 1, j) - get(i - 1, j + 1))
				+ abs(get(i + 1, j + 1) + get(i, j + 1) + get(i - 1, j + 1)
					- get(i + 1, j - 1) - get(i, j - 1) - get(i - 1, j - 1));
	return ret;
}
