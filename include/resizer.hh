//File: resizer.hh
//Date: Sun Dec 22 02:43:09 2013 +0800
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include "matrix.hh"
#include "image.hh"

class ImageResizer {
	const imgptr & orig_img;
	const GreyImg& greyimg;

	Matrix* energy;

	Matrix* weight_mask;

	public:
		ImageResizer(const imgptr& _orig_img):
			orig_img(_orig_img), greyimg(*orig_img.get()) {
			energy = cal_all_energy();
			weight_mask = new Matrix(greyimg.w, greyimg.h);
		}

		~ImageResizer() {
			delete energy;
			delete weight_mask;
		}

		imgptr resize(int w, int h);

		imgptr remove_column(const imgptr& img, int number);

	protected:
		// caller release memory
		Matrix* cal_all_energy() const;

};
