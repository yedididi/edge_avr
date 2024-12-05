#include "LCD.h"

void GPIO_writeControlData(uint8_t data)
{
	LCD_CONTROL_PORT = data;
}

void GPIO_writeData(uint8_t data)
{
	LCD_DATA_PORT = data;
}

void GPIO_init()
{
	LCD_CONTROL_DDR |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_E);
	LCD_DATA_DDR |= 0xff;
}

void LCD_init()
{
	GPIO_init();
	
	_delay_ms(15);
	//function set: 0 0 1 DL=1 N=1 F=0 0 0  -> 0x38
	LCD_writeCmdData(0x38);
	_delay_ms(5);
	//function set: 0 0 1 DL=1 N=1 F=0 0 0  -> 0x38
	LCD_writeCmdData(0x38);
	_delay_ms(1);
	//function set: 0 0 1 DL=1 N=1 F=0 0 0  -> 0x38
	LCD_writeCmdData(0x38);
	//function set: 0 0 1 DL=1 N=1 F=0 0 0  -> 0x38
	LCD_writeCmdData(0x38);
	//LCD_DISPLAY_OFF
	LCD_writeCmdData(0x08);
	//LCD_DISPLAY_CLEAR
	LCD_writeCmdData(0x01);
	//ENTRY_MODE_SET
	LCD_writeCmdData(0x06);
	
	//LCD_DISPLAY_ON
	LCD_writeCmdData(0x0C);
}

void LCD_cmdMode()
{
	//RS -> low
	lcdControlData &= ~(1 << LCD_RS);
	GPIO_writeControlData(lcdControlData);
}
void LCD_charMode()
{
	//RS -> high
	lcdControlData |= (1 << LCD_RS);
	GPIO_writeControlData(lcdControlData);
}

void LCD_writeMode()
{
	//RW -> low
	lcdControlData &= ~(1 << LCD_RW);
	GPIO_writeControlData(lcdControlData);
}

void LCD_enableHigh()
{
	lcdControlData |= (1 << LCD_E);
	GPIO_writeControlData(lcdControlData);
	_delay_ms(1);
}

void LCD_enableLow()
{
	lcdControlData &= ~(1 << LCD_E);
	GPIO_writeControlData(lcdControlData);
	_delay_ms(1);
}

void LCD_writeByte(uint8_t data)
{
	GPIO_writeData(data);
}

void LCD_writeCmdData(uint8_t data)
{
	//lcd 내부 명령어 동작에 대한 함수
	LCD_cmdMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data);
	LCD_enableLow();
}

void LCD_writeCharData(uint8_t data)
{
	//lcd char 쓰는 동작
	LCD_charMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data);
	LCD_enableLow();
}

void LCD_writeString(const char *str)
{
	for (int i = 0; str[i]; i++)
	LCD_writeCharData(str[i]);
}

void LCD_goToXY(uint8_t row, uint8_t col)
{
	col %= 16, row %= 2;
	uint8_t lcdRegisterAddress = (0x40 * row) + col;
	uint8_t command = 0x80 + lcdRegisterAddress;
	LCD_writeCmdData(command);
}

void LCD_writeStringXY(uint8_t row, uint8_t col, const char *str)
{
	LCD_goToXY(row, col);
	LCD_writeString(str);
}