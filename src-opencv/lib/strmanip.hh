/*
 * $File: strmanip.hh
 * $Date: Fri Jan 16 12:32:45 2015 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <utility>

std::string ssprintf(const char *fmt, ...);

std::vector<std::string> strsplit(const std::string &str, const std::string &sep = "");
std::pair<std::string, std::string> strsplit_by_first(const std::string &str, const std::string &sep = "");

std::string strjoin(const std::vector<std::string> &strs, const std::string &sep = "");

inline static std::string strtrim_right(
		const std::string& s,
		const std::string& delimiters = " \f\n\r\t\v" )
{
	auto pos = s.find_last_not_of( delimiters );
	if (pos == std::string::npos)
		return s;
	return s.substr( 0, pos + 1 );
}

inline static std::string strtrim_left(
		const std::string& s,
		const std::string& delimiters = " \f\n\r\t\v" )
{
	auto pos = s.find_first_not_of( delimiters );
	if (pos == std::string::npos)
		return s;
	return s.substr(pos);
}

inline static std::string strtrim(
		const std::string& s,
		const std::string& delimiters = " \f\n\r\t\v" )
{
	return strtrim_left( strtrim_right( s, delimiters ), delimiters );
}

// return a current time like
std::string get_timestamp();

template <class T>
inline std::string to_string(const T& t) {
	std::stringstream ss;
	ss << t;
	return ss.str();
}


/*
 * vim: syntax=cpp11.doxygen foldmethod=marker foldmarker=f{{{,f}}}
 */

