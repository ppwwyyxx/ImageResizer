// File: main.cc
// Date: Sat Dec 28 17:45:32 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <iostream>
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

enum optionIndex { INPUT , OUTPUT, ENERGY, MASK, CONV, WIDTH, HEIGHT, UNKNOWN};
const option::Descriptor usage[] = {
	{INPUT, 0, "i", "input", Arg::NonEmpty, "-i	[Required] Input image."},
	{OUTPUT, 0, "o", "output", Arg::NonEmpty, "-o	[Required] Output image."},
	{WIDTH, 0, "w", "width", Arg::NonEmpty, "-w	Width, pixels in integer, or float between (0, 1]" },
	{HEIGHT, 0, "h", "height", Arg::NonEmpty, "-h	Height, pixels in integer, or float between (0, 1]" },
	{ENERGY, 0, "e", "energy", Arg::NonEmpty, "-e   	Output energy image."},
	{MASK, 0, "m", "mask", Arg::NonEmpty, "-m   	Maks image, red to discard, green to keep."},
	{CONV, 0, "c", "convolution", Arg::NonEmpty, "-c	Convolution type: prewitt, vsquare, sobel, laplacian"},
	{UNKNOWN, 0,"" ,  ""   ,option::Arg::None, "\nExamples:\n"
                                             "  example --unknown -- --this_is_no_option\n"
                                             "  example -unk --plus -ppp file1 file2\n" },
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

	CONV_T conv = CONV_T::PREWITT;
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

	resizer.resize(destw, desth);

	imgptr result = make_shared<Img>(resizer.result);
	FileRender rd2(result, outfile);
	rd2.finish();
}
