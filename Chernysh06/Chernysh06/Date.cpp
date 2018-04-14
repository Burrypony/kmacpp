#include "Date.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;


Date::Date ( int d, int m, int y):
_day(d),
_month(m),
_year(y)
{
	#ifdef NDEBUG
	cout<<"Date created "<<*this<<endl;
	#endif
	return;
}

Date::Date ( int d, Month m, int y):
_day(d),
_month(m),
_year(y)
{
	#ifdef NDEBUG
	cout<<"Date created "<<*this<<endl;
	#endif
	return;
}

Date::Date (const Date& d):
_day(d._day),
_month(d._month),
_year(d._year)
{
	#ifndef NDEBUG
	cout<<"Date copied "<<*this<<endl;
	#endif
	return;
}

int Date::day() const
{
	return _day;
}
int Date::month() const
{
	return _month;
}
int Date::year() const
{
	return _year;
}

void Date::setDay(int d)
{
	_day = d;
}
void Date::setMonth(int m)
{
	_month = m;
}
void Date::setDYear(int y)
{
	_year = y;
}
bool Date::leapYear(int y)
{
	if (y%4 == 0)
	{
		if(y%100 == 0)
		{
			if(y%400 == 0)
			{
				return true;
			}else {
			return false;
			}
		}else {
			return true;
		}
	}else {
		return false;
	}

}

int Date::getDayNumber()
{
	int dayNumber = 0;
	for( int i = 0; i < _month; i++)
	{
		dayNumber += getMonthDays(_month , _year);
	}
	dayNumber += _day; 
	
	return dayNumber;
}

const Date& Date::operator++()
{
	if ( _day < getMonthDays( _month, _year ) )
	{
		_day++;
	}
	else
	{
		_day = 1;
		if ( _month == 11 )
		{
			_month = 0;
			_year++;
		}
		else
		{
			_month++;
		}
	}
	return *this;
}

const Date  Date::operator++(int)
{
	Date result(*this);
	++(*this);
	return result;
}

const Date& Date::operator--()
{
		if ( _day > 1 )
	{
		_day--;
	}
	else
	{
		if ( _month == 0 )
		{
			_month = 11;
			_year--;
		}
		else
		{
			_month--;
		}
		_day = getMonthDays(_month, _year);
	}
	return *this;
}

const Date  Date::operator--(int)
{
	Date result(*this);
	--(*this);
	return result;
}

const string Date::getMonthName() const
{
	return monthNames[ _month ];
}

int Date::getMonthDays(int m, int y)
{
	switch ( m )
	{
	case 0:
	case 2:
	case 4:
	case 6:
	case 7:
	case 9:
	case 11:
		return 31;
	case 1:
		if (leapYear( y ))
		{
			return 29;
		}else{
			return 28;
		}
	case 3:
	case 5:
	case 8:
	case 10:
		return 30;
	default:
		return 31;
	}
	
}

void Date::setDefault()
{
	time_t timer; 
	time(&timer);
	struct tm * today = localtime(&timer); 

	defaultDate.setDay(today -> tm_mday) ;
	defaultDate.setMonth(today -> tm_mon) ;
	defaultDate.setDYear(today -> tm_year += 1900) ;
	defaultSet = true;
}

void Date::showDefault()
{
	if ( defaultSet )
	{
		cout << defaultDate << endl;
	}
	else
	{
		cout << "default date is not set" << endl;
	}

	return;
}

const Date Date::getDefault()
{
	return defaultDate;
}

string Date::monthNames [12]= { "Jan", "Feb", "Mar", "Apr", "May" , "Jun" , "Jul" , "Aug" , "Sep" , "Oct" , "Nov", "Dec" };
Date Date::defaultDate = Date(1,1,2000);
bool Date::defaultSet = false;



Date::~Date()
{
	#ifdef NDEBUG
	cout<<": removed "<<*this<<endl;
	#endif
	return;
}
//void Date::fillDate(int d, Month m, int y)
//{
// if (_type==initial)
// setDefault(); 
//#ifndef NDEBUG
// cout<<"Data constructor defaultDate: "<<*this<<endl;
//#endif
//
//}


ostream& operator<<(ostream& os, const Date & d)
{
	os << d.day() << ' ' << d.getMonthName() << ' ' << d.year() << endl;
	return os;
}