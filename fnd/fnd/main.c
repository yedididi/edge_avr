#include "ap/stopwatch/stopwatch.h"

//어떤 조건에 의한 ISR인지 명시해야함
ISR(TIMER0_OVF_vect) //timer overflow에 대한 ISR이라는 뜻
{
	FND_ISR_Process();
	TCNT0 = 131; //이 설정을 줬으니까 1ms 주기마다 인터럽트 발생
	incTick();
}

ISR(TIMER2_COMP_vect)
{
	FND_ISR_Process();
	incTick();
}

int main(void)
{
	stopwatch_init();
	
	//global interrupt enable 설정
	sei();
	while (1)
	{
		stopwatch_execute();
	}
}

