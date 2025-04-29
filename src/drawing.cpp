
#include "drawing.h"
#include "game.h"

int tileSize = 4;

void drawBoard(std::vector<std::vector<int>> boardData){
    std::cout << "╔";
    for (int i = 0; i < boardSize; i++){    //horizontal start
        for (int j = 0; j < tileSize*2; j++){ //border continue
            std::cout << "═";
        }
        if(i == boardSize - 1){             //border end
            std::cout << "╗\n";
        }
        else{                               //border T cross
            std::cout << "╦";
        }
    }
    int vloopCounter = 0;
    int lineCounter = 0;
    bool runLoop = true;
    do{//each iteration draws a new row to the bottom.
        
        for (int i = 0; i < boardSize + 1; i++){//each iteration draws a new tile to the right.
            std::cout << "║";
            for (int j = 0; j < tileSize*2 && i < boardSize; j++){
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        if(vloopCounter == tileSize/2 && lineCounter < boardSize-1){ //if passed, draws a border between rows.
            lineCounter++;
            if(true){
                std::cout << "╠";                           //border start
                for (int i = 0; i < boardSize; i++){        //horizontal start
                    for (int j = 0; j < tileSize*2; j++){   //border continue
                        std::cout << "═";
                    }
                    if(i == boardSize - 1){                 //border end
                        std::cout << "╣\n";
                    }
                    else{                                   //border + cross
                        std::cout << "╬";
                    }   
                }
            }
            vloopCounter = 0;
        }
        else if (lineCounter == boardSize-1){//draws the last row.
            for (int i = 0; i < tileSize-2; i++){
                for (int i = 0; i < boardSize + 1; i++){    //vertical start // "boardSize + 1" here is important, on the previous block, there was a headstart with "╔".
                    std::cout << "║";
                    for (int j = 0; j < tileSize*2 && i < boardSize; j++){
                        std::cout << " ";
                    }
                }
                std::cout << std::endl;
            }
            //ending the last row.
            std::cout << "╚";                   
            for (int i = 0; i < boardSize; i++){        //horizontal start
                for (int j = 0; j < tileSize*2; j++){   //border continue
                    std::cout << "═";
                }
                if(i == boardSize - 1){                 //border end
                    std::cout << "╝\n";
                }
                else{                                   //border + cross
                    std::cout << "╩";
                }   
            }
            runLoop = false;
        }
        
        else {
            vloopCounter++;
        }


        

    } while (runLoop);

    



    std::cout << std::endl;
}