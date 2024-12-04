#include "stopwatch_.h"

void stopwatch__init()
{
	FND_init();
	counter = 0;
	stopwatchState = STOP;
	prevtime = 0;
	
	initTIM0();
	initTIM2();
	//global interrupt enable 설정
	sei();
	
	Button_init(&runStopBtn, &DDRA, &PINA, 0);
	Button_init(&initBtn, &DDRA, &PINA, 1);
}

void stopwatch__execute()
{
	switch (stopwatchState)
	{
		case STOP:
		if (Button_GetState(&runStopBtn) == ACT_RELEASED)
			stopwatchState = RUN;
		if (Button_GetState(&initBtn) == ACT_RELEASED)
		{
			stopwatchState = STOP;
			counter = 0;
			FND_setfndData(counter);
		}
		break;
		
		case RUN:
		if (Button_GetState(&runStopBtn) == ACT_RELEASED)
			stopwatchState = STOP;
		break;
	}
	
	
	
	switch (stopwatchState)
	{
		case STOP:
		FND_setfndData(counter);
		break;
		
		case RUN:
		if (getTick() - prevtime >= 1000)
		{
			prevtime = getTick();
			FND_setfndData(++counter);
		}
		break;
	}
}