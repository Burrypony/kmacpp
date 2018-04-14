#ifndef _COMPLEXAG_H_

#define _COMPLEXAG_H_
#include <iostream>
#include "ComplexTrig.h"

using namespace std;

class TComplex;
class AComplex 
{
private:
	double _a;
	double _b;

public:
	AComplex ( double a=0 , double b=0);
	AComplex(const AComplex&);
	~AComplex ();
	AComplex& operator+(const AComplex&);
	AComplex& operator-(const AComplex&);
	AComplex& operator*(const AComplex&);
	AComplex& operator/(const AComplex&);
	AComplex& operator=(const AComplex&);
	AComplex& operator+(const TComplex&);
	AComplex& operator-(const TComplex&);
	AComplex& operator*(const TComplex&);
	AComplex& operator/(const TComplex&);

	const double& a() const;
	const double& b() const;
	const TComplex& ToTComplex() const;
};

ostream& operator<<(ostream&, const AComplex&);

#endif