/*
MIT License

Copyright (c) 2020 IanMelvin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Name: launchTTT.c

Description: The base code for the game of tic tac toe, what sets and starts the game, and functions that can not be easily generalized

Contributers: Ian Melvin
*/

#include "finalBossDanTest/launchTTT.h"
#include "finalBoss_Dan/finalBossLoki.h"

#include <stdbool.h>
#include <stdio.h>

#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3

/*
	Purpose: Setup the pointer array, and game variable for Tic Tac Toe.
			 Call the startgame Function

	Parameters: None

	Return possibilities: 0
*/
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

/*
	Purpose: Run the gameloop, calling neccessary functions and bringing the game to an end when the criteria is met

	Parameters: Character pointer and character.

	Return possibilities: 0
*/
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

/*
	Purpose: Update the current space with the symbol of the player whose turn it is

	Parameters: Character pointer, 3 integers

	Return possibilities: NONE
*/
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

/*
	Purpose: Determine if the criteria for winning or tying is met, if so call the endgame function

	Parameters: Character pointer, 1 integer

	Return possibilities: 0 or 1
*/
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

/*
	Purpose: Output the contents of the game pointer to the command window to visualize the game

	Parameters: Character pointer

	Return possibilities: NONE
*/
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