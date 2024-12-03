#ifndef LED_H
#define LED_H

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

void turnOFFLight();
void turnTWOLight();
void turnFOURLight();
void turnSIXLight();
void turnEIGHTLight();

#endif