#ifndef HELPERS_GPIO_GPIO_H_
#define HELPERS_GPIO_GPIO_H_

#include "../../structs/RCC_AHB1ENREG.h"
#include "../../structs/GPIOx_MODEREG.h"
#include "../../structs/GPIOx_PUPDREG.h"

void initGPIO(
	RCC_AHB1ENREG volatile *const pRCCAHB1ENREG,
	GPIOx_MODEREG volatile *const pGPIODModeReg,
	GPIOx_PUPDREG volatile *const pGPIODPUPDReg
);
//char* recieveInput(); // TODO: reading from keypad cols & rows, make more concise

#endif
