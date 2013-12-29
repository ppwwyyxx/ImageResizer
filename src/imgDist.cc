//File: imgDist.cc
//Date: Sun Dec 29 15:39:00 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <limits>
#include <iostream>
#include <omp.h>
using namespace std;

#include "prgReporter.hh"
#include "imgDist.hh"
#include "matrix.hh"

// Optimized Image Resizing Using Seam Carving and Scaling, by W Dong, 2009
namespace {
	const int PATCH_SIZE = 10;
	const int PATCH_SHIFT = 5;

	typedef pair<int, int> Patch;

	vector<Patch> get_patches(const Img& img) {
		int noww = 0, nowh = 0;
		vector<Patch> ret;
		while (nowh <= img.h - PATCH_SIZE) {
			while (noww <= img.w - PATCH_SIZE) {
				ret.emplace_back(noww, nowh);
				noww += PATCH_SHIFT;
			}
			nowh += PATCH_SHIFT;
			noww = 0;
		}
		return ret;
	}

	inline Color get_patch_point(const Img& img, Patch p, int w, int h)
	{ return img.get_pixel(p.second + h, p.first + w); }

	real_t cal_IMED(const Img& img1, Patch p1, const Img& img2, Patch p2, real_t thres) {
		thres = thres * thres;
		real_t diff_h = (float)p1.second / img1.h - (float)p2.second / img2.h;
		if (fabs(diff_h) > 0.4)
			return numeric_limits<real_t>::max();
		real_t start_diff = sqr((float)p1.first / img1.w - (float)p2.first / img2.w) + sqr(diff_h);
		/*
		 *if (start_diff > 0.4)
		 *    return numeric_limits<real_t>::max();
		 */
		start_diff /= 2;
		Color sum(0, 0, 0);
		REP(i1, PATCH_SIZE) REP(j1, PATCH_SIZE) REP(i2, PATCH_SIZE) REP(j2, PATCH_SIZE) {
			Color diff_1 = (get_patch_point(img1, p1, i1, j1) - get_patch_point(img2, p2, i1, j1)).abs(),
				  diff_2 = (get_patch_point(img1, p1, i2, j2) - get_patch_point(img2, p2, i2, j2)).abs();
			real_t dij2 = sqr((float)i1 / img1.w - (float)i2 / img2.w) + sqr((float)j1 / img1.h - (float)j2 / img2.h);
		    real_t gij = exp(-dij2 / 2);
			//real_t gij = 2 / start_diff;		/// much faster than exp
			sum += diff_1 * diff_2 * gij;
			if (!(sum.x + sum.y + sum.z < thres))			// to avoid inf problem
				return numeric_limits<real_t>::max();
		}
		return sqrt(sum.x) + sqrt(sum.y) + sqrt(sum.z);
	}

	real_t cal_dIE(const Img& img1, const vector<Patch>& p1, const Img& img2, const vector<Patch>& p2) {
		Matrix m(p1.size(), p2.size());
		real_t row_min[m.h],
			   col_min[m.w];
		REP(i, m.h) row_min[i] = numeric_limits<real_t>::max();
		REP(i, m.w) col_min[i] = numeric_limits<real_t>::max();
		REP(i, m.h)  {
			REP(j, m.w) {
				real_t ret = cal_IMED(img2, p2[i], img1, p1[j], max(row_min[i], col_min[j]));
				m.get(i, j) = ret;
				update_min(row_min[i], ret);
				update_min(col_min[j], ret);
			}
		}

		real_t sum0 = 0, sum1 = 0;
		REP(j, m.w) sum0 += col_min[j];
		sum0 /= m.w;
		REP(i, m.h) sum1 += row_min[i];
		sum1 /= m.h;
		return sum0 + sum1;
	}


	real_t cal_img_dist(const Img& img1, const Img& img2) {
		auto p1 = get_patches(img1),
			 p2 = get_patches(img2);
		return cal_dIE(img1, p1, img2, p2);
	}
}


void ImageDist::calculate() {
	auto min_dist = numeric_limits<real_t>::max();
	int min_i = -1;
	int n = results.size();
	ProgressReporter prg(n);
#pragma omp parallel for schedule(dynamic)
	for (int i = 0; i < n; i ++) {
//		results[i].save("tmp-result" + to_string(i) + ".png");
		real_t dist = cal_img_dist(orig, results[i]);
		PP(dist);
#pragma omp critical
		if (update_min(min_dist, dist)) min_i = i;
		prg.update(1);
	}
	PP(min_dist);
	PP(min_i);
	results[min_i].save("opt-result.png");
}
