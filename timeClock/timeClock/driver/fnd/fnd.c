#include "fnd.h"

uint16_t data = 0;
uint8_t fndColonFlag = 0;

void FND_init()
{
	FND_NUM_DDR = 0xff;
	FND_DIGIT_DDR = 0xff;
}

void showNum(uint16_t num)
{
	uint8_t fndFont[11] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67, 0x80};
	static uint8_t fndDigitState = 0;
	fndDigitState = (fndDigitState + 1) % 5;
	
	FND_DIGIT_PORT |= (1<<FND_DIGIT_4) | (1<<FND_DIGIT_3) | (1<<FND_DIGIT_2) | (1<<FND_DIGIT_1); //숫자 찍기 전에 불 다 끄기 (커먼핀 다 1로 설정)
	switch (fndDigitState)
	{
		case 0:
		FND_NUM_PORT = fndFont[(num / 1000) % 10]; // number 1
		FND_DIGIT_PORT &= ~(1 << FND_DIGIT_1); //천의자리선택
		break;
		
		case 1:
		FND_NUM_PORT = fndFont[(num / 100) % 10]; // number 1
		FND_DIGIT_PORT &= ~(1 << FND_DIGIT_2); //백의자리선택
		break;
		
		case 2:
		FND_NUM_PORT = fndFont[(num / 10) % 10]; // number 1
		FND_DIGIT_PORT &= ~(1 << FND_DIGIT_3); //십의자리선택
		break;
		
		case 3:
		FND_NUM_PORT = fndFont[num % 10]; // number 1
		FND_DIGIT_PORT &= ~(1 << FND_DIGIT_4); //일의자리선택
		break;
		
		case 4:
		if (fndColonFlag)
			FND_NUM_PORT = fndFont[FND_COLON]; //dp
		else
			FND_NUM_PORT = 0x00;
		FND_DIGIT_PORT &= ~(1 << FND_DIGIT_2); //100의자리 dp
	}
}

void changeFndColonFlag()
{
	if (fndColonFlag)
		fndColonFlag = 0;
	else
		fndColonFlag = 1;
}

void FND_setfndData(uint16_t mydata)
{
	data = mydata;
}

void FND_ISR_Process()
{
	showNum(data);
}

