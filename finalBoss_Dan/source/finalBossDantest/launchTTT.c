#include "finalBossDanTest/launchTTT.h"
#include "finalBoss_Dan/finalBossLoki.h"

#include <stdbool.h>
#include <stdio.h>

#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3

int launchTicTacToe()
{
	char game = 'T';

	char values[BOARD_WIDTH * BOARD_HEIGHT];

	char* ptr;

	ptr = values;

	fillArray(ptr, BOARD_WIDTH * BOARD_HEIGHT);

	startGame(ptr, game);

	return 0;
}



int startGame(char *ptr, char game)
{
	int gameLoop = 0, xCoord = 0, yCoord = 0, players = 1, phase = 0;

	draw(ptr);

	while (gameLoop == 0)
	{
		xCoord = getCordX(game, players, phase);
		yCoord = getCordY(game, players, phase);

		if (checkSpace(ptr, xCoord, yCoord))
		{
			updateSpace(ptr, xCoord, yCoord, players);
			players = updateTurn(players);

			draw(ptr);

			gameLoop = winner(ptr, BOARD_HEIGHT * BOARD_WIDTH);
		}
		else 
		{
			errorState();
		}
	

	}

	return 0;
}

void updateSpace(char* ptr, int x, int y, int player)
{
	if (player == 1)
	{
		ptr[x + (y * 3)] = 'X';
	}
	else 
	{
		ptr[x + (y * 3)] = 'O';
	}
	
}

int winner(char* ptr, int size)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (ptr[i] != ' ')
		{
			count++;

			if (count == 9)
			{
				return endState(3);
			}
		}

		else
		{
			count = 0;
			i = size - 1;
		}
		
	}

	for (int i = 0; i < size; i+=3)
	{
		if (ptr[i] == ptr[i+1] && ptr[i] == ptr[i+2])
		{
			if (ptr[i] == 'X' || ptr[i] == 'O')
			{
				return endState(ptr[i]);
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (ptr[i] == ptr[i + 3] && ptr[i] == ptr[i + 6])
		{
			if (ptr[i] == 'X' || ptr[i] == 'O')
			{
				return endState(ptr[i]);
			}
		}
	}

	if (ptr[0] == ptr[4] && ptr[0] == ptr[8])
	{
		if (ptr[0] != ' ')
		{
			return endState(ptr[0]);
		}
	}

	if (ptr[2] == ptr[4] && ptr[2] == ptr[6])
	{
		if (ptr[2] != ' ')
		{
			return endState(ptr[2]);
		}
	}

	return 0;
}