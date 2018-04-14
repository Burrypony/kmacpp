
#ifndef _COMPLEXTRIG_H_

#define _COMPLEXTRIG_H_
#include <iostream>
#include "ComplexAg.h"

using namespace std;

class AComplex;
class TComplex
{
private:
	double _r;
	double _alpha;
public:
	TComplex ( double r=0 , double alpha=0);
	TComplex(const TComplex&);
	~TComplex ();
	TComplex& operator=(const TComplex&);
	TComplex& operator+(const TComplex&);
	TComplex& operator-(const TComplex&);
	TComplex& operator*(const TComplex&);
	TComplex& operator/(const TComplex&);
	TComplex& operator=(const AComplex&);
	TComplex& operator+(const AComplex&);
	TComplex& operator-(const AComplex&);
	TComplex& operator*(const AComplex&);
	TComplex& operator/(const AComplex&);
	const double& r() const;
	const double& alpha() const;
	const AComplex& ToAComplex() const;
};

ostream& operator<<(ostream&, const TComplex&);

#endif