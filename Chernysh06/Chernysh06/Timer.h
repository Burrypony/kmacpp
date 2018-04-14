#include "Time.h"
#include "Date.h"
#ifndef _TIMER_H_

#define _TIMER_H_
class Timer 
{
private:
	int getCurrentTime;
public:
	Timer ( Date date, Time time, int interval);
	~Timer(){};
	void MarioSong();
};

#endif