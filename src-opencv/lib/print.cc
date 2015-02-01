/*
 * $File: print.cc
 * $Date: Sat Jan 31 22:16:35 2015 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <sstream>
#include <cstdarg>
#include "print.hh"
#include "utils.hh"

std::string TERM_COLOR(int k) {
	// k = 0 ~ 4
	std::ostringstream ss;
	ss << "\x1b[3" << k + 2 << "m";
	return ss.str();
}

void c_printf(const char* col, const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	printf("%s", col);
	vprintf(fmt, ap);
	printf(COLOR_RESET);
	va_end(ap);
}

void c_fprintf(const char* col, FILE* fp, const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	fprintf(fp, "%s", col);
	vfprintf(fp, fmt, ap);
	fprintf(fp, COLOR_RESET);
	va_end(ap);
}
