#include "gameState.h"

void titleScreen(
	GPIOx_IDREG volatile *const pGPIODIDReg,
	GPIOx_ODREG volatile *const pGPIODODReg
) {
	puts(
		"  @@@@@@ @@@ @@@@@@@@@@   @@@@@@  @@@  @@@       @@@@@@  @@@@@@  @@@ @@@  @@@@@@ \n"
		" !@@     @@! @@! @@! @@! @@!  @@@ @@!@!@@@      !@@     @@!  @@@ @@! !@@ !@@     \n"
		"  !@@!!  !!@ @!! !!@ @!@ @!@  !@! @!@@!!@!       !@@!!  @!@!@!@!  !@!@!   !@@!!  \n"
		"     !:! !!: !!:     !!: !!:  !!! !!:  !!!          !:! !!:  !!!   !!:       !:! \n"
		" ::.: :  :    :      :    : :. :  ::    :       ::.: :   :   : :   .:    ::.: :  \n\n"
	);
	display(pGPIODODReg, MEDIUM, 5, circle);
	printf("Select a Difficulty Level: \n");
	printf("`%c` Key = `Casual`\n", CASUAL_MODE);
	printf("`%c` Key = `Pro`\n\n", PRO_MODE);
	char input = recieveInput(pGPIODIDReg, pGPIODODReg);

	switch(input) {
	case CASUAL_MODE:
		printf("Casual Mode chosen");
	case PRO_MODE:
		printf("Pro Mode chosen");
	default:
		printf("Casual Mode chosen");
	}
}
