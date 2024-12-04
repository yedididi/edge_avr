#ifndef TIMECLOCK_H_
#define TIMECLOCK_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../../driver/fnd/fnd.h"
#include "../../periph/GPIO/GPIO.h"
#include "../../periph/TIM/TIM.h"

void execute_timeClock();
void init_timeClock();
void incMilisec();
void displayTime();

uint32_t	milisec;
uint8_t		sec, min, hour;

#endif