#include "executeLight.h"
#include "../../driver/button/button.h"
#include "../../driver/led/led.h"

void initLight()
{
	Button_init(&nextLevelbtn, &BUTTON_DDR, &BUTTON_PIN, 0);
	Button_init(&offBtn, &BUTTON_DDR, &BUTTON_PIN, 1);

	lightState = OFF;
}

void executeLight()
{
	if (Button_GetState(&nextLevelbtn) == ACT_RELEASED)
		lightState = (lightState + 1) % 5;
	if (Button_GetState(&offBtn) == ACT_RELEASED)
		lightState = OFF;

	switch (lightState)
	{
		case OFF:
		turnOFFLight();
		break;

		case TWO:
		turnTWOLight();
		break;

		case FOUR:
		turnFOURLight();
		break;

		case SIX:
		turnSIXLight();
		break;

		case EIGHT:
		turnEIGHTLight();
		break;
	}
}