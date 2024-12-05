#ifndef GPIO_H_
#define GPIO_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

void GPIO_initPort(volatile uint8_t *DDR, uint8_t dir);
void GPIO_initPin(volatile uint8_t *DDR, uint8_t dir, uint8_t pinNum);
void GPIO_writePort(volatile uint8_t *PORT, uint8_t data);
void GPIO_writePin(volatile uint8_t *PORT, uint8_t state, uint8_t pinNum);
uint8_t GPIO_readPort(volatile uint8_t *PIN);
uint8_t GPIO_readPin(volatile uint8_t *PIN, uint8_t pinNum);

enum dir {INPUT, OUTPUT};
enum gpioState {GPIO_RESET, GPIO_SET};

#endif /* GPIO_H_ */