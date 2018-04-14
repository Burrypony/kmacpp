#include "Time.h"
#include "Date.h"
#include "Timer.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

Timer::Timer(Date date , Time alarmTime, int interval )
{
	int daysNumber = 0 ;
	int secondsNumber = 0;
	Date currentDate;
	Time currentTime;
	Date::setDefault();

	
	currentDate = Date::getDefault();
	// cout << "Timer constructor" << endl;
	// cout << "Current date: " << currentDate << " " << currentDate.getDayNumber() << " day of the year" << endl;
	// cout << "Alarm date: " << date << " " << date.getDayNumber() << " day of the year" << endl;

	if ( currentDate.year() > date.year() )
	{
		throw invalid_argument( "Alarm cannot be set in the past" );
	}

	if ( currentDate.year() == date.year() )
	{
		daysNumber = date.getDayNumber() - currentDate.getDayNumber();
	}
	else
	{

		if ( currentDate.leapYear( currentDate.year() ) )
		{
			daysNumber = 365 - currentDate.getDayNumber();
		}
		else
		{
			daysNumber = 364 - currentDate.getDayNumber();
		}

		for ( int i = currentDate.year() + 1; i < date.year(); i++ )
		{
			if ( currentDate.leapYear( i ) )
			{
				daysNumber += 365;
			}
			else
			{
				daysNumber += 364;
			}
		}

		daysNumber += date.getDayNumber();
	}

	if ( daysNumber < 0 )
	{
		throw invalid_argument( "Alarm cannot be set in the past" );
	}
	cout << daysNumber << endl;

	time_t ctimer; 
	time(&ctimer);
	struct tm * today = localtime(&ctimer); 

	currentTime = Time( today->tm_sec, today->tm_min, today->tm_hour);

	// cout << "Current time: " << currentTime << endl;

	secondsNumber = daysNumber*24*3600;
	secondsNumber += (int) alarmTime;
	secondsNumber -= (int) currentTime;

	if ( secondsNumber < 0 )
	{
		throw invalid_argument( "Alarm cannot be set in the past" );
	}

	cout << "Alarm will go in " << secondsNumber << " seconds" << endl;

	Sleep( secondsNumber * 1000 );
	cout << "Alarm has been activated!" << endl;
	for ( int i=0; i < interval; i++ )
	{
		Beep( 500, 300 );
		Sleep( 700 );
	}
	cout << "Alarm has been defused!" << endl;
	//MarioSong(); 

}
void Timer::MarioSong()
{
	     Beep (330,100);Sleep(100);
        Beep (330,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (330,100);Sleep(300);
        Beep (392,100);Sleep(700);
        Beep (196,100);Sleep(700);
        Beep (262,300);Sleep(300);
        Beep (196,300);Sleep(300);
        Beep (164,300);Sleep(300);
        Beep (220,300);Sleep(100);
        Beep (246,100);Sleep(300);
        Beep (233,200);
        Beep (220,100);Sleep(300);
        Beep (196,100);Sleep(150);
        Beep (330,100);Sleep(150);
        Beep (392,100);Sleep(150);
        Beep (440,100);Sleep(300);
        Beep (349,100);Sleep(100);
        Beep (392,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(100);
        Beep (247,100);Sleep(500);
        Beep (262,300);Sleep(300);
        Beep (196,300);Sleep(300);
        Beep (164,300);Sleep(300);
        Beep (220,300);Sleep(100);
        Beep (246,100);Sleep(300);
        Beep (233,200);
        Beep (220,100);Sleep(300);
        Beep (196,100);Sleep(150);
        Beep (330,100);Sleep(150);
        Beep (392,100);Sleep(150);
        Beep (440,100);Sleep(300);
        Beep (349,100);Sleep(100);
        Beep (392,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(100);
        Beep (247,100);Sleep(900);
        Beep (392,100);Sleep(100);
        Beep (370,100);Sleep(100);
        Beep (349,100);Sleep(100);
        Beep (311,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (207,100);Sleep(100);
        Beep (220,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (220,100);Sleep(100);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(500);
        Beep (392,100);Sleep(100);
        Beep (370,100);Sleep(100);
        Beep (349,100);Sleep(100);
        Beep (311,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (523,100);Sleep(300);
        Beep (523,100);Sleep(100);
        Beep (523,100);Sleep(1100);
        Beep (392,100);Sleep(100);
        Beep (370,100);Sleep(100);
        Beep (349,100);Sleep(100);
        Beep (311,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (207,100);Sleep(100);
        Beep (220,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (220,100);Sleep(100);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(500);
        Beep (311,300);Sleep(300);
        Beep (296,300);Sleep(300);
        Beep (262,300);Sleep(1300);
        Beep (262,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(300);
        Beep (330,200);Sleep(50);
        Beep (262,200);Sleep(50);
        Beep (220,200);Sleep(50);
        Beep (196,100);Sleep(700);
        Beep (262,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(100);
        Beep (330,100);Sleep(700);
        Beep (440,100);Sleep(300);
        Beep (392,100);Sleep(500);
        Beep (262,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(300);
        Beep (330,200);Sleep(50);
        Beep (262,200);Sleep(50);
        Beep (220,200);Sleep(50);
        Beep (196,100);Sleep(700);
}