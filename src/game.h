#ifndef GAME_H
#define GAME_H

#include <vector>
#include <random>
#include <iostream>

extern int boardSize;
extern std::vector <std::vector<int>> board;

void initBoard(int size);
int spawnTile();
void moveBoard(int direction);
void moveUp();
void moveLeft();
void moveDown();
void moveRight();

#endif //GAME_H