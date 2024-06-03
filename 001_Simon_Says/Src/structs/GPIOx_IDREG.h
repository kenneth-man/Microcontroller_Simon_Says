#ifndef STRUCTS_GPIOX_IDREG_H_
#define STRUCTS_GPIOX_IDREG_H_

#include <stdint.h>

typedef struct {
	uint32_t IDR0:1;
	uint32_t IDR1:1;
	uint32_t IDR2:1;
	uint32_t IDR3:1;
	uint32_t IDR4:1;
	uint32_t IDR5:1;
	uint32_t IDR6:1;
	uint32_t IDR7:1;
	uint32_t IDR8:1;
	uint32_t IDR9:1;
	uint32_t IDR10:1;
	uint32_t IDR11:1;
	uint32_t IDR12:1;
	uint32_t IDR13:1;
	uint32_t IDR14:1;
	uint32_t IDR15:1;
	uint32_t reserved:16;
} GPIOx_IDREG;

#endif
