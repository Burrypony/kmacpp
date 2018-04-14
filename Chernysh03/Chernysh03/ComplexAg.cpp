#include <iostream>
#include "ComplexAg.h"
#include "ComplexTrig.h"
#include <math.h>
using namespace std;
#define PI 3.14159265


AComplex::AComplex ( const double a, const double b):
_a(a),
_b(b)
{
	#ifndef NDEBUG
	cout<<"Algebraic Complex created"<<*this<<endl;
	#endif
	return;
}

AComplex& AComplex::operator=(const AComplex & s)
{
	_a=s._a;
	_b=s._b;
	return *this;
}
AComplex::AComplex(const AComplex& s):
	_a(s._a),
	_b(s._b)
{
	#ifndef NDEBUG
	cout<<"AComplex copied "<<*this<<endl;
	#endif
	return;
}
AComplex::~AComplex()
{
	#ifdef NDEBUG
	cout<<"AComplex removed"<<*this<<endl;
	#endif
	return;
}
const double& AComplex::a() const
{
	return _a;
}
const double& AComplex::b() const
{
	return _b;
}

AComplex& AComplex::operator+(const AComplex & s)
{
    AComplex res = AComplex(this->a() + s.a(), this->b() + s.b());

    return res;
}
AComplex& AComplex::operator-(const AComplex & s)
{
	AComplex res = ( this->a() - s.a(), this->b() - s.b() );
	return res;
}
AComplex& AComplex::operator* (const AComplex & s)
{
	 AComplex res = ( (this->a()*s.a())-(this->b()*s.b()),(this->a()*s.b())+(this->b()*s.a()) );
	 return res;
}
AComplex& AComplex::operator/(const AComplex & s)
{
	AComplex res = ( (this->a()*s.a()+this->b()*s.b())/(pow(s.a(),2) + pow(s.b(), 2)), (this->a()*s.b() - this->b()*s.a())/(pow(s.a(), 2) + pow(s.b() , 2)) );
	return res;
}

AComplex& AComplex::operator+(const TComplex & s)
{
	AComplex res = *this + s.ToAComplex();

    return res;
}
AComplex& AComplex::operator-(const TComplex & s)
{
	AComplex res = *this - s.ToAComplex();

    return res;
}
AComplex& AComplex::operator* (const TComplex & s)
{
	AComplex res = *this * s.ToAComplex();

	return res;
}
AComplex& AComplex::operator/(const TComplex & s)
{
	AComplex res = *this / s.ToAComplex();

	return res;
}

const TComplex& AComplex::ToTComplex() const
{
	double r;
	double alpha;
	r = sqrt(pow(_a ,2) + pow(_b, 2));
	alpha = acos(_a/r) * 180 / PI;
	return TComplex (r, alpha);

}

ostream& operator<<(ostream &os, const AComplex & s)
{
	os<<"("<<s.a()<<"+"<<s.b()<<"i)";
	return os;
};
