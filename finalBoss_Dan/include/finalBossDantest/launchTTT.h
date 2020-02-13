#pragma once


int launchTicTacToe();

int startGame(char *ptr, char game);

void updateSpace(char* ptr, int x, int y, int player);

int winner(char* ptr, int size);