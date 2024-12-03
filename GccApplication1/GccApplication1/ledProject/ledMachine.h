#ifndef LEDMACHINE_H_
#define LEDMACHINE_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "button.h"
#include "led.h"

void executeLedMachine(uint8_t ledState, button_t *btnPrev, button_t *btnNext);

#endif /* LEDMACHINE_H_ */