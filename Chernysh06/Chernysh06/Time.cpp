#include "Time.h"


const double Time::hourToDec = 1./3600;

Time::Time (int s, int m, int h):
	_hours(h),
	_minutes(m),
	_seconds(s)
{
	normalizeTime();
	return;
}

Time::Time (const Time& t):
	_hours(t._hours),
	_minutes(t._minutes),
	_seconds(t._seconds)
{
	return;
}
Time& Time::operator=(const Time& t)
{
	_hours=t._hours;
	_minutes=t._minutes;
	_seconds=t._seconds;
	return *this;
}
void Time::normalizeTime()
{
	_hours+=((_minutes+(_seconds/60))/60);
	_minutes=(_minutes+(_seconds/60))%60; _seconds%=60; 
}
Time::operator int() const
{
	return _hours*3600+_minutes*60+_seconds;
}
Time::operator double() const
{
	return (double) _hours +(double) _minutes/60 +(double) _seconds/3600;
}
const Time& Time::operator++()
{
	_seconds++;
	normalizeTime();
	return *this;
}
const Time Time::operator++(int)
{
	Time result(*this);
	++(*this);
	normalizeTime();
	return result;
}
const Time& Time::operator--()
{
	_seconds--;
	normalizeTime();
	return *this;
}
const Time Time::operator--(int)
{
	Time result(*this);
	--(*this);
	normalizeTime();
	return result;
}
double operator+(const Time& t1, const Time& t2)
{
	return (double) t1  + (double) t2;

}
ostream& operator<<(ostream& os, const Time & t)
{
	os << t.hours() << ':' << t.minutes() << ':' << t.seconds() ;
	return os;
}