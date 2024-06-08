#ifndef HELPERS_GAMECALC_GAMECALC_H_
#define HELPERS_GAMECALC_GAMECALC_H_

#include <stdint.h>
#include <stdlib.h>
#include "../../variables/variables.h"
#include "../../structs/GAME_CONFIG.h"
#include "../../macros.h"
#include "../../enums/delays.h"

void updateSequence(
	GAME_CONFIG *gameConfig,
	const char difficulty
);

void updateGameConfig(
	GAME_CONFIG *gameConfig,
	const char difficulty
);

char getRandomKey(
	char const *const keys,
	const uint8_t maxIndex,
	const uint8_t minIndex
);

char *getKeys(const char difficulty);

#endif
