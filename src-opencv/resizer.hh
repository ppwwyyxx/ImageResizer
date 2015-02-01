//File: resizer.hh
//Date: Sun Feb 01 23:01:10 2015 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once
#include <opencv2/core/core.hpp>
#include <vector>
#include <string>
#include <memory>
#include "filter.hh"
#include "lib/param_def.hh"


DEF_PARAM_CLASS(ImageResizerParam,
	bool, video, false,
	float, width, 1.f,
	float, height, 1.f,
	// output directory for video frames
	std::string, output_dir, "/tmp",
	std::string, mask_output, "/tmp/mask.jpg"
);

class ImageResizer {
	public:
		typedef std::vector<int> Path;

		ImageResizer(ImageResizerParam param);

		cv::Mat resize(cv::Mat input);

		// red to delete, green to keep
		// will update weight matrix
		void set_mask(cv::Mat mask);

	protected:
		void prepare_weight(cv::Mat m);

		void remove_one_column(const Path& p);

		Path find_path() const;

		cv::Mat input;
		cv::Mat weight, mask;
		ImageResizerParam m_param;

		int diff;	// in width;

		std::unique_ptr<ImageFilter> filter;
};
