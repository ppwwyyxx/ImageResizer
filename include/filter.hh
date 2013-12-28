// File: filter.hh
// Date: Sat Dec 28 17:27:15 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once
#include <memory>
#include "image.hh"

class Filter {
	public:
		static std::shared_ptr<GreyImg> GreyScale(const std::shared_ptr<Img>);
		static real_t to_grey(const ::Color&);

		static real_t prewitt_convolve(const GreyImg& img, int, int);
		static real_t prewitt_convolve(const Img& img, int, int);
		static real_t vsquare_convolve(const GreyImg& img, int, int);
		static real_t sobel_convolve(const GreyImg& img, int, int);
		static real_t laplacian_convolve(const GreyImg& img, int, int);

		static GreyImg GaussianBlur(const GreyImg& img);
};
