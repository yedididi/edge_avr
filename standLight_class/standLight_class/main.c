#include "./ap/standLight/standLight.h"

int main(void)
{
	standLightInit();
	while (1) 
    {
		standLightRun();
    }
}

