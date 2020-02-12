#include "finalBoss_Dan/finalBossLoki.h"
#include <stdio.h>

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
	
		if (player == 1 && phase == 1)
		{
			printf("Player: White, what piece do you want to move? (xcoord)");
		}
		else if (player == 2 && phase == 1)
		{
			printf("Player: Black, what piece do you want to move? (xcoord)");
		}//phase one selecting piece
		else if (player == 1 && phase == 2)
		{
			printf("Player: White, where do you want to move? (xcoord)");
		}
		else if (player == 2 && phase == 2)
		{
			printf("Player: Black, where do you want to move? (xcoord)");
		}//phase two finding where the piece is moving 
	break;
	case 'M':
		phase = 0;
		printf("Which set of marbles would you like to move?(xcoord");
		break;
	case 'T':
		phase = 0;
		if (player == 1)
		{
			printf("Where would you like to put an X value (xcoord)");
		}
		else if (player == 2)
		{
			printf("Where would you like to put an O value (xcoord)");
		}
		break;
	}
	scanf_s("%d", &xcord);
	printf("\n");
}
int getCordY(char game, int player, int phase)
{
	int ycord;
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
			printf("Where would you like to fire? (ycoord)");
		}
		break;
	case 'C':
		if (player == 1 && phase == 1)
		{
			printf("Player: White, what piece do you want to move? (ycoord)");
		}
		else if (player == 2 && phase == 1)
		{
			printf("Player: Black, what piece do you want to move? (ycoord)");
		}//phase one selecting piece
		else if (player == 1 && phase == 2)
		{
			printf("Player: White, where do you want to move? (ycoord)");
		}
		else if (player == 2 && phase == 2)
		{
			printf("Player: Black, where do you want to move? (ycoord)");
		}//phase two finding where the piece is moving 
		break;
	case 'M':
		phase = 0;
		ycord = player;
		break;
	case 'T':
		phase = 0;
		if (player == 1)
		{
			printf("Where would you like to put an X value (xcord)");
			scanf_s("%d", &ycord);
		}
		else if (player == 2)
		{
			printf("Where would you like to put an O value (xcord)");
			scanf_s("%d", &ycord);
		}
		break;
	}
	
	printf("\n");

	return 0;
}
// try this again



int endstate()
{
	return 0;
}

int errorState()
{
	return 0;
}

void fillArray(char* ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*ptr = ' ';
		printf("%c", *ptr);
		ptr++;
	}

	for (int i = 0; i < size; i++)
	{
		ptr--;
	}
}