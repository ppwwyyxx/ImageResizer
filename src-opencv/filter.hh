//File: filter.hh
//Date: Sun Feb 01 22:33:28 2015 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "lib/debug.hh"

class ImageFilter {
	public:
		virtual cv::Mat run(cv::Mat m) = 0;
};

class SobelImageFilter : public ImageFilter {
	public:
		SobelImageFilter() {
			k1 = cv::Mat(3, 3, CV_32FC1, m1);
			k2 = cv::Mat(3, 3, CV_32FC1, m2);
		}

		cv::Mat run(cv::Mat m) {
			cv::Mat flt = m.clone();
			flt.convertTo(flt, CV_32FC3, 1.0 / 255.0);
			cv::Mat ret1, ret2;
			cv::filter2D(flt, ret1, -1, k1);
			cv::filter2D(flt, ret2, -1, k2);
			cv::Mat ret = abs(ret1) + abs(ret2);
			cv::cvtColor(ret, ret, CV_BGR2GRAY);
			return ret;
		}

		cv::Mat k1, k2;
		float m1[9] = {
				  -1.f, 0.f, 1.f,
				  -2.f, 0.f, 2.f,
				  -1.f, 0.f, 1.f},
			  m2[9] = {
				  -1.f, -2.f, -1.f,
				  0.f,0.f,0.f,
				  1.f, 2.f, 1.f};

};
