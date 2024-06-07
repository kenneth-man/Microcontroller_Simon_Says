#include "gameCalc.h"

void updateSequenceValues(
	GAME_CONFIG *gameConfig,
	const char difficulty
) {
	uint8_t truthyElements = 0;

	for(uint8_t i = 0; i < gameConfig->sequenceLength; ++i) {
		if (gameConfig->sequence[i]) ++truthyElements;
	}

	const uint8_t truthyElementsDiff = gameConfig->sequenceLength - truthyElements;

	if (truthyElementsDiff) {
		char const *const keys = getKeys(difficulty);
		const uint8_t maxIndex = sizeof(*keys) / sizeof(char);
		const uint8_t minIndex = 0;

		for(uint8_t i = truthyElements; i < gameConfig->sequenceLength; ++i) {
			gameConfig->sequence[i] = getRandomKey(keys, maxIndex, minIndex);
		}
	}
}

char getRandomKey(
	char const *const keys,
	const uint8_t maxIndex,
	const uint8_t minIndex
) {
	return keys[(rand() % (maxIndex - minIndex))];
}

char *getKeys(const char difficulty) {
	switch(difficulty) {
	case CASUAL_MODE:
		return (char*)&casualModeKeys;
	case PRO_MODE:
		return (char*)&proModeKeys;
	default:
		return (char*)&casualModeKeys;
	}
}
