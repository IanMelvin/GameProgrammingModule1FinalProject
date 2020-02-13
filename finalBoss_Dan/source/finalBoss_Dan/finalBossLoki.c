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

int getCordX(char game, int player, int phase)//gets xcoord for alteration of board, takes in character variable and 2 integers, returns xcord
{
	int xcord;
	switch (game)
	{
	case 'B':
		if (phase == 0 && player %2 == 0)
		{
			printf("Where would you like to place your ship Player 1? (xcoord)");
			
		}
		else if (phase == 0 && player %2 != 0)//Phase 0 placing ships
		{
			printf("Where would you like to place your ship Player 2? (xcoord)");
		}
		else if (phase == 1 && player %2 == 0)
		{
			printf("Where would you like to fire Player 1?(xcoord)");
			
		}
		else if (phase == 1 && player % 2 != 0)//phase 1 firing
		{
			printf("Where would you like to fire Player 2?(xcoord)");

		}
		break;
		
	case 'C':

		if (player %2 == 0 && phase == 1)
		{
			printf("Player: White, what piece do you want to move? (xcoord)");
		}
		else if (player % 2 != 0 && phase == 1)
		{
			printf("Player: Black, what piece do you want to move? (xcoord)");
		}//phase one selecting piece
		else if (player %2 == 0 && phase == 2)
		{
			printf("Player: White, where do you want to move? (xcoord)");
		}
		else if (player %2 != 0 && phase == 2)
		{
			printf("Player: Black, where do you want to move? (xcoord)");
		}//phase two finding where the piece is moving 
		break;
	case 'M':
		phase = 0;
		printf("Which set of marbles would you like to move?(xcoord");//selects pit of counterclockwise moving marbles
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


	return xcord - 1;
}
int getCordY(char game, int player, int phase)//gets ycoord for alteration of board, takes in character variable and 2 integers, returns ycord
{
	int ycord;
	switch (game)
	{
	case 'B':
		if (phase == 0 && player %2 == 0)
		{
			printf("Where would you like to place a ship?");
		}
		else if (phase == 0 && player % 2 != 0)
		{
			printf("Where would you like to place a ship?");//Phase 0 placing ships
		}
		else if (phase == 1 && player % 2 == 0)
		{
			printf("Where would you like to fire? (ycoord)");
		
		}
		else if (phase == 1 && player % 2 != 0)
		{
			printf("Where would you like to fire? (ycoord)");

		}//phase 1 firing

		break;
	case 'C':
		if (player % 2 == 0 && phase == 1)
		{
			printf("Player: White, what piece do you want to move? (ycoord)");
			scanf_s("%d", &ycord);
		}
		else if (player % 2 != 0 && phase == 1)
		{
			printf("Player: Black, what piece do you want to move? (ycoord)");
			
		}//phase one selecting piece
		else if (player % 2 == 0 && phase == 2)
		{
			printf("Player: White, where do you want to move? (ycoord)");
		
		}
		else if (player % 2 != 0 && phase == 2)
		{
			printf("Player: Black, where do you want to move? (ycoord)");
			scanf_s("%d", &ycord);
		}//phase two finding where the piece is moving 
		break;
	case 'M':
		phase = 0;
		if (player % 2 == 0)
		{
			ycord = 1;
		}
		else if(player % 2 != 0)
		{
			ycord = 2;
		}//mancalla height = 2 therefore the height doesnt matter of the pit you are selecting you can only pick your own line
		break;
	case 'T':
		phase = 0;
		if (player == 1)
		{
			printf("Where would you like to put an X value (ycord) ");
			
		}
		else if (player == 2)
		{
			printf("Where would you like to put an O value (ycord) ");
			
		}
		break;
	}

	printf("\n");
	return ycord - 1;
}


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

bool checkSpace(char* ptr, int x, int y)//checks if space is valid and yells at you if it isnt
{
	if (x < 0 || y < 0)
	{
		return false;
	}

	else if (ptr[x + (y * 3)] != ' ')
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
void fillArray(char* ptr, int size)//fills array with blanks
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
