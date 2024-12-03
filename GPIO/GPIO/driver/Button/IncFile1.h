#ifndef INCFILE1_H_
#define INCFILE1_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>

#define BUTTON_DDR	DDRA
#define BUTTON_PIN	PINA
#define BUTTON_NEXT	0
#define BUTTON_PREV 1

enum {LED1,LED2,LED3,LED4};
enum {PUSHED, RELEASED};
enum {ACT_NONE, ACT_PUSHED, ACT_RELEASED};

typedef struct button_s
{
	volatile uint8_t *DDR;	//port
	volatile uint8_t *PIN;	//pin
	uint8_t pinNum;		//static
	uint8_t prevState;
} button_t;

void buttonInit(button_t *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t buttonGetState(button_t *btn);

uint8_t ledData;

#endif /* LEDMACHINE_H_ */