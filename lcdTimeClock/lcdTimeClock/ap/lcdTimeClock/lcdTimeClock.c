#include "lcdTimeClock.h"

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
	LCD_init();
	
	milisec = 0;
	sec = 0;
	min = 0;
	hour = 0;
	clockState = CLOCK;
	
	//initTIM0();
	initTIM2();
	Button_init(&changeStateBtn, &DDRA, &PINA, 0);
	Button_init(&plusHour, &DDRA, &PINA, 1);
	Button_init(&plusMin, &DDRA, &PINA, 2);
	Button_init(&plusSec, &DDRA, &PINA, 3);
}

void displayClock(int row, int col)
{
	char buff[30];
	
	if (sec < 10)
		sprintf(buff, "%d:%d:0%d", hour, min, sec);
	else
		sprintf(buff, "%d:%d:%d", hour, min, sec);
	LCD_writeStringXY(row, col, buff);
}

void modifyMode()
{
	if (Button_GetState(&plusHour) == ACT_RELEASED)
		backupHour = (backupHour + 1) % 24;
	if (Button_GetState(&plusMin) == ACT_RELEASED)
		backupMin = (backupMin + 1) % 24;
	if (Button_GetState(&plusSec) == ACT_RELEASED)
		backupSec = (backupSec + 1) % 60;
	
	hour = backupHour;
	min = backupMin;
	sec = backupSec; 
	
	LCD_writeStringXY(0, 3, "Modify mode");
	displayClock(1, 5);
}

void execute_timeClock()
{
	switch(clockState)
	{
		case CLOCK:
		if (Button_GetState(&changeStateBtn) == ACT_RELEASED)
		{
			clockState = MODIFY;
			backupHour = hour;
			backupMin = min;
			backupSec = sec;
		}
		break;
		
		case MODIFY:
		if (Button_GetState(&changeStateBtn) == ACT_RELEASED)
		{
			clockState = CLOCK;
			LCD_writeCmdData(LCD_DISPLAY_CLEAR);
		}
		break;
	}
	
	switch(clockState)
	{
		case CLOCK:
		displayClock(0, 5);
		break;
		
		case MODIFY:
		modifyMode();
		break;
	}
}