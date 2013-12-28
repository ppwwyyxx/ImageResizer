// File: matrix.cc
// Date: Sun Dec 29 02:34:46 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include <boost/numeric/mtl/mtl.hpp>
#include "matrix.hh"
#include "geometry.hh"

typedef mtl::matrix::dense2D<real_t> mtlM;
using namespace std;

ostream& operator << (std::ostream& os, const Matrix & m) {
	os << "[" << m.w << " " << m.h << "] :" << endl;
	REP(i, m.h) REP(j, m.w)
		os << m.get(i, j) << (j == m.w - 1 ? "\n" : ", ");
	return os;
}

Matrix Matrix::transpose() const {
	Matrix ret(h, w);
	REP(i, h) REP(j, w)
		ret.get(j, i) = val[i][j];
	return move(ret);
}

Matrix Matrix::prod(const Matrix & r) const {
	m_assert(w == r.h);
	const Matrix transp(r.transpose());
	Matrix ret(r.w, h);
	REP(i, h) REP(j, r.w) REP(k, w)
		ret.get(i, j) += val[i][k] * transp.get(j, k);
	return move(ret);
}


void Matrix::normrot() {
	m_assert(w == 3);
	Vec p(val[0][0], val[1][0], val[2][0]);
	Vec q(val[0][1], val[1][1], val[2][1]);
	Vec r(val[0][2], val[1][2], val[2][2]);
	p.normalize();
	q.normalize();
	r.normalize();
	Vec vtmp = p.cross(q);
	real_t dist = (vtmp - r).mod();
	if (dist > 1e-6)
		r = vtmp;
	val[0][0] = p.x, val[1][0] = p.y, val[2][0] = p.z;
	val[0][1] = q.x, val[1][1] = q.y, val[2][1] = q.z;
	val[0][2] = r.x, val[1][2] = r.y, val[2][2] = r.z;
}

real_t Matrix::sqrsum() const {
	m_assert(w == 1);
	real_t sum = 0;
	REP(i, h)
		sum += sqr(val[i][0]);
	return sum;
}

Matrix Matrix::col(int i) const {
	m_assert(i < w);
	Matrix ret(1, h);
	REP(j, h)
		ret.get(j, 0) = get(j, i);
	return move(ret);
}

Matrix Matrix::I(int k) {
	Matrix ret(k, k);
	REP(i, k)
		ret.get(i, i) = 1;
	return move(ret);
}
