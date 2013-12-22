// File: filter.hh
// Date: Sun Dec 22 14:10:03 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once
#include <memory>
#include "image.hh"

class Filter {
	public:
		static std::shared_ptr<GreyImg> GreyScale(const std::shared_ptr<Img>);
		static real_t to_grey(const ::Color&);

		static real_t prewitt_convolve(const GreyImg& img, int, int);
};
