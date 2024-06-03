#ifndef STRUCTS_GPIOX_MODEREG_H_
#define STRUCTS_GPIOX_MODEREG_H_

#include <stdint.h>

typedef struct {
	uint32_t modeR0:2;
	uint32_t modeR1:2;
	uint32_t modeR2:2;
	uint32_t modeR3:2;
	uint32_t modeR4:2;
	uint32_t modeR5:2;
	uint32_t modeR6:2;
	uint32_t modeR7:2;
	uint32_t modeR8:2;
	uint32_t modeR9:2;
	uint32_t modeR10:2;
	uint32_t modeR11:2;
	uint32_t modeR12:2;
	uint32_t modeR13:2;
	uint32_t modeR14:2;
	uint32_t modeR15:2;
} GPIOx_MODEREG;

#endif
