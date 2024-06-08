#ifndef HELPERS_LED_LED_H_
#define HELPERS_LED_LED_H_

#include <stdio.h>
#include <stdint.h>
#include "../../structs/GPIOx_ODREG.h"
#include "../delay/delay.h"
#include "../../enums/delays.h"
#include "../../macros.h"

void orange(
	GPIOx_ODREG volatile *const pGPIODODReg,
	const DELAYS d
);
void green(
	GPIOx_ODREG volatile *const pGPIODODReg,
	const DELAYS d
);
void blue(
	GPIOx_ODREG volatile *const pGPIODODReg,
	const DELAYS d
);
void red(
	GPIOx_ODREG volatile *const pGPIODODReg,
	const DELAYS d
);

void circle(
	GPIOx_ODREG volatile *const pGPIODODReg,
	const DELAYS d
);
void flash(
	GPIOx_ODREG volatile *const pGPIODODReg,
	const DELAYS d
);
void persist(
	GPIOx_ODREG volatile *const pGPIODODReg,
	const DELAYS d
);

void display(
	GPIOx_ODREG volatile *const pGPIODODReg,
	const DELAYS d,
	const uint8_t count,
	void animation(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d)
);

void displaySequenceElement(
	GPIOx_ODREG volatile *const pGPIODODReg,
	const DELAYS d,
	const char key
);

#endif
