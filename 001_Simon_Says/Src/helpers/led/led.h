#ifndef HELPERS_LED_LED_H_
#define HELPERS_LED_LED_H_

#include "../../structs/GPIOx_ODREG.h"
#include "../delay/delay.h"
#include "../../enums/delays.h"

void orange(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);
void green(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);
void blue(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);
void red(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);

#endif
