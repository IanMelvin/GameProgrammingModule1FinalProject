

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

void drawGame(char game, char display) //draw our game
{
	int borderHeight = 0;
	int borderWidth = 0;
	//switch case define boardsize for these games
	switch (game)
	{
	case 'B':
		borderHeight = 10;
		borderWidth = 10;
		break;
	case 'C':
		borderHeight = 8;
		borderWidth = 8;
		break;
	case 'M':
		borderHeight = 2;
		borderWidth = 8;
		break;
	case 'T':
		borderHeight = 3;
		borderWidth = 3;
		break;
	}


}
int playerXY() //determine who is who
{};
