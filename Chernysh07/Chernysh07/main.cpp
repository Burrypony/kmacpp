#include "String.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "testing empty constructor"<< endl;
	String st1 = String();
	cout << st1 << endl;
	char* stChar1 = "hello";
	cout <<"testing constructor for char*"<<endl;
	cout<< String(stChar1) <<endl;
	string stl_st1("world");
	cout <<"testing constructor for string"<<endl;
	String st3 = String(stl_st1);
	cout<< st3 <<endl;
	cout <<"testing constructor for multiplayer"<<endl;
	String st4("pu");
	cout << String(st4, 3) <<endl;
	cout << "testing  STL_string() method" << endl;
	cout << st4.STL_string() << endl;
	cout << "testing  c_str() method" << endl;
	cout << st4.c_str() << endl;
	st1 = st3;
	cout << "testing operator = for String" << endl << st1 << endl;
	st1 = stl_st1;
	cout << "testing operator = for string" << endl << st1 << endl;	
	st1 = stChar1;
	cout << "testing operator = for char*" << endl << st1 << endl;	

	const char stChar2 = 'a';
	st1 = stChar2;
	cout << "testing operator = for const char" << endl << st1 << endl;
	char& ch1 = st3[2];
	cout << "testing operator [] for char& " << endl << ch1 << endl;
	const char ch2 = st3[2];
	cout << "testing operator [] for const char " << endl << ch2 << endl;
	String str1("hello");
	String str2("hello");
	String str3("world");
	String str4("Hello world");
	cout << "testing operator == (true) " << endl << ( str1 == str2 ) << endl;
	cout << "testing operator == (false) " << endl << ( str1 == str3 ) << endl;
	cout << "testing operator != (true) " << endl << ( str1 != str3 ) << endl;
	cout << "testing operator != (false) " << endl << ( str1 != str2 ) << endl;
	cout << "testing operator > (false) " << endl << ( str1 > str4 ) << endl;
	cout << "testing operator > (true) " << endl << ( str4 > str1 ) << endl;
	cout << "testing operator < (true) " << endl << ( str1 < str4 ) << endl;
	cout << "testing operator < (false) " << endl << ( str4 < str1 ) << endl;
	cout << "testing operator >= (true) " << endl << ( str1 >= str2 ) << endl;
	cout << "testing operator >= (true) " << endl << ( str4 >= str1 ) << endl;
	cout << "testing operator <= (true) " << endl << ( str1 <= str2 ) << endl;
	cout << "testing operator <= (false) " << endl << ( str4 <= str1 ) << endl;
	cout << "testing operator + " << endl << ( str1 + str3 ) << endl;
	str1 += str3;
	cout << "testing operator += String" << endl << str1 << endl;
	str3 += stChar1;
	cout << "testing operator += char*" << endl << str3 << endl;

	return 0;
}
