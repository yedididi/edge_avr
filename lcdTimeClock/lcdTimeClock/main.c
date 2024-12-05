#include "ap/lcdTimeClock/lcdTimeClock.h"

ISR(TIMER2_COMP_vect)
{
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

