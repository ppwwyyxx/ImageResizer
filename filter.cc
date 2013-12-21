// File: filter.cc
// Date: Sat Dec 21 17:29:53 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include "filter.hh"
#include "utils.hh"
#include "render/MImageRender.hh"
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
