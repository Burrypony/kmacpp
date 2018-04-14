#include "Point.h"
#include "Segment.h"

#ifndef _TRIANGLE_H_

#define _TRIANGLE_H_
//*******************************************

//    Lab task 4

//    Developed by Kiril Chernysh

//    at 18.02.2018

//    Version 1.0

//*******************************************

class Point;
class Segment;


class Triangle

{

private:

/*    *************************************************

������������� �� ����������� �������������

(� ����� ���� ��������� ��������� �ᒺ���)

���������� ���������� �� ��������� ���� ������

� (���) �����


Point _a, _b, _c;

Segment _ab, _bc, _ca;

Point &_a, &_b, &_c;

Segment &_ab, &_bc, &_ca;

Point *_a, *_b, *_c;

Segment *_ab, *_bc, *_ca;


����� ���� ����� � ������

�� �������� ��� ��������


**    ************************************************* */
	Point _a;
	Point _b;
	Point _c;

public:

Triangle(const double x1=0, const double y1=0,const double x2=1, const double y2=0,const double x3=0, const double y3=1);

Triangle(const Point &a, const Point& b, const Point& c);

Triangle(const Point &a, const Segment &bc);


// �� �������� ������� ���� ������������


Triangle (const Triangle&);

~Triangle();

Triangle& operator= (const Triangle&);


double perimeter() const;

double area() const;


// �������

const Point& apexA() const;

const Point& apexB() const;

const Point& apexC() const;


// �������

const Segment side_a() const;

const Segment side_b() const;

const Segment side_c() const;


// ������� �����

const double length_a() const;

const double length_b() const;

const double length_c() const;



const Segment height_a() const;

const Segment height_b() const;

const Segment height_c() const;

double height_in_num_a() const;

double height_in_num_b() const;

double height_in_num_c() const;



};


ostream& operator<<(ostream &, const Triangle &);


// �����: �� ������� ��������� ���������, ��� ������ ������ ���������

// ������
/*
const Segment& height_a() const;

const Segment& height_b() const;

const Segment& height_c() const;
*/
#endif