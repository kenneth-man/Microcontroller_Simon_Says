#include "delay.h"

// not the best way to delay,
// but couldn't get <unistd.h> sleep or <windows.h> Sleep to work,
// due to include errors and sleep not being recognised...
void delay(const DELAYS delayType) {
	for (size_t i = 0; i < delayType; ++i);
}
