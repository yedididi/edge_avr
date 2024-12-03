#include "led.h"

void Led1_blink()
{
	ledData ^= 0x01;
	LED_PORT = ledData;
}

void Led2_blink()
{
	ledData ^= 0x02;
	LED_PORT = ledData;
}

void Led3_blink()
{
	ledData ^= 0x04;
	LED_PORT = ledData;
}
void Led4_blink()
{
	ledData ^= 0x08;
	LED_PORT = ledData;

}