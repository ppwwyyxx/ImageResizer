//File: resizer.cc
//Date: Sun Feb 01 23:06:53 2015 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include "resizer.hh"

#include "lib/utils.hh"
#include "lib/debug.hh"
#include "lib/strmanip.hh"
#include <opencv2/highgui/highgui.hpp>

using namespace std;

namespace {
cv::Mat acc_matrix(cv::Mat m) {
	m_assert(m.rows && m.cols);
	m_assert(m.type() == CV_32FC1);
	cv::Mat acc_weight = cv::Mat::zeros(m.rows,
			m.cols, CV_32FC1);
	REP(j, m.cols)
		acc_weight.at<float>(0, j) = m.at<float>(0, j);
	REPL(i, 1, m.rows) {
		acc_weight.at<float>(i, 0) = min(acc_weight.at<float>(i - 1, 0),
				acc_weight.at<float>(i - 1, 1)) + m.at<float>(i, 0);
		acc_weight.at<float>(i, m.cols - 1) = min(acc_weight.at<float>(i - 1, m.cols - 1),
				acc_weight.at<float>(i - 1, m.cols - 2)) + m.at<float>(i, m.cols - 1);
		REPL(j, 1, m.cols - 1) {
			acc_weight.at<float>(i, j) = min(acc_weight.at<float>(i - 1, j - 1),
					min(acc_weight.at<float>(i - 1, j),
					acc_weight.at<float>(i - 1, j + 1))) + m.at<float>(i, j);
		}
	}
	return acc_weight;
}

ImageResizer::Path backprop(cv::Mat e, int idx) {
	ImageResizer::Path ret(e.rows);
	ret[e.rows - 1] = idx;
	int nowx = idx;
	for (int i = e.rows - 2; i >= 0; i --) {
		float min = e.at<float>(i, nowx);
		int minx = nowx;
		if (nowx != 0)
			if (update_min(min, e.at<float>(i, nowx - 1)))
				minx = nowx - 1;
		if (nowx != e.cols - 1)
			if (update_min(min, e.at<float>(i, nowx + 1)))
				minx = nowx + 1;
		ret[i] = minx;
		nowx = minx;
	}
	return ret;
}

}

ImageResizer::ImageResizer(ImageResizerParam param):
	m_param(param) {
	m_assert((m_param.width() == 1.f) xor
			(m_param.height() == 1.f));
	filter.reset(new SobelImageFilter());
}

void ImageResizer::prepare_weight(cv::Mat input) {
	m_assert(input.type() == CV_8UC3);
	weight = filter->run(input);
	m_assert(weight.type() == CV_32FC1);

	m_assert(mask.rows == weight.rows && mask.cols == weight.cols);
	REP(i, mask.rows) REP(j, mask.cols) {
		cv::Vec3b c = mask.at<cv::Vec3b>(i, j);
		if (c[1] > 100) weight.at<float>(i, j) += 1e2;
		if (c[2] > 100) weight.at<float>(i, j) -= 1e2;
		m_assert(c[1] < 100 || c[2] < 100);
	}
}

cv::Mat ImageResizer::resize(cv::Mat input) {
	m_assert(input.type() == CV_8UC3);
	if (m_param.height() == 1.f) {
		this->input = input;
		int target_w = input.cols * m_param.width();
		diff = target_w - input.cols;
	} else {
		cv::transpose(input, this->input);
		int target_h = input.rows * m_param.height();
		diff = target_h - input.rows;
	}
	int cnt = abs(diff);
	if (m_param.mask_output().length()) {
		prepare_weight(input);
		cv::imwrite(m_param.mask_output().c_str(), weight * 50);
	}
	while (cnt--) {
		prepare_weight(this->input);
		auto p = find_path();
		if (m_param.video()) {
			cv::Mat viz = this->input.clone();
			REP(i, viz.rows)
				viz.at<cv::Vec3b>(i, p[i]) = cv::Vec3b(0,0,0);
			string output = ssprintf(
					"%s/%03d.jpg",
					m_param.output_dir().c_str(),
					cnt);
			cv::imwrite(output, viz);
		}
		remove_one_column(p);
	}
	if (m_param.height() != 1.f)
		cv::transpose(this->input, this->input);
	return this->input;
}

ImageResizer::Path ImageResizer::find_path() const {
	cv::Mat acc = acc_matrix(weight);
	float min_e = numeric_limits<float>::max();
	int min_i = 0;
	// find minimum
	REP(j, weight.cols)
		if (update_min(min_e, acc.at<float>(weight.rows - 1, j)))
			min_i = j;
	// find path from the minimum
	auto path = backprop(acc, min_i);
	return path;
}

void ImageResizer::remove_one_column(const Path& p) {
	cv::Mat ret = cv::Mat::zeros(input.rows, input.cols - 1, CV_8UC3);
	cv::Mat new_mask = cv::Mat::zeros(input.rows, input.cols - 1, CV_8UC3);
	REP(i, input.rows) {
		REP(j, p[i]) {
			ret.at<cv::Vec3b>(i, j) = input.at<cv::Vec3b>(i, j);
			new_mask.at<cv::Vec3b>(i, j) = mask.at<cv::Vec3b>(i, j);
		}
		REPL(j, p[i] + 1, input.cols) {
			ret.at<cv::Vec3b>(i, j - 1) = input.at<cv::Vec3b>(i, j);
			new_mask.at<cv::Vec3b>(i, j - 1) = mask.at<cv::Vec3b>(i, j);
		}
	}
	input = ret;
	mask = new_mask;
}

void ImageResizer::set_mask(cv::Mat mask) {
	m_assert(mask.type() == CV_8UC3);
	this->mask = mask;
}
