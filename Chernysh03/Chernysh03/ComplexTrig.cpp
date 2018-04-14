
#include <iostream>
#include "ComplexTrig.h"
#include <math.h>
using namespace std;
#define PI 3.14159265


TComplex::TComplex ( const double r, const double alpha):
_r(r),
_alpha(alpha)
{
	#ifndef NDEBUG
	cout<<"Trigonometric Complex created"<<*this<<endl;
	#endif
	return;
}
TComplex& TComplex::operator=(const TComplex & k)
{
	_r=k._r;
	_alpha=k._alpha;
	return *this;
}
TComplex::TComplex(const TComplex& k):
	_r(k._r),
	_alpha(k._alpha)
{
	#ifndef NDEBUG
	cout<<"TComplex copied "<<*this<<endl;
	#endif
	return;
}
TComplex::~TComplex()
{
	#ifdef NDEBUG
	cout<<"TComplex removed"<<*this<<endl;
	#endif
	return;
}
const double& TComplex::r() const
{
	return _r;
}
const double& TComplex::alpha() const
{
	return _alpha;
}

TComplex& TComplex::operator+(const TComplex & s)
{
	AComplex c1;
	AComplex c2;
	TComplex res;

	c1 = this->ToAComplex();
	c2 = s.ToAComplex();
	res = (c1 + c2).ToTComplex();

    return res;
}

TComplex& TComplex::operator-(const TComplex & s)
{
	AComplex c1;
	AComplex c2;
	TComplex res;

	c1 = this->ToAComplex();
	c2 = s.ToAComplex();
	res = (c1 - c2).ToTComplex();

    return res;
}

TComplex& TComplex::operator*(const TComplex & s)
{
	AComplex c1;
	AComplex c2;
	TComplex res;

	c1 = this->ToAComplex();
	c2 = s.ToAComplex();
	res = (c1 * c2).ToTComplex();

    return res;
}

TComplex& TComplex::operator/(const TComplex & s)
{
	AComplex c1;
	AComplex c2;
	TComplex res;

	c1 = this->ToAComplex();
	c2 = s.ToAComplex();
	res = (c1 / c2).ToTComplex();

    return res;
}

TComplex& TComplex::operator+(const AComplex & s)
{
	AComplex c1;
	TComplex res;

	c1 = this->ToAComplex();
	res = (c1 + s).ToTComplex();

    return res;
}

TComplex& TComplex::operator-(const AComplex & s)
{
	AComplex c1;
	TComplex res;

	c1 = this->ToAComplex();
	res = (c1 - s).ToTComplex();

    return res;
}

TComplex& TComplex::operator*(const AComplex & s)
{
	AComplex c1;
	TComplex res;

	c1 = this->ToAComplex();
	res = (c1 * s).ToTComplex();

    return res;
}

TComplex& TComplex::operator/(const AComplex & s)
{
	AComplex c1;
	TComplex res;

	c1 = this->ToAComplex();
	res = (c1 / s).ToTComplex();

    return res;
}


const AComplex& TComplex::ToAComplex() const
{
	double a;
	double b;
	a = _r*cos(_alpha*PI/180);
	b = _r*sin(_alpha*PI/180);
	return AComplex (a, b);

}
ostream& operator<<(ostream &os, const TComplex & s)
{
	os<<s.r()<<"(cos"<<s.alpha()<<" + sin" << s.alpha() <<")";
	return os;
};