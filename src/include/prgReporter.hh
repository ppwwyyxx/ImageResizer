//File: prgReporter.hh
//Date: Sat Dec 28 15:47:13 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once
#include <iostream>
#include "utils.hh"


class ProgressReporter {

	double total, now;

	HWTimer timer;

	bool verbose;

	inline void print_progress(double percent) {
		printf("Progress: %.6lf %%\r", percent * 100);
		fflush(stdout);
	}


	public:
		ProgressReporter(double m_total, bool m_verbose = false) :
			total(m_total), now(0), timer(""), verbose(m_verbose) {
			timer.verbose = false;
		}

		void set(double set_now) {
			now = set_now;
			print_progress(now / total);
			if (verbose)
				std::cout << timer.sec() << std::endl;
		}

		void update(double diff) { set(now + diff); }
};
