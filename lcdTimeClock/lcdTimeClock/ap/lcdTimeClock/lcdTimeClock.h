#ifndef LCDTIMECLOCK_H_
#define LCDTIMECLOCK_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "../../driver/LCD/LCD.h"
#include "../../driver/button/button.h"
#include "../../periph/GPIO/GPIO.h"
#include "../../periph/TIM/TIM.h"

void execute_timeClock();
void init_timeClock();
void incMilisec();
void displayClock(int row, int col);

enum {CLOCK, MODIFY};

uint32_t	milisec;
uint8_t		sec, min, hour;
uint8_t		clockState;
button_t	changeStateBtn, plusHour, plusMin, plusSec;
uint8_t		backupHour ,backupMin ,backupSec;

#endif /* LCDTIMECLOCK_H_ */