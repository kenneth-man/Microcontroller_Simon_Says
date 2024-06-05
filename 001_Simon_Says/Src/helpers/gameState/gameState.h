#ifndef HELPERS_GAMESTATE_GAMESTATE_H_
#define HELPERS_GAMESTATE_GAMESTATE_H_

#include <stdio.h>
#include "../led/led.h"
#include "../../enums/delays.h"
#include "../gpio/gpio.h"
#include "../../macros.h"

void titleScreen(
	GPIOx_IDREG volatile *const pGPIODIDReg,
	GPIOx_ODREG volatile *const pGPIODODReg
);

#endif
