#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#endif

#include "game.h"
#include "drawing.h"
#include "input.h"


int main(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif
    std::cout << "Welcome to CLI2048!\n";
    tile tile1 = tile(10);
    std::cout << "Please enter the desired board size.\n";
    std::cin >> boardSize;
    std::cout << "Board Size is: " << boardSize << std::endl;
    initGame();
    std::cout << board.at(0).size() << std::endl;


    bool gameRunning = true;
    while(gameRunning){
        spawnTile();
        break;
    }

    drawBoard(board);

    return 0;
}