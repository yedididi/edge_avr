#include "led.h"

void turnOFFLight()
{
	PORTD = 0b00000000;
}

void turnTWOLight()
{
	PORTD = 0b00000011;
}

void turnFOURLight()
{
	PORTD = 0b00001111;
}

void turnSIXLight()
{
	PORTD = 0b00111111;
}

void turnEIGHTLight()
{
	PORTD = 0b11111111;
}