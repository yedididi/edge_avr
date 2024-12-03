#ifndef LED_H_
#define LED_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#define  LED_DDR	DDRD
#define	LED_PORT	PORTD

enum{LED1, LED2, LED3, LED4};
	
uint8_t ledData;	

void Led1_blink();
void Led2_blink();
void Led3_blink();
void Led4_blink();

#endif /* LED_H_ */