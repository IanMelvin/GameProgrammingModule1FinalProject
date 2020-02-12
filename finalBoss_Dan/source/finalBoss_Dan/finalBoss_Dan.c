#include "finalBoss_Dan/finalBoss_Dan.h"

void endGame(char victor, int player)
{
	switch (victor)
	{
	case 'W':
		printf("Congragulations Player ", player, " you have won!\n");
		break;
	case 'T':
		printf("Huh, guess you are equally skilled. Go again?\n");
		break;
	}
}


int playerXY() //determine who is who
{};
