#include "Point.h"
#ifndef _SEGMENT_H_

#define _SEGMENT_H_


//*******************************************

//Every segment posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a segment created or resp. deleted

//Developed by Kiril Chernysh

//at 04.02.2018

//Version 1.0

//*******************************************

 

// ���� ������

class Segment

{

private:

// ������ ���������� ������

static int _freeID;

const int _myId;

// ����� ������� ������

Point _a;

// ����� ���� ������

Point _b;

public:

// ������������ ������

// 1) �� ������������ ���� �����

Segment(const double x1=0, const double y1=0,

const double x2=1, const double y2=0);

// 2) �� ������� ������� � ����

Segment(const Point &start, const Point &end);


// 3) ����������� �����������

Segment(const Segment&);

// ����������

~Segment();

// ���������

Segment& operator=(const Segment&);

// ���������  �����

const Point& start() const;

const Point& end() const;

// ���������-������������ �����

Point &Segment::start();

Point &Segment::end();

// ��������� ��������� �����

const double &Segment::startX() const;

const double &Segment::startY() const;

const double &Segment::endX() const;

const double &Segment::endY() const;

// ���������-������������ ��������� �����

double &Segment::startX();

double &Segment::startY();

double &Segment::endX();

double &Segment::endY();

// ���������� ������� ������

double length () const;

// ���������� ������� �� ������ �� �����

double distance (const Point&) const;

// �������� ID

const int getID() const;

};

 

ostream& operator<<(ostream &, const Segment &);

#endif