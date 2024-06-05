#include "led.h"

void circle(
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS d
) {
	pGPIODODReg->ODR13 = 1;
	delay(d);
	pGPIODODReg->ODR13 = 0;

	pGPIODODReg->ODR12 = 1;
	delay(d);
	pGPIODODReg->ODR12 = 0;

	pGPIODODReg->ODR15 = 1;
	delay(d);
	pGPIODODReg->ODR15 = 0;

	pGPIODODReg->ODR14 = 1;
	delay(d);
	pGPIODODReg->ODR14 = 0;
}

void flash(
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS d
) {
	pGPIODODReg->ODR13 = 1;
	pGPIODODReg->ODR12 = 1;
	pGPIODODReg->ODR15 = 1;
	pGPIODODReg->ODR14 = 1;
	delay(d);
	pGPIODODReg->ODR13 = 0;
	pGPIODODReg->ODR12 = 0;
	pGPIODODReg->ODR15 = 0;
	pGPIODODReg->ODR14 = 0;
	delay(d);
}

void persist(
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS d
) {
	pGPIODODReg->ODR13 = 1;
	delay(d);
	pGPIODODReg->ODR12 = 1;
	delay(d);
	pGPIODODReg->ODR15 = 1;
	delay(d);
	pGPIODODReg->ODR14 = 1;
	delay(d);
	pGPIODODReg->ODR13 = 0;
	delay(d);
	pGPIODODReg->ODR12 = 0;
	delay(d);
	pGPIODODReg->ODR15 = 0;
	delay(d);
	pGPIODODReg->ODR14 = 0;
}

void display (
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS delay,
	uint8_t count,
	void animation(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS delay)
) {
	for(size_t i = 0; i < count; ++i) {
		animation(pGPIODODReg, delay);
	}
}
