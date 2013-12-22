// File: render.hh
// Date: Sun Dec 22 14:34:58 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>


#pragma once

#include <memory>
#include "matrix.hh"
#include "color.hh"
#include "image.hh"

class RenderBase {
	public:
		RenderBase(const Geometry &m_g):
			geo(m_g){}

		virtual ~RenderBase(){};

		virtual void init() {}
		// execute before write

		virtual void finish() {}
		// execute after write

		void write(int x, int y, const Color &c) {
			if (x < 0 || x >= geo.w || y < 0 || y >= geo.h)
				return;
			/*
			 *c.check();
			 */

			_write(x, y, c);
			render_cnt ++;
		}

		void write(const std::shared_ptr<Img>& r) {
			m_assert((r->h == geo.h) && (r->w == geo.w));
			Color *dest = r->pixel;
			REP(i, geo.h) REP(j, geo.w) {
				write(j, i, *dest);
				dest ++;
			}
		}

		const Geometry& get_geo() const
		{ return geo; }

		int get_cnt() const
		{ return render_cnt; }

	private:
		int render_cnt = 0;

	protected:
		Geometry geo;
		virtual void _write(int x, int y, const Color &c) = 0;

};


