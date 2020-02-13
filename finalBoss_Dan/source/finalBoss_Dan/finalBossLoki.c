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

Name: finalBossLoki.c

Description: Holds the prototypes for the launchTTT.c functions

Contributers: Loki Sanguine & Ian Melvin 
*/

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

/*
	Purpose: Display the appropriate message for ending the game and return a value to end the game loop

	Parameters: Integer variable

	Return possibilities: 1
*/
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

/*
	Purpose: Output the error message so the user knows what they did

	Parameters: None

	Return possibilities: NONE
*/
void errorState()
{
	char c[] = "You have choosen an invalid location.";

	printf("%s", c);
	printf("\n \n");
}

/*
	Purpose: Checks to see if the space choosen is valid

	Parameters: Character pointer, 2 integers

	Return possibilities: true or false
*/
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

/*
	Purpose: Alters the turn order

	Parameters: integer variable

	Return possibilities: 0 or 1
*/
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

/*
	Purpose: Fills game array with blank spaces

	Parameters: Character pointer, 1 integer
	
	Return possibilities: NONE
*/
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