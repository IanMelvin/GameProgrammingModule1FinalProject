#include "finalBoss_Dan/finalBossLoki.h"
#include <stdio.h>
#include <stdbool.h>

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
			printf("Where would you like to put an X value (xcoord) ");
		}
		else if (player == 2)
		{
			printf("Where would you like to put an O value (xcoord) ");
		}
		break;
	}
	scanf_s("%d", &xcord);
	printf("\n");


	return xcord-1;
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
			printf("Where would you like to put an X value (ycord) ");
			scanf_s("%d", &ycord);
		}
		else if (player == 2)
		{
			printf("Where would you like to put an O value (ycord) ");
			scanf_s("%d", &ycord);
		}
		break;
	}
	
	printf("\n");
	return ycord-1;
}
// try this again

int endState(int winner)
{
	if (winner == 3)
	{
		printf("There is a tie,\n");
		printf("You're both equally good.\n");
		printf("Ending program... (hit enter)\n");
		_getch();
	}
	else
	{
		printf("Player: ");
		printf("%c", winner);
		printf(" is the winner.\n");
		printf("Ending program... (hit enter)\n");
		_getch();
	}

	return 1;
}

void errorState()
{
	char c[] = "You have choosen an invalid location.";

	printf("%s", c);
	printf("\n \n");
}

bool checkSpace(char *ptr, int x, int y)
{
	if (x < 0 || y < 0)
	{
		return false;
	}

	else if (ptr[x+(y*3)] != ' ')
	{
		return false;
	}

	return true;
}

int updateTurn(int player)
{
	if (player == 1)
	{
		player++;
	}
	else
	{
		player--;
	}

	return player;
}

void fillArray(char* ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*ptr = ' ';
		ptr++;
	}

	for (int i = 0; i < size; i++)
	{
		ptr--;
	}
}

void draw(char* ptr)
{
	system("cls");

	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i != 0)
		{
			printf("\n");
		}
		printf("%c", ptr[i]);
		printf(" ");
	}

	printf("\n");
	printf("\n");
}