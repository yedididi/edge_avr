#include "standLight.h"

void standLightInit()
{
	standLightState = MODE1;
	Button_init(&nextBtn, &DDRA, &PINA, 0);
	Button_init(&offBtn, &DDRA, &PINA, 1);
	led_init(&DDRD);
}

void standLightEventCheck()
{
	if (Button_GetState(&nextBtn) == ACT_RELEASED)
		standLightState = (standLightState + 1) % 5;
	if (Button_GetState(&offBtn) == ACT_RELEASED)
		standLightState = LED_OFF;
	
	//switch(standLightState)
	//{
		//case LED_OFF:
		//if (Button_GetState((&nextBtn)) == ACT_RELEASED)
			//standLightState = MODE1;
		//else if (Button_GetState((&offBtn)) == ACT_RELEASED)
			//standLightState = LED_OFF;
		//break;
	//
		//case MODE1:
		//if (Button_GetState((&nextBtn)) == ACT_RELEASED)
			//standLightState = MODE2;
		//else if (Button_GetState((&offBtn)) == ACT_RELEASED)
			//standLightState = LED_OFF;
		//break;
		//
		//case MODE2:
		//if (Button_GetState((&nextBtn)) == ACT_RELEASED)
			//standLightState = MODE3;
		//else if (Button_GetState((&offBtn)) == ACT_RELEASED)
			//standLightState = LED_OFF;
		//break;
		//
		//case MODE3:
		//if (Button_GetState((&nextBtn)) == ACT_RELEASED)
			//standLightState = MODE4;
		//else if (Button_GetState((&offBtn)) == ACT_RELEASED)
			//standLightState = LED_OFF;
		//break;
		//
		//case MODE4:
		//if (Button_GetState((&nextBtn)) == ACT_RELEASED)
			//standLightState = LED_OFF;
		//else if (Button_GetState((&offBtn)) == ACT_RELEASED)
			//standLightState = LED_OFF;
		//break;
	//}
	
}

void standLightExecute()
{
	switch(standLightState)
	{
		case LED_OFF:
		standLightALLOFF();
		break;
		
		case MODE1:
		standLightMODE1();
		break;
		
		case MODE2:
		standLightMODE2();
		break;
		
		case MODE3:
		standLightMODE3();
		break;
		
		case MODE4:
		standLightMODE4();
		break;
	}
}

void standLightRun()
{
	
	//event check
	standLightEventCheck();
	//execute
	standLightExecute();
}

void standLightALLOFF()
{
	led_allOff(&PORTD);
}

void standLightMODE1()
{
	led_writeData(&PORTD, 0b00000011);
}

void standLightMODE2()
{
	led_writeData(&PORTD, 0b00001111);
}

void standLightMODE3()
{
	led_writeData(&PORTD, 0b00111111);
}

void standLightMODE4()
{
	led_writeData(&PORTD, 0b11111111);
}