/*
 * $File: utils.hh
 * $Date: Sat Jan 31 22:16:13 2015 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#pragma once

#include <ctime>
#include <chrono>
#include <iostream>
#include <iterator>
#include <limits>
#include <sys/stat.h>

#include "debug.hh"

#define REP(x, y) for (auto x = decltype(y){0}; x < (y); x ++)
#define REPL(x, y, z) for (auto x = decltype(z){y}; x < (z); x ++)
#define REPD(x, y, z) for (auto x = decltype(z){y}; x >= (z); x --)

template <class T>
inline T sqr(T a) { return a * a; }

template <typename T>
inline void free_2d(T** ptr, int w) {
	if (ptr != nullptr)
		for (int i = 0; i < w; i ++)
			delete[] ptr[i];
	delete[] ptr;
}


template<class Container>
typename Container::value_type max(const Container &data) {
	typedef typename Container::value_type value_type;
	if (data.size() == 0)
		return value_type();

	auto it = data.begin();
	value_type ret = *it;
	it ++;
	for (; it != data.end(); it ++)
		ret = std::max(ret, *it);

	return ret;
}


template<class Container>
auto min(const Container &data) -> decltype(*data.begin()) {
	typedef decltype(*data.begin()) value_type;
	if (data.size() == 0)
		return value_type();

	auto it = data.begin();
	value_type ret = *it;
	it ++;
	for (; it != data.end(); it ++)
		ret = std::min(ret, *it);

	return ret;
}

template <typename T>
T max_value_of(const T &) {
	return std::numeric_limits<T>::max();
}

template<typename T>
bool update_min(T &dest, const T &val) {
	if (val < dest) { dest = val; return true; }
	return false;
}

template<typename T>
bool update_max(T &dest, const T &val) {
	if (dest < val) { dest = val; return true; }
	return false;
}


template <typename T>
std::pair<double, double> valid_interval(const std::vector<T>& v, float dist=2) {
	double mean = 0;
	for (auto k : v) mean += k;
	mean /= v.size();
	double std = 0;
	for (auto k : v) std += sqr(k - mean);
	std = sqrt(std / v.size());
	return std::make_pair(mean - dist * std, mean + dist * std);
}

template <typename T>
std::vector<T> filter_by_valid_interval(const std::vector<T>& v, float dist=3) {
	auto interval = valid_interval(v, dist);
	std::vector<T> ret;
	for (auto k : v)
		if (k > interval.first && k < interval.second)
			ret.push_back(k);
	return ret;
}

inline bool exists_file (const std::string& name) {
  struct stat buffer;
  bool ret = stat (name.c_str(), &buffer) == 0;
	if (!ret)
		error_exit((name + " not found.").c_str());
	return ret;
}


/*
 * vim: syntax=cpp11.doxygen foldmethod=marker foldmarker=f{{{,f}}}
 */

