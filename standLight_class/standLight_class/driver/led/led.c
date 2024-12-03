#include "led.h"

void led_init(volatile uint8_t *DDR)
{
	GPIO_initPort(DDR, OUTPUT);
}

void led_allOff(volatile uint8_t *PORT)
{	
	GPIO_writePort(PORT, 0x00);
}

void led_allOn(volatile uint8_t *PORT)
{
	GPIO_writePort(PORT, 0xff);
}

void led_writeData(volatile uint8_t *PORT, uint8_t data)
{
	GPIO_writePort(PORT, data);
}