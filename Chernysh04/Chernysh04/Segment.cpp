#include <iostream>
#include <cmath>
#include "Segment.h"
#include "Point.h"
using namespace std;


Segment::Segment(const double x1, const double y1, const double x2, const double y2):
 _a( Point(x1, y1)),
 _b( Point(x2, y2)),
 _myId(++_freeID)
{
	#ifndef NDEBUG
	cout<<"segment "<<_myId<<": created "<<*this<<endl;
	#endif
	return;
};

Segment::Segment(const Point &start, const Point &end):
 _a(start),
 _b(end),
 _myId(++_freeID)
{
	#ifndef NDEBUG
	cout<<"segment "<<_myId<<": created "<<*this<<endl;
	#endif
	return;
};

Segment::Segment(const Segment& s):
 _a(s._a),
 _b(s._b),
 _myId(++_freeID)
{
	#ifndef NDEBUG
	cout<<"segment "<<_myId<<": copied "<<*this<<endl;
	#endif
	return;
}

Segment::~Segment()
{
	#ifdef NDEBUG
	cout<<myId<<": removed "<<*this<<endl;
	#endif
	return;
}

Segment& Segment::operator=(const Segment& s)
{
	_a=s._a;
    _b=s._b;
    return *this;
}

const Point& Segment::start() const
{
	return _a;
}
	
const Point& Segment::end() const
{
	return _b;
}

Point &Segment::start()
{
	return _a;
}

Point &Segment::end()
{
	return _b;
}
const double &Segment::startX() const
{
	return _a.x();
}

const double &Segment::startY() const
{
	return _a.y();
}

const double &Segment::endX() const
{
	return _b.x();
}

const double &Segment::endY() const
{
	return _b.y();
}

double &Segment::startX()
{
	return _a.x();
}

double &Segment::startY()
{
	return _a.y();
}

double &Segment::endX()
{
	return _b.x();
}

double &Segment::endY()
{
	return _b.y();
}

double Segment::length () const
{
	return sqrt( pow((_b.x() - _a.x()),2) + pow((_b.y() - _a.y()), 2)) ;
}

double Segment::distance (const Point& k) const
{
	return (abs((_b.y()-_a.y())*k.x()+(_a.x()-_b.x())*k.y()-(_a.y()*_a.x()-_a.y()*_b.x()+_a.x()*_b.y()-_a.x()*_a.y())))
		/ sqrt(pow((_b.y()-_a.y()),2)+ pow((_a.x()-_b.x()),2));
}

const int Segment::getID() const
{
	return _myId;
}
 ostream& operator<<(ostream &os, const Segment & s)
{
	os<<'('<<s.start()<<','<<s.end()<<')';
	return os;
};