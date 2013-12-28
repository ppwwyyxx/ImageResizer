// File: main.cc
// Date: Sat Dec 28 12:41:07 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <iostream>
#include "render/filerender.hh"
#include "planedrawer.hh"
#include "resizer.hh"
#include "optionparser.h"
#include <ctime>
#include <cassert>

struct Arg: public option::Arg
{
  static void printError(const char* msg1, const option::Option& opt, const char* msg2)
  {
    fprintf(stderr, "%s", msg1);
    fwrite(opt.name, opt.namelen, 1, stderr);
    fprintf(stderr, "%s", msg2);
  }

  static option::ArgStatus Unknown(const option::Option& option, bool msg)
  {
    if (msg) printError("Unknown option '", option, "'\n");
    return option::ARG_ILLEGAL;
  }

  static option::ArgStatus Required(const option::Option& option, bool msg)
  {
    if (option.arg != 0)
      return option::ARG_OK;

    if (msg) printError("Option '", option, "' requires an argument\n");
    return option::ARG_ILLEGAL;
  }

  static option::ArgStatus NonEmpty(const option::Option& option, bool msg)
  {
    if (option.arg != 0 && option.arg[0] != 0)
      return option::ARG_OK;

    if (msg) printError("Option '", option, "' requires a non-empty argument\n");
    return option::ARG_ILLEGAL;
  }

  static option::ArgStatus Numeric(const option::Option& option, bool msg)
  {
    char* endptr = 0;
    if (option.arg != 0 && strtol(option.arg, &endptr, 10)){};
    if (endptr != option.arg && *endptr == 0)
      return option::ARG_OK;

    if (msg) printError("Option '", option, "' requires a numeric argument\n");
    return option::ARG_ILLEGAL;
  }
};

enum optionIndex { HELP, INPUT , OUTPUT, ENERGY, CONV, UNKNOWN};
const option::Descriptor usage[] = {
	{HELP, 0, "h", "help", Arg::None, "-h	Print this help."	},
	{INPUT, 0, "i", "input", Arg::NonEmpty, "-i	Input image."},
	{OUTPUT, 0, "o", "output", Arg::NonEmpty, "-o	Output image."},
	{ENERGY, 0, "e", "energy", Arg::NonEmpty, "-e   	Output energy image."},
	{CONV, 0, "c", "convolution", Arg::NonEmpty, "-c	Convolution type: prewitt, vsquare, sobel, laplacian"},
	{UNKNOWN, 0,"" ,  ""   ,option::Arg::None, "\nExamples:\n"
                                             "  example --unknown -- --this_is_no_option\n"
                                             "  example -unk --plus -ppp file1 file2\n" },
	{0, 0, 0, 0, 0, 0}
};

using namespace std;
using namespace Magick;

bool TEMPDEBUG = false;

void check_option(const option::Option options[]) {
	auto printHelp = [&]() {
		int columns = getenv("COLUMNS")? atoi(getenv("COLUMNS")) : 80;
		option::printUsage(fwrite, stdout, usage, columns);
		exit(1);
	};
	if (options[HELP])
		printHelp();
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
		PP(opt);
		if (opt == "prewitt")
			conv = CONV_T::PREWITT;
		else if (opt == "vsquare")
			conv = CONV_T::V_SQURARE;
		else if (opt == "sobel")
			conv = CONV_T::SOBEL;
		else if (opt == "laplacian")
			conv = CONV_T::LAPLACIAN;
	}

	Img input(infile);
	ImageResizer resizer(input, conv);

	if (options[ENERGY].arg) {
		string out_energy_file = options[ENERGY].arg;
		PP(out_energy_file);

		GreyImg energy(resizer.energy);
		imgptr energyimg = make_shared<Img>(energy);
		FileRender render(energyimg, out_energy_file);
		render.finish();
	}

	resizer.resize(500, 525);

	imgptr result = make_shared<Img>(resizer.result);
	FileRender rd2(result, outfile);
	rd2.finish();
}
