#include "gpio.h"

void initGPIO(
	RCC_AHB1ENREG volatile *const pRCCAHB1ENREG,
	GPIOx_MODEREG volatile *const pGPIODModeReg,
	GPIOx_PUPDREG volatile *const pGPIODPUPDReg
) {
	// enable clock (RCC peripheral) for GPIOD peripheral (port D)
	pRCCAHB1ENREG->gpioDEN = 1;

	// set the keypad columns pin mode to input mode
	pGPIODModeReg->modeR8 = 0;
	pGPIODModeReg->modeR9 = 0;
	pGPIODModeReg->modeR10 = 0;
	pGPIODModeReg->modeR11 = 0;

	// enable internal pull-up resistors for keypad column pins
	pGPIODPUPDReg->PUPDR8 = 1;
	pGPIODPUPDReg->PUPDR9 = 1;
	pGPIODPUPDReg->PUPDR10 = 1;
	pGPIODPUPDReg->PUPDR11 = 1;

	// set the keypad rows pin mode to output mode
	pGPIODModeReg->modeR0 = 1;
	pGPIODModeReg->modeR1 = 1;
	pGPIODModeReg->modeR2 = 1;
	pGPIODModeReg->modeR3 = 1;

	// set LEDs mode (PD12-15) to ouput mode
	pGPIODModeReg->modeR12 = 1;
	pGPIODModeReg->modeR13 = 1;
	pGPIODModeReg->modeR14 = 1;
	pGPIODModeReg->modeR15 = 1;
}

char debounce(char c) {
	delay(MEDIUM);
	return c;
}

char recieveInput(
	GPIOx_IDREG volatile *const pGPIODIDReg,
	GPIOx_ODREG volatile *const pGPIODODReg
) {
	while(1) {
		pGPIODODReg->ODR0 = 0;
		pGPIODODReg->ODR1 = 1;
		pGPIODODReg->ODR2 = 1;
		pGPIODODReg->ODR3 = 1;

		if (!pGPIODIDReg->IDR8) return debounce(KEYPAD_1);
		if (!pGPIODIDReg->IDR9) return debounce(KEYPAD_2);
		if (!pGPIODIDReg->IDR10) return debounce(KEYPAD_3);
		if (!pGPIODIDReg->IDR11) return debounce(KEYPAD_A);

		pGPIODODReg->ODR0 = 1;
		pGPIODODReg->ODR1 = 0;

		if (!pGPIODIDReg->IDR8) return debounce(KEYPAD_4);
		if (!pGPIODIDReg->IDR9) return debounce(KEYPAD_5);
		if (!pGPIODIDReg->IDR10) return debounce(KEYPAD_6);
		if (!pGPIODIDReg->IDR11) return debounce(KEYPAD_B);

		pGPIODODReg->ODR1 = 1;
		pGPIODODReg->ODR2 = 0;

		if (!pGPIODIDReg->IDR8) return debounce(KEYPAD_7);
		if (!pGPIODIDReg->IDR9) return debounce(KEYPAD_8);
		if (!pGPIODIDReg->IDR10) return debounce(KEYPAD_9);
		if (!pGPIODIDReg->IDR11) return debounce(KEYPAD_C);

		pGPIODODReg->ODR2 = 1;
		pGPIODODReg->ODR3 = 0;

		if (!pGPIODIDReg->IDR8) return debounce(KEYPAD_STAR);
		if (!pGPIODIDReg->IDR9) return debounce(KEYPAD_0);
		if (!pGPIODIDReg->IDR10) return debounce(KEYPAD_HASH);
		if (!pGPIODIDReg->IDR11) return debounce(KEYPAD_D);
	}
}
