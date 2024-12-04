#include "ap/stopwatch/stopwatch.h"

//� ���ǿ� ���� ISR���� ����ؾ���
ISR(TIMER0_OVF_vect) //timer overflow�� ���� ISR�̶�� ��
{
	FND_ISR_Process();
	TCNT0 = 131; //�� ������ �����ϱ� 1ms �ֱ⸶�� ���ͷ�Ʈ �߻�
	incTick();
}

ISR(TIMER2_COMP_vect)
{
	FND_ISR_Process();
	incTick();
}

int main(void)
{
	stopwatch_init();
	
	//global interrupt enable ����
	sei();
	while (1)
	{
		stopwatch_execute();
	}
}

