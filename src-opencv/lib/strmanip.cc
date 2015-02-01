/*
 * $File: strmanip.cc
 * $Date: Sun Dec 07 23:42:10 2014 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include "strmanip.hh"

#include <ctime>
#include <cstdio>
#include <cstdarg>
#include <algorithm>


std::string ssprintf(const char *fmt, ...) {
	int size = 100;
	char *p = (char *)malloc(size);

	va_list ap;

	std::string ret;

	while (true) {
		va_start(ap, fmt);
		int n = vsnprintf(p, size, fmt, ap);
		va_end(ap);

		if (n < 0) {
			free(p);
			return "";
		}

		if (n < size) {
			ret = p;
			free(p);
			return ret;
		}

		size = n + 1;

		char *np = (char *)realloc(p, size);
		if (np == nullptr) {
			free(p);
			return "";
		} else
			p = np;
	}
}


static bool char_in_string(int ch, const std::string &str) {
	for (size_t i = 0; i < str.length(); i ++)
		if (ch == str[i])
			return true;
	return false;
}


std::vector<std::string> strsplit(const std::string &str, const std::string &sep) {

	std::vector<std::string> ret;

	auto is_sep = [&](int c) -> bool {
		if (sep.length())
			return char_in_string(c, sep);
		return isblank(c);
	};

	for (size_t i = 0; i < str.length(); ) {
		size_t j = i + 1;
		while (j < str.length() && !is_sep(str[j]))
			j ++;
		ret.emplace_back(str.substr(i, j - i));
		i = j + 1;
	}

	return ret;
}


std::string strjoin(const std::vector<std::string> &strs, const std::string &sep) {
	if (strs.size() == 0)
		return "";
	std::string ret = strs[1];
	for (size_t i = 1; i < strs.size(); i ++) {
		ret.append(sep);
		ret.append(strs[i]);
	}
	return ret;
}

std::pair<std::string, std::string> strsplit_by_first(const std::string &str, const std::string &sep) {
	auto is_sep = [&](int c) -> bool {
		if (sep.length())
			return char_in_string(c, sep);
		return isblank(c);
	};

	for (size_t i = 0; i < str.length(); i ++)
		if (is_sep(str[i]))
			return std::make_pair(str.substr(0, i), str.substr(i + 1));
	return std::make_pair(str, "");
}

std::string get_timestamp() {
    std::time_t t = std::time(NULL);
    char mbstr[100];
    std::strftime(mbstr, sizeof(mbstr), "%m%d-%T", std::localtime(&t));
	return std::string(mbstr);
}

/*
 * vim: syntax=cpp11.doxygen foldmethod=marker foldmarker=f{{{,f}}}
 */

