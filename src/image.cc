// File: image.cc
// Date: Sun Dec 29 01:36:27 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include "image.hh"
#include "filter.hh"
#include "render/filerender.hh"
#include "render/MImageRender.hh"
using namespace std;
using namespace Magick;

void Img::init(int m_w, int m_h) {
	w = m_w, h = m_h;
	pixel = new ::Color[w * h];
}

void GreyImg::init(int m_w, int m_h) {
	w = m_w, h = m_h;
	pixel = new real_t[w * h];
}

void Img::init_from_image(const Image& img) {
	Magick::Geometry size = img.size();
	init(size.width(), size.height());

	::Color *dest = pixel;

	const PixelPacket* src = img.getConstPixels(0, 0, w, h);
	REP(i, h) REP(j, w) {
		dest->x = (real_t)(src->red) / QuantumRange;
		dest->y = (real_t)(src->green) / QuantumRange;
		dest->z = (real_t)(src->blue) / QuantumRange;
		dest ++;
		src ++;
	}
}

Img::Img(const GreyImg& gr) {
	init(gr.w, gr.h);
	REP(i, h) REP(j, w) {
		real_t grey = gr.get_pixel(i, j);
		get_pixel(i, j) = ::Color(grey, grey, grey);
	}
}

Img Img::get_resized(real_t factor) const {
	int neww = ceil(w * factor),
		newh = ceil(h * factor);
	Image img = MImg(make_shared<Img>(*this)).get_img();
	img.resize(Magick::Geometry(neww, newh));
	return Img(img);
}

Img Img::get_resized(int neww, int newh) const {
	Image img = MImg(make_shared<Img>(*this)).get_img();
	img.resize(Magick::Geometry(neww, newh));
	return Img(img);
}

void Img::fill(const ::Color& c) {
#pragma omp parallel for schedule(static)
	REP(i, h) REP(j, w) get_pixel(i, j) = c;
}

::Color& Img::get_pixel(int r, int c) const {
	m_assert(between(r, 0, h) && between(c, 0, w));
	::Color *dest = pixel + r * w + c;
	return *dest;
}

::Color& Img::get_pixel_safe(int r, int c) const {
	if (r < 0) r = 0;
	else if (r >= h) r = h - 1;
	if (c < 0) c = 0;
	else if (c >= w) c = w - 1;
	::Color *dest = pixel + r * w + c;
	return *dest;
}

::Color Img::get_pixel(real_t y, real_t x) const {
	::Color ret = ::Color::BLACK;
	real_t dy = y - floor(y), dx = x - floor(x);
	ret += get_pixel((int)floor(y), (int)floor(x)) * ((1 - dy) * (1 - dx));
	ret += get_pixel((int)ceil(y), (int)floor(x)) * (dy * (1 - dx));
	ret += get_pixel((int)ceil(y), (int)ceil(x)) * (dy * dx);
	ret += get_pixel((int)floor(y), (int)ceil(x)) * ((1 - dy) * dx);
	return ret;
}

void Img::save(const string& fname) const {
	imgptr result = make_shared<Img>(*this);
	FileRender rd(result, fname);
	rd.finish();
}

real_t& GreyImg::get_pixel(int r, int c) const {
	m_assert(between(r, 0, h) && between(c, 0, w));
	return *(pixel + r * w + c);
}

real_t& GreyImg::get_pixel_safe(int r, int c) const {
	if (r < 0) r = 0;
	else if (r >= h) r = h - 1;
	if (c < 0) c = 0;
	else if (c >= w) c = w - 1;
	return *(pixel + r * w + c);
}

GreyImg::GreyImg(const Matrix& m) {
	init(m.w, m.h);
	double max = 0;
	REP(i, h) REP(j, w) {
		double v = m.get(i, j);
		update_max(max, v);
		get_pixel(i, j) = v;
	}
	REP(i, h) REP(j, w)
		get_pixel(i, j) /= max;
}

void GreyImg::init_from_img(const Img& img, int component) {
	init(img.w, img.h);
	switch (component) {
		case 0:
			REP(i, h) REP(j, w)
				get_pixel(i, j) = Filter::to_grey(img.get_pixel(i, j));
			break;
		case 1:
			REP(i, h) REP(j, w)
				get_pixel(i, j) = img.get_pixel(i, j).x;
			break;
		case 2:
			REP(i, h) REP(j, w)
				get_pixel(i, j) = img.get_pixel(i, j).y;
			break;
		case 3:
			REP(i, h) REP(j, w)
				get_pixel(i, j) = img.get_pixel(i, j).z;
			break;
		default:
			m_assert(false);
	}
}

imgptr GreyImg::to_img() const {
	imgptr ret = make_shared<Img>(w, h);
	REP(i, h) REP(j, w) {
		real_t grey = get_pixel(i, j);
		ret->get_pixel(i, j) = ::Color(grey, grey, grey);
	}
	return ret;
}
