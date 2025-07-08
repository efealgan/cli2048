#include "drawing.h"

int tileSizeV = 5; //should be an odd number for vertical centering of the tiles.
int tileSizeH = tileSizeV+2;
int rowCounter = 0;

void drawBoard(std::vector<std::vector<int>> boardData){
    drawUpperBorder();
    int lineCounter = 0;
    rowCounter = 0;
    
    bool runLoop = true;

    for (int i = 0; i < boardSize; i++){
        std::vector<int> drawnRow = boardData.at(i);
        std::vector<tile> rowTiles;
        for (int j = 0; j < boardSize; j++){
            rowTiles.push_back(tiles.at(drawnRow.at(j)));
        }
        drawRow(rowTiles);
        rowTiles.clear();
    }
}

void drawUpperBorder(){
    std::cout << "╔";
    for (int i = 0; i < boardSize; i++){    //horizontal start

            for (int j = 0; j < tileSizeH*2; j++){ //border continue
                std::cout << "═";
            }
            if(i == boardSize - 1){             //border end
                std::cout << "╗\n";
            }
            else{                               //border T cross
                std::cout << "╦";
            }
    }
}

void drawRow(std::vector<tile> tilesToDraw){
    
    int padL = tileSizeH;
    int padR = tileSizeH;
    for (int lineNo = 0; lineNo < tileSizeV; lineNo++){
        for (int tileNo = 0; tileNo < boardSize; tileNo++){

            if (lineNo == tileSizeV/2){
                padR = calcPaddingR(tilesToDraw.at(tileNo).strLen);
                padL = tileSizeH*2 - padR - tilesToDraw.at(tileNo).strLen;
            }
            else{
                padL = tileSizeH;
                padR = tileSizeH;
            }
            
            std::cout << "║";
            for (int pad = 0; pad < padL; pad++){
                std::cout << " ";
            }

            if (lineNo == tileSizeV/2){
                std::cout << tilesToDraw.at(tileNo).string;
            }
            
            for (int pad = 0; pad < padR; pad++){
                std::cout << " ";
            }
            
        }
        std::cout << "║\n";
    }
    rowCounter++;
    if (rowCounter == boardSize){
        drawLowerBorder();
    }
    else{
        drawInnerBorder();
    }
    
}

void drawInnerBorder(){
    std::cout << "╠";                           //border start
    for (int i = 0; i < boardSize; i++){        //horizontal start
        for (int j = 0; j < tileSizeH*2; j++){   //border continue
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

void drawLowerBorder(){
    std::cout << "╚";                   
    for (int i = 0; i < boardSize; i++){        //horizontal start
        for (int j = 0; j < tileSizeH*2; j++){   //border continue
            std::cout << "═";
        }
        if(i == boardSize - 1){                 //border end
            std::cout << "╝\n";
        }
        else{                                   //border + cross
            std::cout << "╩";
        }   
    }
}

tile::tile(int poweroftwo){
    int decimal = 1 << poweroftwo;
    std::string stringForm = std::to_string(decimal);
    int stringLength = stringForm.length();
    this->decimalValue = decimal;
    this->power = poweroftwo;
    this->string = stringForm;
    this->strLen = stringLength;
}

int calcPaddingR(int length){
    return ((tileSizeH*2-length)/2);
}