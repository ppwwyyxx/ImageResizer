/*
 * $File: debug.hh
 * $Date: Mon Dec 15 16:08:44 2014 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#pragma once

#include <cstdarg>
#include <map>
#include <string.h>
#include <libgen.h>
#include <iostream>

#include "print.hh"

#define P(a) std::cout << (a) << std::endl
#define PP(x) (std::cout << "[debug] " << #x << " " << (x) << std::endl)
#define PA(arr) \
	do { \
		std::cout << #arr << " size=" << arr.size() << ": "; \
		std::copy(begin(arr), end(arr), std::ostream_iterator<std::remove_reference<decltype(arr)>::type::value_type>(std::cout, " ")); \
		std::cout << std::endl;  \
	} while (0)

void error_exit(const char *msg) __attribute__((noreturn));

inline void error_exit(const char *msg) {
	c_fprintf(COLOR_RED, stderr, "error: %s\n", msg);
	abort();
}

#ifdef DEBUG


#define print_debug(fmt, ...) \
			__print_debug__(__FILE__, __func__, __LINE__, fmt, ## __VA_ARGS__)

#define m_assert(expr) \
	__m_assert_check__((expr), # expr, __FILE__, __PRETTY_FUNCTION__, __LINE__)

inline void __m_assert_check__(bool val, const char *expr,
		const char *file, const char *func, int line) {
	if (val) return;
	c_fprintf(COLOR_RED, stderr, "assertion \"%s\" failed, in %s, (%s:%d)\n",
			expr, func, file, line);
	abort();
}

void __print_debug__(
		const char *file,
		const char *func,
		int line,
		const char *fmt, ...) __attribute__((format(printf, 4, 5)));
inline void __print_debug__(
		const char *file,
		const char *func,
		int line,
		const char *fmt, ...) {
	static std::map<int, std::string> colormap;
	static int color = 0;
	if (! colormap[line].length()) {
		colormap[line] = TERM_COLOR(color);
		color = (color + 1) % 5;
	}

	char *fbase = basename(strdupa(file));
	c_fprintf(colormap[line].c_str(), stderr, "[%s@%s:%d] ", func, fbase, line);

	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
}

#else

#define print_debug(fmt, ...)

#define m_assert(expr)

#endif

/*
 * vim: syntax=cpp11.doxygen foldmethod=marker foldmarker=f{{{,f}}}
 */

