#include "button.h"
#include "led.h"
#include "ledMachine.h"

int main(void)
{
	LED_DDR = 0xff;
	//BUTTON_DDR &= ~((1<<0) | (1<<1));

	ledData = 0x01;
	uint8_t ledState = LED1;
	
	button_t btnNext, btnPrev;				//구조체 변수 선언
	Button_init(&btnNext, &DDRA, &PINA, 0);
	Button_init(&btnPrev, &DDRA, &PINA, 1);
	
	while (1)
	{
		//executeLedMachine(ledState, &btnPrev, &btnNext);
		
		switch(ledState)
		{
			case LED1 :
			Led1_blink();
			if(Button_GetState(&btnNext) == ACT_RELEASED)
			{
				ledState = LED2;
				ledData=0x00;
			}
			else if(Button_GetState(&btnPrev) == ACT_RELEASED)
			{
				ledState = LED4;
				ledData=0x00;
			}
			break;
			case LED2 :
			Led2_blink();
			if(Button_GetState(&btnNext) == ACT_RELEASED)
			{
				ledState = LED3;
				ledData=0x00;
			}
			else if(Button_GetState(&btnPrev) == ACT_RELEASED)
			{
				ledState = LED1;
				ledData=0x00;
			}
			break;
			case LED3 :
			Led3_blink();
			if(Button_GetState(&btnNext) == ACT_RELEASED)
			{
				ledState = LED4;
				ledData=0x00;
			}
			else if(Button_GetState(&btnPrev) == ACT_RELEASED)
			{
				ledState = LED2;
				ledData=0x00;
			}
			break;
			case LED4 :
			Led4_blink();
			if(Button_GetState(&btnNext) == ACT_RELEASED)
			{
				ledState = LED1;
				ledData=0x00;
			}
			else if(Button_GetState(&btnPrev) == ACT_RELEASED)
			{
				ledState = LED3;
				ledData=0x00;
			}
			break;
		}
		_delay_ms(200);
	}

}
