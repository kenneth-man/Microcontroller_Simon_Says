#ifndef HELPERS_GAMESTATE_GAMESTATE_H_
#define HELPERS_GAMESTATE_GAMESTATE_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../led/led.h"
#include "../delay/delay.h"
#include "../../enums/delays.h"
#include "../gpio/gpio.h"
#include "../../macros.h"
#include "../../structs/GAME_CONFIG.h"

char titleScreen(
	GPIOx_IDREG volatile *const pGPIODIDReg,
	GPIOx_ODREG volatile *const pGPIODODReg
);

GAME_CONFIG initGameConfig(char difficulty);

void inGame(
	GAME_CONFIG *gameConfig,
	GPIOx_ODREG volatile *const pGPIODODReg
);

#endif
