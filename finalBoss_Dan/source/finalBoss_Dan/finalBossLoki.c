int getCordX(char game, int player, int phase)
{
	int xcord;
	switch (game)
	{
	case 'B':
		if (phase == 0 && player == 1)
		{
			//to be continued
		}
		else if (phase == 0 && player == 2)
		{
			//to be continued
		}
		else if (phase == 1 && player == 1)
		{
			printf("Where would you like to fire? (xcoord)");
		}
		break;
	case 'C':
		phase = 0;
		break;
	case 'M':
		phase = 0;
		break;
	case 'T':
		phase = 0;
		if (player == 1)
		{
			printf("Where would you like to put an X value (xcord)");
		}
		else if (player == 2)
		{
			printf("Where would you like to put an O value (xcord)");
		}
		break;
	}
	scanf_s("%d", &xcord);
	printf("\n");
}
// try this again