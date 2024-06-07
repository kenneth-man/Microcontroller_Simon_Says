#include "outputDelay.h"

// can't do optional/default args in C without a Macro
// easier and safer to create wrapper function
void outputDelay(
	const char *message,
	const DELAYS delayType
) {
	output(message);
	delay(delayType);
}
