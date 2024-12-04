#include "TIM.h"

void initTIM0()
{
	//timer/counter0에 대한 overflow interrupt 설정
	//prescaler 1/1024로 설정하고 test > cs00 cs01, cs02 다 1로 설정해야 함
	TCCR0 |= (1 << CS02) | (0 << CS01) | (1 << CS00);
	//TIMSK timer overflow interrupt enable 설정
	TIMSK |= (1 << TOIE0);

	TCNT0 = 130; //이 설정을 줬으니까 1ms 주기마다 인터럽트 발생
}

void initTIM2()
{
	//prescaler 1/64로 설정 > cs22, cs21, cs20 0 1 1로 설정해야 함
	TCCR2 |= (0 << CS22) | (1 << CS21) | (1 << CS20);
	
	//CTC mode 설정
	TCCR2 |= (1 << WGM21) | (0 << WGM20);
	
	//TIMSK timer compare bit on
	TIMSK |= (1 << OCIE2);
	
	//비교할 숫자 설정
	OCR2 = 250 - 1;
}