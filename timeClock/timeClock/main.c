#include "ap/timeClock/timeClock.h"

ISR(TIMER2_COMP_vect)
{
	FND_ISR_Process();
	incMilisec();
}

int main(void)
{
	init_timeClock();
	sei();
    while (1) 
    {
		execute_timeClock();
    }
}

