#ifndef NEWTIMECLOCK_H_
#define NEWTIMECLOCK_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../../driver/fnd/fnd.h"
#include "../../driver/button/button.h"
#include "../../periph/GPIO/GPIO.h"
#include "../../periph/TIM/TIM.h"

void execute_timeClock();
void init_timeClock();
void incMilisec();
void displayHourMin();
void displaySecMilisec();

enum {HOURMIN, SECMILISEC, MODIFY};

uint32_t	milisec;
uint8_t		sec, min, hour;
uint8_t		clockState;
button_t	changeclockStateBtn, changeModifyStateBtn, plusHour, plusMin;

#endif /* NEWTIMECLOCK_H_ */