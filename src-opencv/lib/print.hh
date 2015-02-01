/*
 * $File: print.hh
 * $Date: Thu Dec 04 16:03:46 2014 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#pragma once


#include <vector>
#include <string>

std::string TERM_COLOR(int k);

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"


void print_table(const std::vector<std::vector<std::string>> &data);

void c_printf(const char* col, const char* fmt, ...);

void c_fprintf(const char* col, FILE* fp, const char* fmt, ...);

inline void print_progress(int percent) {
	printf("progress: %d %%\r", percent);
	fflush(stdout);
}
/*
 * vim: syntax=cpp11.doxygen foldmethod=marker foldmarker=f{{{,f}}}
 */

