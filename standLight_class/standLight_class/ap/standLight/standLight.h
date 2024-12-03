#ifndef STANDLIGHT_H_
#define STANDLIGHT_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "../../periph/GPIO/GPIO.h"
#include "../../driver/button/button.h"
#include "../../driver/led/led.h"

enum {LED_OFF, MODE1, MODE2, MODE3, MODE4};
	
uint8_t  standLightState;
button_t nextBtn;
button_t offBtn;

void standLightInit();
void standLightRun();
void standLightEventCheck();
void standLightExecute();
void standLightALLOFF();
void standLightMODE1();
void standLightMODE2();
void standLightMODE3();
void standLightMODE4();

#endif /* STANDLIGHT_H_ */