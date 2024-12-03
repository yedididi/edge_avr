#include "LED.h"

void Led_writeData(uint8_t Data)
{
	LED_PORT = Data;
}

void Led_init()
{
	LED_DDR = 0xff;
}

void led_allOff()
{
	LED_DDR = 0x00;
}

void led_allOn()
{
	LED_DDR = 0xff;
}

void led1Blink()
{
	ledData ^= 0x01;
	//LED_PORT = ledData;
	Led_writeData(ledData);
}

void led2Blink()
{
	ledData ^= 0x02;
	//LED_PORT = ledData;
	Led_writeData(ledData);
}


void led3Blink()
{
	ledData ^= 0x04;
	//LED_PORT = ledData;
	Led_writeData(ledData);
}

void led4Blink()
{
	ledData ^= 0x08;
	//LED_PORT = ledData;
	Led_writeData(ledData);
}