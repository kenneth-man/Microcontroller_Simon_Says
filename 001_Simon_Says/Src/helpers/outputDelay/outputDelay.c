#include "outputDelay.h"

// can't do optional/default args in C without a Macro
// easier and safer to create wrapper function
void outputDelay(char *message, DELAYS delayType) {
	output(message);
	delay(delayType);
}
