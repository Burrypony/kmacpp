#include "Point.h"
#include "Segment.h"
#include "Triangle.h"
#include <iostream>
using namespace std;


size_t Point::_freeID = 0;
int Segment::_freeID = 0;
int main()
{ 
	cout << "testing constructor with coordinates" <<endl;
	Triangle t1(4,6,1,4,8,10);
	cout << t1 <<endl;
	cout << "testing constructor with points" <<endl;
	Triangle t2(Point(4,61), Point(66,64), Point(2,10));
	cout << t2 << endl;
	cout << "testing perimeter method: "<< t1.perimeter() << endl;
	cout << "testing area method: "<<t2.area() << endl;
	cout << "t1 ApexA: " << t1.apexA() <<" t1 ApexB: "<< t1.apexB() <<" t1 ApexC: "<< t1.apexC() <<endl;
	cout << "t2 side A: " << t2.side_a() <<" t2 side B: "<< t2.side_b() <<" t2 side C: "<< t2.side_c() <<endl;
	cout << "t2 length A: " << t2.length_a() <<" t2 length B: "<< t2.length_b() <<" t2 length C: "<< t2.length_c() <<endl;
	cout<<"Height b in segment "<<t1.height_b()<<endl;
	cout<<"Height c in segment "<<t1.height_c()<<endl;
	cout<<"Height a in number "<<t1.height_in_num_b()<<endl;
	cout<<"Height b in number "<<t1.height_in_num_c()<<endl;
	return 0;
}