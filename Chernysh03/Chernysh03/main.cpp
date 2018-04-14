#include "ComplexAg.h"
#include "ComplexTrig.h"
#include <iostream>
using namespace std;

int main ()
{
	AComplex a1(10, 20);
	AComplex a2(3, 5);
	TComplex t1(5, 45);
	TComplex t2(10, 30);
	AComplex resA;
	TComplex resT;

	cout << "AComplex: " << a1 << endl;
	cout << "TComplex: " << t1 << endl;
	resA = t1.ToAComplex(); 
	cout << "TComplex converted to AComplex: " << resA << endl;
	resT = a1.ToTComplex();
	cout << "AComplex converted to TComplex: " << resT << endl;
	resA = a1 + a2;
	cout << "AComplex + AComplex: " << resA << endl; 
	resA = a1 - a2;
	cout << "AComplex - AComplex: " << resA << endl; 
	resA = a1 * a2;
	cout << "AComplex * AComplex: " << resA << endl; 
	resA = a1 / a2;
	cout << "AComplex / AComplex: " << resA << endl; 
	resT = t1 + t2;
	cout << "TComplex + TComplex: " << resT << endl; 
	resT = t1 - t2;
	cout << "TComplex - TComplex: " << resT << endl; 
	resT = t1 * t2;
	cout << "TComplex * TComplex: " << resT << endl; 
	resT = t1 / t2;
	cout << "TComplex / TComplex: " << resT << endl; 
	return 0;

}