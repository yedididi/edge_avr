#ifndef TIMETICK_H_
#define TIMETICK_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void incTick();
void initTick();
uint32_t getTick();
void setTick(uint32_t tick);

#endif /* TIMETICK_H_ */