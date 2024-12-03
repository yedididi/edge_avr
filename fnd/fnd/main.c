#include "ap/stopwatch/stopwatch.h"

int main(void)
{
	stopwatch_init();
	while (1)
	{
		stopwatch_execute();
	}
}

