#pragma once
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

Name: finalBossLoki.h

Description: Holds the prototypes for the finalBossLoki.c functions

Contributers: Loki Sanguine & Ian Melvin
*/

#include <stdbool.h>

int getCordX(char game, int player, int phase);//gets xcoord for alteration of board, takes in character variable and 2 integers, returns xcord

int getCordY(char game, int player, int phase);//gets ycoord for alteration of board, takes in character variable and 2 integers, returns ycord


/*
	Purpose: Display the appropriate message for ending the game and return a value to end the game loop

	Parameters: Integer variable

	Return possibilities: 1
*/
int endState(int winner);

/*
	Purpose: Output the error message so the user knows what they did

	Parameters: None

	Return possibilities: NONE
*/
void errorState();

/*
	Purpose: Checks to see if the space choosen is valid

	Parameters: Character pointer, 2 integers

	Return possibilities: true or false
*/
bool checkSpace(char* ptr, int x, int y);

/*
	Purpose: Alters the turn order

	Parameters: integer variable

	Return possibilities: 0 or 1
*/
int updateTurn(int player);

/*
	Purpose: Fills game array with blank spaces

	Parameters: Character pointer, 1 integer

	Return possibilities: NONE
*/
void fillArray(char* ptr, int size);
