#pragma once
#include <Eigen/Core>
#include <iostream>

class cVector3d
{
public:
	cVector3d();
	cVector3d(double x, double y, double z);
	cVector3d(const Eigen::Vector3d & o): v_(o) {}

	void set(double a,double b, double c);
	cVector3d & div(double d);
	void zero() { v_.setZero(); }

	cVector3d operator - (const cVector3d & o) const;
	cVector3d operator + (const cVector3d & o) const;
	cVector3d operator * (double d) const;
	double dot(const cVector3d & o) const;
	double length() const;
	double lengthsq() const;
	double distance(const cVector3d & a)const;
	cVector3d & normalize();
	cVector3d & mul(double d) ;
	cVector3d & add(const cVector3d & a);
	void subr(const cVector3d & b, cVector3d & r);
	void addr(const cVector3d & b, cVector3d & r);
	void normalizer(cVector3d & r);
	void mulr(double d, cVector3d & r);
	double operator() (int i) const { return v_(i); } 
	cVector3d & negate() ;
	void crossr(const cVector3d &a, cVector3d & r);
	bool equals(const cVector3d & o);

	Eigen::Vector3d v_;
};

inline cVector3d cAdd(const cVector3d & a, const cVector3d & b)
{
	return a+b;
}	

inline cVector3d cAdd(const cVector3d & a, const cVector3d & b, const cVector3d & c)
{
	return a+b+c;
}	

inline cVector3d cSub(const cVector3d & a, const cVector3d & b)
{
	return a-b;
}

inline cVector3d operator*(double d, const cVector3d & a)
{
	return Eigen::Vector3d(a.v_*d);
}

inline cVector3d cMul(const Eigen::Matrix3d & a, const cVector3d & b)
{
	return Eigen::Vector3d(a*b.v_);
}

inline cVector3d cMul(double a, const cVector3d & b)
{
	return Eigen::Vector3d(a*b.v_);
}


inline cVector3d operator * (const Eigen::Matrix3d & a, const cVector3d & x)
{
	return cMul(a,x);
}

inline Eigen::Matrix3d cTranspose(const Eigen::Matrix3d& o)
{
	return o.transpose();
}

inline cVector3d cProject(const cVector3d &a, const cVector3d & b)
{
	std::cout << "cProject notimpl\n";
	exit(0);

}

inline cVector3d cProjectPointOnLine(const cVector3d & a, const cVector3d & pos, const cVector3d & normal)
{
	std::cout << "cProjectPointOnPlane notimpl\n";
	exit(0);
}

inline cVector3d cProjectPointOnPlane(const cVector3d & a, const cVector3d & pos, const cVector3d & normal)
{
	std::cout << "cProjectPointOnPlane notimpl\n";
	exit(0);

}

inline cVector3d cProjectPointOnPlane(const cVector3d & aa, const cVector3d & v0, const cVector3d & v1,const cVector3d & v2, double &a, double & b)
{
	std::cout << "cProjectPointOnPlane notimpl\n";
	exit(0);

}

inline cVector3d cNormalize(const cVector3d & a)
{
	return (1.0/ a.length())*a;
}

inline double cDistance(const cVector3d & a, const cVector3d & b)
{
	return a.distance(b);
}


inline double cAngle(const cVector3d & a, const cVector3d &b)
{
	std::cout << "cAngle notimpl\n";
	exit(0);
}
	

inline double cMax(double a, double b)
{
	return a > b ? a :b;
}

inline double cClamp(double v, double a, double b)
{
	return v > a ? a : v < b ? b : v;
}

inline double cSqr(double x)
{
	return std::sqrtf(x);
}

inline double cTriangleArea(const cVector3d & a, const cVector3d& b, const cVector3d c)
{
	std::cout << "cTriangleArea notimpl\n";
	exit(0);

}



