#include "./IncFile1.h"

void buttonInit(button_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
	btn->DDR = ddr;
	btn->PIN = pin;
	btn->pinNum = pinNum;
	btn->prevState = RELEASED;
	*btn->DDR &= (1<<btn->pinNum);
}

uint8_t buttonGetState(button_t *btn)
{
	uint8_t	curState = *btn->PIN & (1<<btn->pinNum); //0번핀의 값 저장
	
	if ((curState == PUSHED) && (btn->prevState == RELEASED))
	{
		_delay_ms(10);
		btn->prevState = PUSHED;
		return (ACT_PUSHED);
	}
	else if ((curState != PUSHED) && (btn->prevState == PUSHED))
	{
		_delay_ms(10);
		btn->prevState = RELEASED;
		return (ACT_RELEASED);
	}
	else
	return (ACT_NONE);
}