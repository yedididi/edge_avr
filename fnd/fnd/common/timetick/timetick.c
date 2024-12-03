#include "timetick.h"

uint32_t timeTick = 0;

void incTick()
{
	timeTick++;
}

void initTick()
{
	timeTick = 0;
}

uint32_t getTick()
{
	return (timeTick);
}

void setTick(uint32_t tick)
{
	timeTick = tick;
}