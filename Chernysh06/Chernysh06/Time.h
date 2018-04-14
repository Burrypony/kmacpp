#include <iostream>
#ifndef _TIME_H_

#define _TIME_H_
using namespace std;
//---------------------------------------

//1. Реалізувати клас Time

//

//2. Реалізувати таймер, який вмикається

//вибраного дня (клас Date) в заданий час

//і подає сигнал через заданий інтервал

//часу після вмикання

//---------------------------------------

class Time

{

private:

int _hours;

int _minutes;

int _seconds;

//Функція службова, а тому закрита

void normalizeTime();


public:

static const double hourToDec;

Time (int s=0, int m=0, int h=0);

Time (const Time&);

~Time(){};


Time& operator=(const Time&);

operator int() const;

operator double() const;


int hours() const {return _hours;}

int minutes() const {return _minutes;}

int seconds() const {return _seconds;}


int& hours() {return _hours;}

int& minutes() {return _minutes;}

int& seconds() {return _seconds;}


//Зміна часового проміжку на одну секунду

const Time& operator++();

const Time operator++(int);

const Time& operator--();

const Time operator--(int);

};

//Додавання часових проміжків

double operator+(const Time&, const Time&) ;


ostream& operator<<(ostream&, const Time &);

#endif