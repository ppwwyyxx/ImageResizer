//File: gen_mask.cpp
//Date: Sun Feb 01 22:57:07 2015 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <opencv2/highgui/highgui.hpp>

#include "lib/argument_def_plain.hh"
#include "lib/debug.hh"

using namespace std;
using namespace cv;

DEF_ARGUMENT_CLASS(Argument,
	string, input, "", REQUIRED, OPT_SL(-i, --input),
	string, output, "", REQUIRED, OPT_SL(-o, --output)
);

int brush_size = 10;	// init brush size
string window_name = "paint";
cv::Mat img_show, img_save;
bool mode_delete = true;		// keep or delete

void callback(int event, int x, int y, int, void*) {
	cv::Scalar c = mode_delete ? cv::Scalar(0, 0, 255) : cv::Scalar(0, 255, 0);
	if  (event == EVENT_LBUTTONDOWN) {
		cv::circle(img_show, cv::Point(x, y), brush_size / 2, c, -1);
		cv::circle(img_save, cv::Point(x, y), brush_size / 2, c, -1);
		imshow(window_name, img_show);
	} else if (event == EVENT_MOUSEMOVE) {
		Mat copy = img_show.clone();
		cv::circle(copy, cv::Point(x, y), brush_size / 2, c, -1);
		imshow(window_name, copy);
	}
}

int main(int argc, char** argv) {
	Argument args;
	if (!args.parse_args(argc, argv)) return 1;
	img_show = imread(args.input);
	if (img_show.empty()) {
		cout << "Error loading the image" << endl;
		return -1;
	}
	img_save = cv::Mat::zeros(img_show.rows, img_show.cols, CV_8UC3);

	namedWindow(window_name, 1);
	setMouseCallback(window_name, callback, NULL);
	imshow(window_name, img_show);

	// Wait until user press some key
	while (true) {
		bool q = false;
		int k = waitKey(0);
		switch (k) {
			case 61:	// =
				brush_size += 2;
				break;
			case 45:	// -
				brush_size -= 2;
				break;
			case 113:	// q
			case 27:	// esc
				q = true;
				break;
			case 32:	// space
				mode_delete = !mode_delete;
				break;
		}
		if (q) break;
	}
	imwrite(args.output.c_str(), img_save);
	return 0;
}
