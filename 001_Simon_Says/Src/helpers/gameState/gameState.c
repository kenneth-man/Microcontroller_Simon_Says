#include "gameState.h"

char titleScreen(
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

	display(pGPIODODReg, SPEED2, 5, circle);

	void titleInstructions() {
		output("Select a Difficulty Level:");
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
	GPIOx_IDREG volatile *const pGPIODIDReg,
	GPIOx_ODREG volatile *const pGPIODODReg,
	const char difficulty
) {
	updateSequence(gameConfig, difficulty);

	printf("Stage: %i, Lives: %i\n", gameConfig->stage + 1, gameConfig->lives);
	delay(SPEED10);
	printf("Ready...\n");
	delay(SPEED10);
	printf("Simon Says...\n");
	delay(SPEED10);

	int32_t correctReply = playGame(gameConfig, pGPIODIDReg, pGPIODODReg);

	if (correctReply != 0) {
		output("INCORRECT!!!");
		display(pGPIODODReg, SPEED_DIFF, 5, flash);
		gameConfig->lives -= 1;
		return;
	}

	output("CORRECT!!!");
	display(pGPIODODReg, SPEED_DIFF, 5, circle);
	gameConfig->stage += 1;
	updateGameConfig(gameConfig, difficulty);
}

int32_t playGame(
	GAME_CONFIG *gameConfig,
	GPIOx_IDREG volatile *const pGPIODIDReg,
	GPIOx_ODREG volatile *const pGPIODODReg
) {
	char sequence[gameConfig->sequenceLength];

	for(uint8_t i = 0; i < gameConfig->sequenceLength; ++i) {
		sequence[i] = gameConfig->sequence[i];

		displaySequenceElement(
			pGPIODODReg,
			gameConfig->speed,
			gameConfig->sequence[i]
		);

		if (gameConfig->sequence[i] == gameConfig->sequence[i+1]) {
			delay(SPEED_DIFF);
		}
	}

	output("...And your reply is?");

	char reply[gameConfig->sequenceLength];

	for(uint8_t i = 0; i < gameConfig->sequenceLength; ++i) {
		if (i == 0) {
			printf("Enter the First Key in the sequence\n");
		} else {
			printf("%c Key Pressed. Enter the Next Key...\n", reply[i - 1]);
		}
		const char input = recieveInput(pGPIODIDReg, pGPIODODReg);
		reply[i] = input;
	}

	return (int32_t)memcmp(sequence, reply, sizeof(sequence));
}

void gameOver(
	const GAME_CONFIG *gameConfig,
	GPIOx_IDREG volatile *const pGPIODIDReg,
	GPIOx_ODREG volatile *const pGPIODODReg
) {
	output("GAME OVER!!!");
	display(pGPIODODReg, SPEED_MAX, 1, persist);
	output("Your Stats");
	printf("Score: %i\n", (int)(gameConfig->score));
	printf("Stage: %i\n", gameConfig->stage + 1);
	printf("Speed: %i\n", (int)(gameConfig->speed / SPEED_DIFF));
	printf("Sequence Length: %i\n", (int)(gameConfig->sequenceLength));
	output("Press any Key to Restart...");
	recieveInput(pGPIODIDReg, pGPIODODReg);
}
