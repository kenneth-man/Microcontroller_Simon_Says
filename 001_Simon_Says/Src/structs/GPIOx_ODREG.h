#ifndef STRUCTS_GPIOX_ODREG_H_
#define STRUCTS_GPIOX_ODREG_H_

#include <stdint.h>

typedef struct {
	uint32_t ODR0:1;
	uint32_t ODR1:1;
	uint32_t ODR2:1;
	uint32_t ODR3:1;
	uint32_t ODR4:1;
	uint32_t ODR5:1;
	uint32_t ODR6:1;
	uint32_t ODR7:1;
	uint32_t ODR8:1;
	uint32_t ODR9:1;
	uint32_t ODR10:1;
	uint32_t ODR11:1;
	uint32_t ODR12:1;
	uint32_t ODR13:1;
	uint32_t ODR14:1;
	uint32_t ODR15:1;
	uint32_t reserved:16;
} GPIOx_ODREG;

#endif
