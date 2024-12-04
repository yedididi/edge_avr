#include "stopwatch.h"

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

void stopwatch_init()
{
	FND_init();
	
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
	prevtime = 0;
	stopWatchState = RUN;
	
	//initTIM0();
	initTIM2();
	Button_init(&runStopBtn, &DDRA, &PINA, 0);
	Button_init(&initBtn, &DDRA, &PINA, 1);
}

void displayTime()
{
	uint16_t stopWatchData = 0;
	
	stopWatchData = (min % 10) * 1000;
	stopWatchData += sec * 10;
	stopWatchData += (milisec / 100) % 10;
	FND_setfndData(stopWatchData);
}

void stopwatch_execute()
{
	switch (stopWatchState)
	{
		case (RUN):
		if (Button_GetState(&runStopBtn) == ACT_RELEASED)
		stopWatchState = STOP;
		break;
		
		case (STOP):
		if (Button_GetState(&runStopBtn) == ACT_RELEASED)
		stopWatchState = RUN;
		if (Button_GetState(&initBtn) == ACT_RELEASED)
		{
			stopWatchState = STOP;
			milisec = 0;
			sec = 0;
			min = 0;
			hour = 0;
			displayTime();
		}
		break;
	}
	
	switch (stopWatchState)
	{
		case (RUN):
		if (getTick() - prevtime >= 1)
		{
			prevtime = getTick();
			incMilisec();
			displayTime();
		}
		break;
		
		case (STOP):
		break;
	}
}