#pragma once
#include <stdbool.h>

int getCordX(char game, int player, int phase);

int getCordY(char game, int player, int phase);

int endState(int winner);

void errorState();

bool checkSpace(char* ptr, int x, int y);

int updateTurn(int player);

void fillArray(char* ptr, int size);

void draw(char* ptr);