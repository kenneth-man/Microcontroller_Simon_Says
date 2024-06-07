#include "gameState.h"

char titleScreen(
	GPIOx_IDREG volatile *const pGPIODIDReg,
	GPIOx_ODREG volatile *const pGPIODODReg
) {
	srand(time(NULL));

	puts(
		"  @@@@@@ @@@ @@@@@@@@@@   @@@@@@  @@@  @@@       @@@@@@  @@@@@@  @@@ @@@  @@@@@@ \n"
		" !@@     @@! @@! @@! @@! @@!  @@@ @@!@!@@@      !@@     @@!  @@@ @@! !@@ !@@     \n"
		"  !@@!!  !!@ @!! !!@ @!@ @!@  !@! @!@@!!@!       !@@!!  @!@!@!@!  !@!@!   !@@!!  \n"
		"     !:! !!: !!:     !!: !!:  !!! !!:  !!!          !:! !!:  !!!   !!:       !:! \n"
		" ::.: :  :    :      :    : :. :  ::    :       ::.: :   :   : :   .:    ::.: :  \n\n"
	);

	display(pGPIODODReg, SPEED2, 5, circle);

	void titleInstructions() {
		printf("Select a Difficulty Level: \n");
		printf("`%c` Key = `Casual`\n", CASUAL_MODE);
		printf("`%c` Key = `Pro`\n\n", PRO_MODE);
	}

	titleInstructions();

	while(1) {
		char input = recieveInput(pGPIODIDReg, pGPIODODReg);

		switch(input) {
		case KEYPAD_1:
			output("Casual Mode chosen!");
			display(pGPIODODReg, SPEED_DIFF, 5, flash);
			return CASUAL_MODE;
		case KEYPAD_2:
			output("Pro Mode chosen!");
			display(pGPIODODReg, SPEED_DIFF, 5, flash);
			return PRO_MODE;
		default:
			output("Invalid Key Pressed, Try again...");
			titleInstructions();
		}
	}
}

GAME_CONFIG initGameConfig(const char difficulty) {
	GAME_CONFIG config;

	switch(difficulty) {
	case CASUAL_MODE:
		config.speed = SPEED_MAX;
		config.sequenceLength = CASUAL_MODE_SEQ_LEN;
		config.lives = CASUAL_MODE_LIVES;
		break;
	case PRO_MODE:
		config.speed = SPEED6;
		config.sequenceLength = PRO_MODE_SEQ_LEN;
		config.lives = PRO_MODE_LIVES;
		break;
	default:
		config.speed = SPEED_MAX;
		config.sequenceLength = CASUAL_MODE_SEQ_LEN;
		config.lives = CASUAL_MODE_LIVES;
	}

	memset(config.sequence, '\0', sizeof(config.sequence));
	config.score = GAME_CONFIG_SCORE;
	config.stage = GAME_CONFIG_STAGE;

	return config;
}

void inGame(
	GAME_CONFIG *gameConfig,
	GPIOx_ODREG volatile *const pGPIODODReg,
	const char difficulty
) {
	updateSequenceValues(gameConfig, difficulty);
	printf("Ready...\n");
	delay(SPEED7);
	printf("Simon Says...\n");
	delay(SPEED7);

}
