#ifndef LED_H_
#define LED_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>
#include "../Button/IncFile1.h"

#define LED_DDR		DDRD
#define LED_PORT	PORTD

void led1Blink();
void led2Blink();
void led3Blink();
void led4Blink();
void led_allOn();
void led_allOff();
void Led_init();
void Led_writeData(uint8_t Data);

#endif /* LED_H_ */