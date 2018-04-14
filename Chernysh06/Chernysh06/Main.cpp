#include "Time.h"
#include "Timer.h"
#include "Date.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

int main()
{
	Time t1 = Time( 1 , 0 , 0);
	cout << "Testing constructor: " << t1 << endl;
	Time t2 = Time( t1);
	cout << "Testing copy constructor: " << t2 << endl;
	cout << "Testing convertion to int: " << (int) t1 << " seconds" << endl;
	cout << "Testing convertion to double: " << (double) t1 << " hours" << endl;
	/*cout << "Testing postfix operator ++ " << t1++ << " " << t1 << endl;
	cout << "Testing prefix operator ++ " << ++t1 << " " << t1 << endl;*/
	cout << "Testing postfix operator -- " << t2-- << " " << t2 << endl;
	cout << "Testing prefix operator -- " << --t1 << " " << t1 << endl;
	cout << "Testing addition " << t1 + t2 << endl;
	cout << "Testing timer" << endl;
	try 
	{
		Timer tmr = Timer( Date( 11, 2, 2018 ), Time( 15, 59, 22 ), 5 );
	}
	catch( const std::invalid_argument& e ) 
	{
		cout << "Cannot set alarm in the past" << endl;
	}


	return 0;
}