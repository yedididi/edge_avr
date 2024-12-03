#ifndef EXECUTELIGHT_H
#define EXECUTELIGHT_H

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "../../driver/button/button.h"

button_t nextLevelbtn;
button_t offBtn;

enum light {OFF, TWO, FOUR, SIX, EIGHT};

uint8_t lightState;


#endif