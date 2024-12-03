#include "GPIO.h"

//init - port (8EA or 5EA)
void GPIO_initPort(volatile uint8_t *DDR, uint8_t dir)
{
	if (dir == OUTPUT)
		*DDR = 0xff;
	else
		*DDR = 0x00;	
}

//init - pin (1EA)
void GPIO_initPin(volatile uint8_t *DDR, uint8_t dir, uint8_t pinNum)
{
	if (dir == OUTPUT)
		*DDR |= (1 << pinNum); //no ~?
	else
		*DDR &= ~(1 << pinNum);
}

//output - port (8EA or 5EA) 
void GPIO_writePort(volatile uint8_t *PORT, uint8_t data)
{
	*PORT = data;
}

//output - pin (1EA)
void GPIO_writePin(volatile uint8_t *PORT, uint8_t state, uint8_t pinNum)
{
	if (state == GPIO_SET)
		*PORT |= (1 << pinNum);
	else
		*PORT &= ~(1 << pinNum);
}

//input - port (8EA or 5EA)
uint8_t GPIO_readPort(volatile uint8_t *PIN)
{
	return (*PIN);
}

//input - pin (1EA)
uint8_t GPIO_readPin(volatile uint8_t *PIN, uint8_t pinNum)
{
	return ((*PIN & (1 << pinNum)) != 0);
}