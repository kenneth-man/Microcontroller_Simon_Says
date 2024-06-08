#include <stdint.h>
#include "macros.h"
#include "structs/GPIOx_IDREG.h"
#include "structs/GPIOx_ODREG.h"
#include "structs/GPIOx_MODEREG.h"
#include "structs/GPIOx_PUPDREG.h"
#include "structs/RCC_AHB1ENREG.h"
#include "structs/GAME_CONFIG.h"
#include "helpers/gpio/gpio.h"
#include "helpers/gameState/gameState.h"
#include "variables/variables.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	RCC_AHB1ENREG volatile *const pRCCAHB1ENREG = (RCC_AHB1ENREG*)(RCC_AHB1ENREG_ADDR);
	GPIOx_MODEREG volatile *const pGPIODModeReg = (GPIOx_MODEREG*)(GPIOD_MODEREG_ADDR);
	GPIOx_PUPDREG volatile *const pGPIODPUPDReg = (GPIOx_PUPDREG*)(GPIOD_PUPDREG_ADDR);
	GPIOx_IDREG volatile *const pGPIODIDReg = (GPIOx_IDREG*)(GPIOD_IDREG_ADDR);
	GPIOx_ODREG volatile *const pGPIODODReg = (GPIOx_ODREG*)(GPIOD_ODREG_ADDR);

	initGPIO(pRCCAHB1ENREG, pGPIODModeReg, pGPIODPUPDReg);
	const char difficulty = titleScreen(pGPIODIDReg, pGPIODODReg);
	GAME_CONFIG gameConfig = initGameConfig(difficulty);

	while(1) {
		if (gameConfig.lives > 0) {
			inGame(&gameConfig, pGPIODIDReg, pGPIODODReg, difficulty);
			continue;
		}
		printf("Game over...\n");
	}
}
