﻿#ifndef TIM_H_
#define TIM_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void initTIM0();
void initTIM2();

#endif /* TIM_H_ */