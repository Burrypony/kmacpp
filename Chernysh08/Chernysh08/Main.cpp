#include "Screen.h"
#include <iostream>
#include <math.h>

using namespace std;


int main()
{
 	
 const int size=100;
 Screen demo(size, size);
 cout<<"Empty screen created"<<endl<<endl; demo.show();
	for(int i=0; i<=size; i++){
	 double x1 = pow((double)i, 2);
	 int x1Int = x1;
	 demo.set('*').move( i ,x1Int);	
    //cout << x1 <<"==========="<< i << endl;
    } 
 cout<<"The screen filled"<<endl<<endl;
 for(int i=0; i<=size; i++)
 {
	 demo.set('*').move( i , i);	
    //cout << x1 <<"==========="<< i << endl;
 }
 demo.show();
}
