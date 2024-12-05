#include "timeClock.h"

void incMilisec()
{
	milisec = (milisec + 1) % 1000;
	if (milisec)
	return;
	else
	{
		changeFndColonFlag();
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
	clockState = HOURMIN;
	
	//initTIM0();
	initTIM2();
	Button_init(&changeclockStateBtn, &DDRA, &PINA, 0);
	Button_init(&changeModifyStateBtn, &DDRA, &PINA, 1);
	Button_init(&plusHour, &DDRA, &PINA, 2);
	Button_init(&plusMin, &DDRA, &PINA, 3);
}

void displayHourMin()
{
	uint16_t stopWatchData = 0;
	
	stopWatchData = hour * 100;
	stopWatchData += min;
	FND_setfndData(stopWatchData);
}

void displaySecMilisec()
{
	uint16_t stopWatchData = 0; 
	
	stopWatchData = sec * 100;
	stopWatchData += milisec / 10;
	FND_setfndData(stopWatchData);
	
	//if (milisec < something) changeFndColonFlag();
	//else ;
}

void execute_timeClock()
{
	switch(clockState)
	{
		case HOURMIN:
		if (Button_GetState(&changeclockStateBtn) == ACT_RELEASED)
			clockState = SECMILISEC;
		if (Button_GetState(&changeModifyStateBtn) == ACT_RELEASED)
			clockState = MODIFY;
		break;
		
		case SECMILISEC:
		if (Button_GetState(&changeclockStateBtn) == ACT_RELEASED)
			clockState = HOURMIN;
		break;
		
		case MODIFY:
		if (Button_GetState(&changeModifyStateBtn) == ACT_RELEASED)
			clockState = HOURMIN;
		break;
	}
	
	switch(clockState)
	{
		case HOURMIN:
			displayHourMin();
		break;
		
		case SECMILISEC:
			displaySecMilisec();
		break;
		
		case MODIFY:
		if (Button_GetState(&plusHour) == ACT_RELEASED)
		{
			hour = (hour + 1) % 24;
			displayHourMin();
		}
		if (Button_GetState(&plusMin) == ACT_RELEASED)
		{
			min = (min + 1) % 24;
			displayHourMin();
		}
		break;
	}
}