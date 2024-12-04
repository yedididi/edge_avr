#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include "../../driver/fnd/fnd.h"
#include "../../periph/GPIO/GPIO.h"
#include "../../periph/TIM/TIM.h"
#include "../../driver/button/button.h"
#include "../../common/timetick/timetick.h"

void stopwatch_init();
void stopwatch_execute();
void incMilisec();

enum {STOP, RUN};

uint8_t		stopWatchState;
uint32_t	milisec;
uint32_t		prevtime;
uint8_t		sec, min, hour;
button_t	runStopBtn, initBtn;

#endif /* STOPWATCH_H_ */