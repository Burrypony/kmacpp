#include "Date.h"
#include <iostream>
#include <ctime>

using namespace std;


int main()
{
	Date::showDefault();
	Date::setDefault();
	Date::showDefault();
	cout << "========================";
	Date d1 = Date(31,11,2018);
	Date d2 = d1++;
	cout << d1 << endl << d2;
	Date d3 = Date(1,Date::Month::jan,2018);
	Date d4 = d3--;
	cout << d3 << endl << d4;
	Time t1 = Time( 1 , 0 , 0);
	cout << --t1 <<endl;
	return 0;
}