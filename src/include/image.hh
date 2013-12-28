// File: image.hh
// Date: Sun Dec 29 03:14:20 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include <cstring>
#include <memory>
#include <Magick++.h>
#include "matrix.hh"
#include "color.hh"
class GreyImg;

class Img {
	protected:
		void init(int m_w, int m_h);

		void init_from_image(const Magick::Image& img);

	public:
		int w = 0, h = 0;
		Color** pixel;

		Img(const Img& img):
			Img(img.w, img.h)
		{
			REP(i, h)
				memcpy(pixel[i], img.pixel[i], w * sizeof(Color));
		}

		Img& operator=(const Img& img) {
			if (this != &img) {
				free_2d<Color>(pixel, h);
				init(img.w, img.h);
				REP(i, h)
					memcpy(pixel[i], img.pixel[i], w * sizeof(Color));
			}
			return *this;
		}

		Img(Img&& img) {
			w = img.w, h = img.h;
			pixel = img.pixel;
			img.pixel = nullptr;
		}

		Img & operator = (Img && r) {
			free_2d<Color>(pixel, h);
			pixel = r.pixel;
			w = r.w, h = r.h;
			r.pixel = nullptr;
			return *this;
		}

		Img(int m_w, int m_h)
		{ init(m_w, m_h); }

		explicit Img(const Magick::Image& img)
		{ init_from_image(img); }

		explicit Img(const char* fname) {
			Magick::Image img(fname);
			init_from_image(img);
		}

		explicit Img(const GreyImg& gr);

		~Img()
		{ free_2d<Color>(pixel, h); }

		Img get_resized(real_t factor) const;

		Img get_resized(int, int) const;

		inline Color& get_pixel(int r, int c) const {
			m_assert(between(r, 0, h) && between(c, 0, w));
			return pixel[r][c];
		}

		inline Color& get_pixel_safe(int r, int c) const {
			if (r < 0) r = 0;
			else if (r >= h) r = h - 1;
			if (c < 0) c = 0;
			else if (c >= w) c = w - 1;
			return get_pixel(r, c);
		}

		Color get_pixel(real_t, real_t) const;

		Color& get_pixel(const Coor& w) const
		{ return get_pixel(w.y, w.x);}

		Color get_pixel(const Vec2D& w) const
		{ return get_pixel(w.y, w.x);}

		void fill(const Color& c);

		Vec2D get_center() const { return Vec2D(w / 2, h / 2); }

		void save(const string& fname) const;
};

class GreyImg {
	protected:
		void init(int m_w, int m_h);

		void init_from_img(const Img& img, int conponent = 0);

		void init_from_image(const Magick::Image img);

	public:
		int w =0, h = 0;
		real_t* pixel;

		GreyImg(const GreyImg& img):
			GreyImg(img.w, img.h)
	{ memcpy(pixel, img.pixel, w * h * sizeof(real_t)); }

		GreyImg& operator=(const GreyImg& img) {
			if (this != &img) {
				delete[] pixel;
				init(img.w, img.h);
				memcpy(pixel, img.pixel, w * h * sizeof(real_t));
			}
			return *this;
		}

		GreyImg(int m_w, int m_h)
		{ init(m_w, m_h); }

		GreyImg(const Matrix& m);

		GreyImg & operator = (GreyImg && r) {
			delete[] pixel;
			pixel = r.pixel;
			w = r.w, h = r.h;
			r.pixel = nullptr;
			return *this;
		}

		explicit GreyImg(const Img& img, int component = 0)
		{ init_from_img(img, component); }

		explicit GreyImg(const Magick::Image& img)
		{ init_from_image(img); }

		~GreyImg()
		{ delete[] pixel; }

		std::shared_ptr<Img> to_img() const;

		inline real_t& get_pixel(int r, int c) const {
			m_assert(between(r, 0, h) && between(c, 0, w));
			return *(pixel + r * w + c);
		}

		inline real_t& get_pixel_safe(int r, int c) const {
			if (r < 0) r = 0;
			else if (r >= h) r = h - 1;
			if (c < 0) c = 0;
			else if (c >= w) c = w - 1;
			return get_pixel(r, c);
		}

};


typedef std::shared_ptr<Img> imgptr;
typedef std::shared_ptr<const Img> imgptrc;
