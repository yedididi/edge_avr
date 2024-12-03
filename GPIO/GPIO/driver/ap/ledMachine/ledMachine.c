#include "./ledMachine.h"

void ledMachine_execute(uint8_t ledState, button_t *btnPrev, button_t *btnNext)
{
	if (ledState == LED1)
	{
		led1Blink();
		if (buttonGetState(btnNext) == ACT_RELEASED) //뗄 때 동작을 하겠다
		{
			ledState = LED2;
			ledData = 0x00;
		}
		else if (buttonGetState(btnPrev) == ACT_RELEASED)
		{
			ledState = LED4;
			ledData = 0x00;
		}
	}
	else if (ledState == LED2)
	{
		led2Blink();
		if (buttonGetState(btnNext) == ACT_RELEASED)
		{
			ledState = LED3;
			ledData = 0x00;
		}
		else if (buttonGetState(btnPrev) == ACT_RELEASED)
		{
			ledState = LED1;
			ledData = 0x00;
		}
	}
	else if (ledState == LED3)
	{
		led3Blink();
		if (buttonGetState(btnNext) == ACT_RELEASED)
		{
			ledState = LED4;
			ledData = 0x00;
		}
		else if (buttonGetState(btnPrev) == ACT_RELEASED)
		{
			ledState = LED2;
			ledData = 0x00;
		}
	}
	else if (ledState == LED4)
	{
		led4Blink();
		if (buttonGetState(btnNext) == ACT_RELEASED)
		{
			ledState = LED1;
			ledData = 0x00;
		}
		else if (buttonGetState(btnPrev) == ACT_RELEASED)
		{
			ledState = LED3;
			ledData = 0x00;
		}
	}
	_delay_ms(400);
}