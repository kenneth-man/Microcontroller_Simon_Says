#ifndef STRUCTS_GPIOX_PUPDREG_H_
#define STRUCTS_GPIOX_PUPDREG_H_

#include <stdint.h>

typedef struct {
	uint32_t PUPDR0:2;
	uint32_t PUPDR1:2;
	uint32_t PUPDR2:2;
	uint32_t PUPDR3:2;
	uint32_t PUPDR4:2;
	uint32_t PUPDR5:2;
	uint32_t PUPDR6:2;
	uint32_t PUPDR7:2;
	uint32_t PUPDR8:2;
	uint32_t PUPDR9:2;
	uint32_t PUPDR10:2;
	uint32_t PUPDR11:2;
	uint32_t PUPDR12:2;
	uint32_t PUPDR13:2;
	uint32_t PUPDR14:2;
	uint32_t PUPDR15:2;
} GPIOx_PUPDREG;

#endif
