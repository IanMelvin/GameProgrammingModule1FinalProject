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

Name: launchTTT.h

Description: Holds the prototypes for the launchTTT.c functions

Contributers: Ian Melvin
*/

/*
	Purpose: Setup the pointer array, and game variable for Tic Tac Toe.
			 Call the startgame Function

	Parameters: None

	Return possibilities: 0
*/
int launchTicTacToe();

/*
	Purpose: Run the gameloop, calling neccessary functions and bringing the game to an end when the criteria is met

	Parameters: Character pointer and character.

	Return possibilities: 0
*/
int startGame(char *ptr, char game);

/*
	Purpose: Update the current space with the symbol of the player whose turn it is

	Parameters: Character pointer, 3 integers

	Return possibilities: NONE
*/
void updateSpace(char* ptr, int x, int y, int player);

/*
	Purpose: Determine if the criteria for winning or tying is met, if so call the endgame function

	Parameters: Character pointer, 1 integer

	Return possibilities: 0 or 1
*/
int winner(char* ptr, int size);

/*
	Purpose: Output the contents of the game pointer to the command window to visualize the game

	Parameters: Character pointer

	Return possibilities: NONE
*/
void draw(char* ptr);