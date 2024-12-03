#ifndef LED_H
#define LED_H

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "../../periph/GPIO/GPIO.h"

void led_init(volatile uint8_t *DDR);
void led_allOff(volatile uint8_t *PORT);
void led_allOn(volatile uint8_t *PORT);
void led_writeData(volatile uint8_t *PORT, uint8_t data);

#endif