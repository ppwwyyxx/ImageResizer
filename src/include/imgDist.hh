//File: imgDist.hh
//Date: Sun Dec 29 16:20:01 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include "image.hh"

typedef pair<int, int> Patch;
class ImageDist {

	public:
		Img orig;
		vector<Img> results;

		int PATCH_SIZE, PATCH_SHIFT;

		ImageDist(const Img& m_orig, int number) :
			orig(m_orig) {
				results.reserve(number);
				PATCH_SIZE = orig.w / 30;
				PATCH_SHIFT = PATCH_SIZE / 2;
		}

		void calculate();

		real_t cal_IMED(const Img& img1, Patch p1, const Img& img2, Patch p2, real_t thres) const;

};

class ImageDistCalculator {
	const Img& img1, &img2;
	const ImageDist* self;
	public:
		ImageDistCalculator(ImageDist* _self, const Img& _img1, const Img& _img2):
			self(_self), img1(_img1), img2(_img2) {}

		real_t calculate();

		vector<Patch> get_patches(const Img& img) const;

		real_t cal_dIE(const vector<Patch>& p1, const vector<Patch>& p2) const;

};
