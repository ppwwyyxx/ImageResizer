//File: imgDist.hh
//Date: Sun Dec 29 01:30:16 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include "image.hh"

class ImageDist {
	public:
		Img orig;
		vector<Img> results;

		ImageDist(const Img& m_orig, int number) :
			orig(m_orig) {
				results.reserve(number);
		}


};
