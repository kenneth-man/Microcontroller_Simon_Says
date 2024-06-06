#ifndef STRUCTS_GAME_CONFIG_H_
#define STRUCTS_GAME_CONFIG_H_

#include <stdint.h>
#include "../macros.h"

typedef struct {
	uint32_t speed;
	char sequence[GAME_CONFIG_MAX_SEQ_LEN];
	uint32_t sequenceLength;
	uint8_t lives;
	uint32_t score;
	uint8_t stage;
} GAME_CONFIG;

#endif
