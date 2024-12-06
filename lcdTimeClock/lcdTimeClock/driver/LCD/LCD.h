#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "../../periph/GPIO/GPIO.h"

#define LCD_CONTROL_DDR		DDRB
#define LCD_DATA_DDR		DDRC
#define LCD_CONTROL_PORT	PORTB
#define LCD_DATA_PORT		PORTC
#define LCD_RS				5
#define LCD_RW				6
#define LCD_E				7
#define LCD_FUNCTION_SET    0x38
#define LCD_DISPLAY_OFF		0x08 //화면을 잠시 끈다, 즉 문자는 화면 다시 키면 남아있음
#define LCD_DISPLAY_CLEAR	0x01 //문자를 다 날린다
#define LCD_ENTRY_MODE_SET	0x06
#define LCD_DISPLAY_ON		0x0C

uint8_t lcdControlData;

void GPIO_writeControlData(uint8_t data);
void GPIO_writeData(uint8_t data);
void GPIO_init();
void LCD_init();
void LCD_cmdMode();
void LCD_charMode();
void LCD_writeMode();
void LCD_enableHigh();
void LCD_enableLow();
void LCD_writeByte(uint8_t data);
void LCD_writeCmdData(uint8_t data);
void LCD_writeCharData(uint8_t data);
void LCD_writeString(const char *str);
void LCD_goToXY(uint8_t row, uint8_t col);
void LCD_writeStringXY(uint8_t row, uint8_t col, const char *str);

#endif /* LCD_H_ */