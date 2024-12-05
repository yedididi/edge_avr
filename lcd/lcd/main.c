#include <stdio.h>

#include "driver/LCD/LCD.h"

int main(void)
{
	LCD_init();
	
	char buff[30];
	uint16_t counter = 0;
	
    while (1) 
    {
		sprintf(buff, "counter: %d", counter++);	
		LCD_writeStringXY(0, 3, buff);
		_delay_ms(1000);
	}
}

