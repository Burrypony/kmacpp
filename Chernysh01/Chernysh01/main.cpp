#include "main.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.1415926
using namespace std;

int main()
{


    double x;
	x = 1;
	
    cout << setprecision(10) << "sin = " << sin(x) <<  endl;
    cout << setprecision(10) << "cos = " << cos(x) <<  endl;
	//cout << setprecision(10) <<"arccos = " << arccos(x) << endl;
	int i=0;
	double E;
	E = 0.000001;
	double sh=x, a=x;
	while((a*=(x*x/(2*i+2)/(2*i+3)))>E) {
		sh+=a;
		i++;
	}
	cout << sh << ' ' << sinh(x) << endl;
	return 0;
    return 0;
}
double cos(double x)
{
    double y = 1;
    double s = 0;
    int i = 1;

    do
    {
        s += y;
        y *= -1 * x * x / ((2 * i - 1) * (2 * i));
        i++;
    }
    while (fabs(y) > 0.0000000000001);

    return s;
}

double sin(double x)
{
    double y = x;
    double s = 0;
    int i = 1;

    do
    {
        s += y;
        y*= -1 * x * x / ((2 * i) * (2 * i + 1));
        i++;
    }
    while (fabs(y) > 0.0000000000001);

    return s;
}
double arccos(double x){
	int i = 0;
	double p = x;
	double s = x;

	do
	{
		p*=(x*x*(2*i + 1)*(2*i + 1))/(2*(i+1)*(2*i + 3));
		s+=p;
		i++;
	}
	while (fabs(p) > 0.000000000001);

	return s;
}