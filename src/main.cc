// File: main.cc
// Date: Wed Jan 01 14:24:10 2014 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <iostream>
#include <fstream>
#include "render/filerender.hh"
#include "planedrawer.hh"
#include "resizer.hh"
#include "optionparser.h"
#include <ctime>
#include <cassert>

struct Arg: public option::Arg {
  static void printError(const char* msg1, const option::Option& opt, const char* msg2) {
    fprintf(stderr, "%s", msg1);
    fwrite(opt.name, opt.namelen, 1, stderr);
    fprintf(stderr, "%s", msg2);
  }

  static option::ArgStatus NonEmpty(const option::Option& option, bool msg) {
    if (option.arg != 0 && option.arg[0] != 0)
      return option::ARG_OK;
    if (msg) printError("Option '", option, "' requires a non-empty argument\n");
    return option::ARG_ILLEGAL;
  }
};

enum optionIndex { INPUT , OUTPUT, ENERGY, MASK, CONV, WIDTH, HEIGHT, OPTIMIZED, FEATURE, VIDEO, UNKNOWN};
const option::Descriptor usage[] = {
	{INPUT, 0, "i", "input", Arg::NonEmpty, "-i	[Required] Input image."},
	{OUTPUT, 0, "o", "output", Arg::NonEmpty, "-o	[Required] Output image."},
	{WIDTH, 0, "w", "width", Arg::NonEmpty, "-w	Width, can be pixel number in integer, or a relative number in (0, 1]" },
	{HEIGHT, 0, "h", "height", Arg::NonEmpty, "-h	Height, same as above" },
	{ENERGY, 0, "e", "energy", Arg::NonEmpty, "-e   	Output energy image."},
	{MASK, 0, "m", "mask", Arg::NonEmpty, "-m   	Maks image, red to discard, green to keep."},
	{CONV, 0, "c", "convolution", Arg::NonEmpty, "-c	Convolution type. can be one of prewitt, vsquare, sobel, laplacian"},
	{OPTIMIZED, 0, "p", "optimized", Arg::None, "-p   	Use Optimized Seam Carving(slow)."},
	{FEATURE, 0, "f", "feature", Arg::NonEmpty, "-f   	Use feature as mask. every line is \"r c\" "},
	{VIDEO, 0, "v", "video", Arg::None, "-v   	Output images with carved path for video generation."},
	{UNKNOWN, 0,"" ,  ""   ,option::Arg::None, "\nExamples:\n"
                                             "  ./image_resize -i in.png -o out.png -w 0.9 -e energy.png\n"
                                             "  ./image_resize -i in.png -o out.png -w 300 -h 200\n" },
	{0, 0, 0, 0, 0, 0}
};

using namespace std;
using namespace Magick;

void printHelp() {
	int columns = getenv("COLUMNS")? atoi(getenv("COLUMNS")) : 80;
	option::printUsage(fwrite, stdout, usage, columns);
	exit(1);
}

void check_option(const option::Option options[]) {
	if (!options[INPUT] || !options[OUTPUT])
		printHelp();
}


int main(int argc, char* argv[]) {
	argc-=(argc>0); argv+=(argc>0); // skip program name argv[0] if present
	option::Stats  stats(usage, argc, argv);
	option::Option options[stats.options_max], buffer[stats.buffer_max];
	option::Parser parse(usage, argc, argv, options, buffer);
	if (parse.error()) return 1;
	check_option(options);

	string infile = options[INPUT].arg,
		   outfile = options[OUTPUT].arg;

	CONV_T conv = CONV_T::SOBEL;
	if (options[CONV].arg) {
		string opt = options[CONV].arg;
		if (opt == "prewitt") conv = CONV_T::PREWITT;
		else if (opt == "vsquare") conv = CONV_T::V_SQURARE;
		else if (opt == "sobel") conv = CONV_T::SOBEL;
		else if (opt == "laplacian") conv = CONV_T::LAPLACIAN;
	}

	Img input(infile);
	ImageResizer resizer(input, conv);

	if (options[ENERGY].arg) {
		string out_energy_file = options[ENERGY].arg;
		imgptr energyimg = make_shared<Img>(GreyImg(resizer.energy));
		FileRender(energyimg, out_energy_file).finish();
	}
	if (options[MASK].arg) {
		Img mask(options[MASK].arg);
		resizer.update_mask(mask);
	}
	if (options[FEATURE].arg) {
		string ffile_name = options[FEATURE].arg;
		PP(ffile_name);
		Matrix mask(input.w, input.h);
		ifstream ffile;
		ffile.open(ffile_name);
		int r, c;
		while (ffile >> r >> c) {
			mask.get(c, r) = 2;
		}
		ffile.close();
		resizer.weight_mask = ImageResizer::blurMatrix(mask);

		string out_energy_file = "out-mask.png";
		imgptr energyimg = make_shared<Img>(GreyImg(resizer.weight_mask));
		FileRender(energyimg, out_energy_file).finish();
	}

	int destw = 0, desth = 0;
	try {
		if (options[WIDTH].arg) {
			double v = stod(options[WIDTH].arg), intpart;
			if (v <= 0) throw(v);
			if (0 < v && v <= 1) destw = input.w * v;
			else if (modf(v, &intpart) != 0.0 || !(destw = intpart)) printHelp();
		}
		if (options[HEIGHT].arg) {
			double v = stod(options[HEIGHT].arg), intpart;
			if (v <= 0) throw(v);
			if (0 < v && v <= 1) desth = input.h * v;
			else if (modf(v, &intpart) != 0.0 || !(desth = intpart)) printHelp();
		}
	} catch (...) { printHelp(); }
	if (! destw && ! desth) printHelp();
	if (!destw) destw = input.w;
	if (!desth) desth = input.h;
	PP(destw);
	PP(desth);

	if (options[OPTIMIZED])
		resizer.optimized = true;
	if (options[VIDEO])
		resizer.video = true;

	resizer.resize(destw, desth);

	resizer.result.save(outfile);
}
