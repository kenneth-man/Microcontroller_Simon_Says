#ifndef HELPERS_GAMECALC_GAMECALC_H_
#define HELPERS_GAMECALC_GAMECALC_H_

#include <stdint.h>
#include <stdlib.h>
#include "../../variables/variables.h"
#include "../../structs/GAME_CONFIG.h"
#include "../../macros.h"

void updateSequenceValues(
	GAME_CONFIG *gameConfig,
	const char difficulty
);

char getRandomKey(
	char const *const keys,
	const uint8_t maxIndex,
	const uint8_t minIndex
);

char *getKeys(const char difficulty);

// function to update the game config speed
	// get index of game config speed - game config stage,
		// if currently <= 0, then stay at 0

// random led value assignment to array (switch for chars) and return

// function to see if original array and user input array match,
	// update game config if incorrect,
		// (decrement lives)
	// update game config if correct,
		// (speed, add char to sequence, sequenceLength, score, stage)

#endif
