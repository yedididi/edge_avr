#include "timeClock.h"

void incMilisec()
{
	milisec = (milisec + 1) % 1000;
	if (milisec)
	return;
	else
	{
		sec = (sec + 1) % 60;
		if (sec)
		return;
		else
		{
			min = (min + 1) % 60;
			if (min)
			return ;
			else
			hour = (hour + 1) % 24;
		}
	}
}

void init_timeClock()
{
	FND_init();
	
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
	
	//initTIM0();
	initTIM2();
}

void displayTime()
{
	uint16_t stopWatchData = 0;
	
	stopWatchData = min * 100;
	stopWatchData += sec;
	FND_setfndData(stopWatchData);
}

void execute_timeClock()
{
	displayTime();
}