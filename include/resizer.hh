//File: resizer.hh
//Date: Sun Dec 22 12:35:05 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include "matrix.hh"
#include "image.hh"

typedef vector<int> Path;

class ImageResizer {
	public:
	const Img& orig_img;
	GreyImg greyimg;

	Matrix energy;

	Matrix weight_mask;

//	MatrixBase<bool> removed;

	public:
		ImageResizer(const Img& _orig_img):
			orig_img(_orig_img), greyimg(_orig_img),
			weight_mask(_orig_img.w, _orig_img.h) {
			energy = cal_all_energy();
		}

		~ImageResizer() { }

		Img resize(int w, int h);

		void remove_column(int number);


	protected:
		// caller release memory
		Matrix cal_all_energy() const;

		static Path get_path(const Matrix& e, real_t min_e, int min_i);

		void remove_one_column();

		// remove path from orig_img, greyimg, weight_mask, update energy, record to removedPoint
		void remove_vert_path(const Path& p);

};
