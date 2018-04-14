#include "Triangle.h"
#include "Point.h"
#include "Segment.h"
#include <cmath>
#include <iostream>
using namespace std;


Triangle::Triangle(const double x1, const double y1,const double x2, const double y2,const double x3, const double y3):
	_a(Point(x1, y1)),
	_b(Point(x2, y2)),
	_c(Point(x3, y3))
{
	#ifndef NDEBUG
	cout<<"Triangle created with points "<<*this<<endl;
	#endif
	return;
}
Triangle::Triangle(const Point &a, const Point& b, const Point& c):
	_a(a),
	_b(b),
	_c(c)
{
	#ifndef NDEBUG
	cout<<"Triangle created with segments "<<*this<<endl;
	#endif
	return;
}
Triangle::Triangle(const Point &a, const Segment &bc):
	_a(a),
	_b(bc.start()),
	_c(bc.end())
{
	#ifndef NDEBUG
	cout<<"Triangle created with point and segment "<<*this<<endl;
	#endif
	return;
}
Triangle::Triangle (const Triangle& t):
	_a(t._a),
	_b(t._b),
	_c(t._c)
{
	#ifndef NDEBUG
	cout<<"Triangle copied "<<*this<<endl;
	#endif
	return;
}
Triangle::~Triangle()
{
	#ifndef NDEBUG
	cout<<"Triangle deleted "<<*this<<endl;
	#endif
	return;
};
Triangle& Triangle::operator= (const Triangle& t)
{
	_a=t._a;
	_b=t._b;
	_c=t._c;
	return *this;
}
double Triangle::perimeter() const
{
	return side_a().length()+side_b().length()+side_c().length();
}
double Triangle::area() const
{
	return 0.5*side_a().length()*side_a().distance(_a);
}
const Point& Triangle::apexA() const
{
	return _a;
}
const Point& Triangle::apexB() const
{
	return _b;
}
const Point& Triangle::apexC() const
{
	return _c;
}
const Segment Triangle::side_a() const
{
	return Segment(_b, _c);
}
const Segment Triangle::side_b() const
{
	return Segment(_c, _a);
}
const Segment Triangle::side_c() const
{
	return Segment(_a, _b);
}
const double Triangle::length_a() const
{
	return sqrt( pow((_b.x() - _a.x()),2) + pow((_b.y() - _a.y()), 2)) ;
}
const double Triangle::length_b() const
{
	return sqrt( pow((_c.x() - _b.x()),2) + pow((_c.y() - _b.y()), 2)) ;
}
const double Triangle::length_c() const
{
	return sqrt( pow((_a.x() - _c.x()),2) + pow((_a.y() - _c.y()), 2)) ;
}
double Triangle::height_in_num_a() const
{
	return side_a().distance(_a);
}
double Triangle::height_in_num_b() const
{
	return side_b().distance(_b);
}
double Triangle::height_in_num_c() const
{
	return side_c().distance(_c);
}
const Segment Triangle::height_a() const
{
	Point a = apexA();
	Point b = apexB();
	Point c = apexC();
	double catheter1 = fabs(sqrt(pow(length_b(),2) - pow(height_in_num_a(), 2)));
	double catheter2 = length_a()-catheter1;
	if (catheter1 == length_a()||0<=catheter2<=0.4)
	{

		Point x(b.x(), b.y());
		return Segment(_a, x);
	}
	else
	{
		double alpha = catheter1/catheter2;
		double x1 = (c.x()+alpha*b.x())/(1 + alpha);
		double y1 = (c.y()+alpha*b.y())/(1 + alpha);
		Point x(x1, y1);
		return Segment(_a, x);
	}

}
const Segment Triangle::height_b() const
{
	double catheter1 = fabs(sqrt(pow(length_a(),2) - pow(height_in_num_b(), 2)));
	double catheter2 = length_b() - catheter1;
	Point a = apexA();
	Point b = apexB();
	Point c = apexC();
	if (catheter1 == length_b()||0<=catheter2<=0.4)
	{
		Point x(a.x(), a.y());
		return Segment(_b, x);
	}
	else
	{
		double alpha = catheter1/catheter2;
		double x1 = (a.x()+alpha*c.x())/(1 + alpha);
		double y1 = (a.y()+alpha*c.y())/(1 + alpha);
		Point x(x1, y1);
		return Segment(_b, x);
	}
}

const Segment Triangle::height_c() const
{
	double catheter1 = fabs(sqrt(pow(length_a(),2) - pow(height_in_num_c(), 2)));
	double catheter2 = length_c() - catheter1;
	Point a = apexA();
	Point b = apexB();
	Point c = apexC();
	if (catheter1 == length_c()||0<=catheter2<=0.4)
	{
		Point x(a.x(), a.y());
		return Segment(_c, x);
	}
	else
	{
		double alpha = catheter1/catheter2;
		double x1 = (a.x()+alpha*b.x())/(1 + alpha);
		double y1 = (a.y()+alpha*b.y())/(1 + alpha);
		Point x(x1, y1);
		return Segment(_c, x);
	}
}


ostream& operator<<(ostream & os, const Triangle & t)
{	
	os<<'('<<t.apexA()<<','<<t.apexB()<<','<<t.apexC()<<')';
	return os;
}