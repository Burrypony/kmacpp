#ifndef _POINT_H_

#define _POINT_H_

#include <iostream>

using namespace std;

 

//*******************************************

//Every point posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a point created or resp. deleted

//Developed by Kiril Chernysh

//on 28.01.2018

//Version 1.0

//*******************************************

 

class Point

{

private:

	static size_t _freeID;
	const size_t _pointID;
	double _x;
	double _y;

public:

	Point (double x=0, double y=0);
	Point (const Point &);
	~Point();
	Point& operator=(const Point &);
	double& x();
	double& y();
	const double& x()const;
	const double& y()const;
	const int getID() const;
	static int amount();
};

 

ostream& operator<<(ostream&, const Point&);

 

const Point operator+ (const Point & u, const Point & v);

bool operator==(const Point & u, const Point &v);

bool operator!=(const Point & u, const Point &v);


 

#endif

