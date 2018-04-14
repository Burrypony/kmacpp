#include "Array.h"
#include <iostream>

using namespace std;


int main()
{
	Array<3,int> ai;
	cout<<ai<<endl; 
	ai[0]=1; ai[1]=2; ai[2]=3; 
	cout<<ai<<endl;
	Array<4, char> ci;
	cout<<ci<<endl; 
	ci[0]='a'; ci[1]='b'; ci[2]='c'; ci[3]='d';
	cout<<ci<<endl;
	Array<2, string> si;
	cout<<si<<endl;
	si[0]="first"; si[1]="second";
	cout<<si<<endl;
	try
	{
		si[5]="fifth";
	}
	catch( const Array<2, string>::BadArray& ba)
	{
		ba.diagnose();
	}
	
	return 0;
}