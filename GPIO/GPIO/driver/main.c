#include "./Button/IncFile1.h"
#include "./ap/ledMachine/ledMachine.h"

int main(void)
{
	DDRD = 0xff;
	PORTA = 0xff;
	button_t btnNext, btnPrev; /////////////////////
	uint8_t ledState = LED1;
	//BUTTON_DDR &= ~((1<<0) | (1<<1));
	buttonInit(&btnNext, &DDRA, &PINA, 0);
	buttonInit(&btnPrev, &DDRA, &PINA, 1);
	
	Led_init();
	
	while (1)
	{
		ledMachine_execute(ledState, &btnPrev, &btnNext);
	}
}