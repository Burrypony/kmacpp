#include <iostream>
#include "POINT.h"
using namespace std;

Point::Point (double x, double y):
 _x (x),
 _y (y),
 _pointID (++_freeID)
{
#ifdef NDEBUG
cout<<pointID<<": created "<<*this<<endl;
#endif
return;
};

Point::Point (const Point & u):
	_x (u._x),
	_y (u._y),
	_pointID(++_freeID)
	{
#ifdef NDEBUG
cout<<pointID<<": copied " <<*this<<endl;
#endif
return;
	};

Point::~Point()
{
#ifdef NDEBUG
cout<<pointID<<": removed "<<*this<<endl;
#endif
return;
};

Point& Point::operator=(const Point & p){
    _x=p._x;
    _y=p._y;
    return *this;
  };

double& Point::x()
{
	return _x;
};

double& Point::y()
{
	return _y;
};

const double& Point::x()const
{
	return _x;
}
const double& Point::y()const
{
	return _y;
}

const int Point::getID()const
{
	return _pointID;
}

int Point::amount()
{
	return _freeID;
}

ostream& operator<<(ostream &os, const Point & n)
{
	os<<'('<<n.x()<<','<<n.y()<<')';
	return os;
};

const Point operator+ (const Point & u, const Point & v)
{
  return Point( u.x() + v.x(), u.y() + v.y() );
};

bool operator==(const Point & u, const Point &v)
{
	return ( u.x() == v.x() && v.x() == v.y() );
}

bool operator!=(const Point & u, const Point &v)
{
	return !(u == v);
}




