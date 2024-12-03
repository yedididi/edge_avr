#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../../driver/fnd/fnd.h"
#include "../../periph/GPIO/GPIO.h"
#include "../../periph/TIM/TIM.h"
#include "../../driver/button/button.h"
#include "../../common/timetick/timetick.h"


void stopwatch_init();
void stopwatch_execute();

enum {STOP, RUN};

button_t runStopBtn;
button_t initBtn;

uint8_t		stopwatchState;
uint16_t	counter;
//uint32_t		timetick;
uint32_t		prevtime;

#endif /* STOPWATCH_H_ */