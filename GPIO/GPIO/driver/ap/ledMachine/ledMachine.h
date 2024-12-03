
#ifndef LEDMACHINE_H_
#define LEDMACHINE_H_

#include "../../Button/IncFile1.h"
#include "../../LED/LED.h"

void ledMachine_execute(uint8_t ledState, button_t *btnPrev, button_t *btnNext);

#endif /* LEDMACHINE_H_ */