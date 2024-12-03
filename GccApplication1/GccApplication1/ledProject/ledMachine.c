#include "ledMachine.h"

void executeLedMachine(uint8_t ledState, button_t *btnPrev, button_t *btnNext)
{
	switch(ledState)
	{
		case LED1 :
		Led1_blink();
		if(Button_GetState(btnNext) == ACT_RELEASED)
		{
			ledState = LED2;
			ledData=0x00;
		}
		else if(Button_GetState(btnPrev) == ACT_RELEASED)
		{
			ledState = LED4;
			ledData=0x00;
		}
		break;
		case LED2 :
		Led2_blink();
		if(Button_GetState(btnNext) == ACT_RELEASED)
		{
			ledState = LED3;
			ledData=0x00;
		}
		else if(Button_GetState(btnPrev) == ACT_RELEASED)
		{
			ledState = LED1;
			ledData=0x00;
		}
		break;
		case LED3 :
		Led3_blink();
		if(Button_GetState(btnNext) == ACT_RELEASED)
		{
			ledState = LED4;
			ledData=0x00;
		}
		else if(Button_GetState(btnPrev) == ACT_RELEASED)
		{
			ledState = LED2;
			ledData=0x00;
		}
		break;
		case LED4 :
		Led4_blink();
		if(Button_GetState(btnNext) == ACT_RELEASED)
		{
			ledState = LED1;
			ledData=0x00;
		}
		else if(Button_GetState(btnPrev) == ACT_RELEASED)
		{
			ledState = LED3;
			ledData=0x00;
		}
		break;
	}
	_delay_ms(200);
}