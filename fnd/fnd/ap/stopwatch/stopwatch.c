#include "stopwatch.h"

//어떤 조건에 의한 ISR인지 명시해야함
ISR(TIMER0_OVF_vect) //timer overflow에 대한 ISR이라는 뜻
{
	FND_ISR_Process();
	TCNT0 = 130; //이 설정을 줬으니까 1ms 주기마다 인터럽트 발생
	incTick();
}

void stopwatch_init()
{
	FND_init();
	counter = 0;
	stopwatchState = STOP;
	//timetick = 0;
	prevtime = 0;
	
	initTIM0();
	//global interrupt enable 설정
	sei();
	
	Button_init(&runStopBtn, &DDRA, &PINA, 0);
	Button_init(&initBtn, &DDRA, &PINA, 1);
}

void stopwatch_execute()
{
	if (Button_GetState(&runStopBtn) == ACT_RELEASED)
		stopwatchState = (stopwatchState + 1) % 2;
	if (Button_GetState(&initBtn) == ACT_RELEASED)
	{
		stopwatchState = STOP;
		counter = 0;
		FND_setfndData(counter);
	}
	
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
		//FND_setfndData(counter++);
		if (getTick() - prevtime >= 1000)
		{
			prevtime = getTick();
			FND_setfndData(++counter);
		}
		//_delay_ms(1000);
		break;
	}
}