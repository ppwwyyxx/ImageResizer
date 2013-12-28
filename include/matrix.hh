// File: matrix.hh
// Date: Sat Dec 28 16:40:18 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once
#include <cstring>
#include <memory>
#include "debugutils.hh"
#include "utils.hh"

// basic 2-d array
class Matrix {
	public:
		typedef real_t vtype;

		real_t **val;
		int w = 0, h = 0;

		Matrix(){}

		Matrix(int m_w, int m_h):		// initialize with value 0
			w(m_w), h(m_h) {
				val = new real_t* [h];
				REP(i, h)
					val[i] = new real_t[w]();
			}

		~Matrix() { free_2d<real_t>(val, h); }

		// something bad
		Matrix(const Matrix& m) {
			w = m.w, h = m.h;
			val = new real_t* [h];
			REP(i, h) {
				val[i] = new real_t[w]();
				memcpy(val[i], m.val[i], w * sizeof(real_t));
			}
		}

		Matrix & operator = (const Matrix & m) {
			if (this != &m) {
				free_2d<real_t>(val, h);
				w = m.w, h = m.h;
				val = new real_t* [h];
				REP(i, h) {
					val[i] = new real_t[w]();
					memcpy(val[i], m.val[i], w * sizeof(real_t));
				}
			}
			return *this;
		}

		Matrix & operator = (Matrix && r) {
			m_assert(this != &r);
			free_2d<real_t>(val, h);
			val = r.val;
			w = r.w, h = r.h;
			r.val = nullptr;
			return *this;
		}

		Matrix(Matrix&& r) {
			val = r.val;
			w = r.w, h = r.h;
			r.val = nullptr;
		}
		// something ugly

		real_t & get(int i, int j)
		{ return val[i][j]; }

		const real_t & get(int i, int j) const
		{ return val[i][j]; }

		bool inverse(Matrix & ret) const;

		Matrix transpose() const;

		Matrix prod(const Matrix & r) const;

		bool solve_overdetermined(Matrix & x, const Matrix & b) const;		//

		friend std::ostream& operator << (std::ostream& os, const Matrix & m);

		bool SVD(Matrix & u, Matrix & s, Matrix & v) const;

		void normrot();

		real_t sqrsum() const;

		Matrix col(int i) const;

		static Matrix I(int);
};



template <typename T>
class MatrixBase {
	public:
		T **val;
		int w, h;

		MatrixBase(int m_w, int m_h):
			w(m_w), h(m_h) {
				val = new T* [h];
				for (int i = 0; i < h; i ++)
					val[i] = new T[w]();
		}

		MatrixBase(int m_w, int m_h, T** v)
			:w(m_w), h(m_h) {
			val = new T* [h];
			int rowlen = w * sizeof(T);

			for (int i = 0; i < h; i++) {
				val[i] = new T [w]();
				if (v)
					memcpy(val[i], v[i], rowlen);
			}
		}

		~MatrixBase() {
			for (int i = 0; i < h; i++)
				delete [] val[i];
			delete [] val;
		}

		// get the ith row
		T*& operator [] (int i) { return val[i]; }
};

