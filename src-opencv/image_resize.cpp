//File: image_resize.cpp
//Date: Sun Feb 01 23:01:37 2015 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <string>
#include <opencv2/highgui/highgui.hpp>
#include "lib/argument_def_plain.hh"
#include "lib/debug.hh"
#include "resizer.hh"

using namespace std;

DEF_ARGUMENT_CLASS(Argument,
	string, input, "", REQUIRED, OPT_SL(-i, --input),
	string, output, "", REQUIRED, OPT_SL(-o, --output),
	float, width, 1.f, OPTIONAL, OPT_SL(-w, --width),
	float, height, 1.f, OPTIONAL, OPT_SL(-h, --height),
	string, video, "", OPTIONAL, OPT_SL(-v, --video),
	string, mask, "", OPTIONAL, OPT_SL(-m, --mask)
);

int main(int argc, char* argv[]) {
	Argument args;
	if (!args.parse_args(argc, argv)) return 1;

	cv::Mat input = cv::imread(args.input);
	print_debug("Input image: %dx%d\n", input.cols, input.rows);
	ImageResizer resizer(ImageResizerParam()
			.width(args.width)
			.height(args.height)
			.video(args.video.length() > 0)
			.output_dir(args.video));
	if (args.mask.length())
		resizer.set_mask(cv::imread(args.mask));
	auto output = resizer.resize(input);
	cv::imwrite(args.output, output);
}
