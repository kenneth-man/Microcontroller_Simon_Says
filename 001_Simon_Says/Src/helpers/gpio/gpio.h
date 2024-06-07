#ifndef HELPERS_GPIO_GPIO_H_
#define HELPERS_GPIO_GPIO_H_

#include "../../structs/RCC_AHB1ENREG.h"
#include "../../structs/GPIOx_MODEREG.h"
#include "../../structs/GPIOx_PUPDREG.h"
#include "../../structs/GPIOx_IDREG.h"
#include "../../structs/GPIOx_ODREG.h"
#include "../../macros.h"
#include "../delay/delay.h"
#include "../../enums/delays.h"

void initGPIO(
	RCC_AHB1ENREG volatile *const pRCCAHB1ENREG,
	GPIOx_MODEREG volatile *const pGPIODModeReg,
	GPIOx_PUPDREG volatile *const pGPIODPUPDReg
);

char debounce(const char c);

char recieveInput(
	GPIOx_IDREG volatile *const pGPIODIDReg,
	GPIOx_ODREG volatile *const pGPIODODReg
);

#endif
