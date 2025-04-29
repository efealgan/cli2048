#include <iostream>

#include "game.h"
#include "drawing.h"
#include "input.h"

int main(){
    std::cout << "Welcome to CLI2048!\n";
    std::cout << "Please enter the desired board size.\n";
    std::cin >> boardSize;
    std::cout << "Board Size is: " << boardSize << std::endl;
    initBoard(boardSize);
    std::cout << board.at(0).size() << std::endl;

    spawnTile();
    bool gameRunning = true;
    while(gameRunning){
        spawnTile();
        break;
    }

    drawBoard(board);

    return 0;
}