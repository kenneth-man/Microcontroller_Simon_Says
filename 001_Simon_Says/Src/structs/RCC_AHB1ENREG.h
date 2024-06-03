#ifndef STRUCTS_RCC_AHB1ENREG_H_
#define STRUCTS_RCC_AHB1ENREG_H_

#include <stdint.h>

typedef struct {
	uint32_t gpioAEN:1;
	uint32_t gpioBEN:1;
	uint32_t gpioCEN:1;
	uint32_t gpioDEN:1;
	uint32_t gpioEEN:1;
	uint32_t gpioFEN:1;
	uint32_t gpioGEN:1;
	uint32_t gpioHEN:1;
	uint32_t gpioIEN:1;
	uint32_t reserved1:3;
	uint32_t crcEN:1;
	uint32_t reserved2:5;
	uint32_t bkpsramEN:1;
	uint32_t reserved3:1;
	uint32_t ccmdataramEN:1;
	uint32_t dma1EN:1;
	uint32_t dma2EN:1;
	uint32_t reserved4:2;
	uint32_t ethmacEN:1;
	uint32_t ethmactxEN:1;
	uint32_t ethmacrxEN:1;
	uint32_t ethmacptpEN:1;
	uint32_t otghsEN:1;
	uint32_t otghsulpiEN:1;
	uint32_t reserved5:1;
} RCC_AHB1ENREG;

#endif
