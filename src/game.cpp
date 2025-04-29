#include "game.h"
#include "input.h"

//each vector in the board vector is a row. first vector is the top row, and first element in that vector is the leftmost element/cell.
std::vector <std::vector<int>> board;
int boardSize = 4;

void initBoard(int size){
    std::vector <int> column;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){ 
            column.push_back(0);
        }
        board.push_back(column);
    }
}

int spawnTile(){
    std::random_device rd;
    std::mt19937 gen(rd());
    int boardCol;
    int boardRow;

    std::uniform_int_distribution<> dice(1,10);
    int diceRoll = dice(gen);
    std::cout << "Dice roll: " << diceRoll << std::endl;
    std::uniform_int_distribution<> coordinate(0, boardSize-1);
    do{
        boardCol = coordinate(gen);
        std::cout << "Board Column: " << boardCol << std::endl;
        boardRow = coordinate(gen);
        
    } while (board.at(boardRow).at(boardCol) != 0);


    if (diceRoll < 9){
        board.at(boardRow).insert(board.at(boardRow).begin() + boardCol, 2);
    }
    else{
        board.at(boardRow).insert(board.at(boardRow).begin() + boardCol, 4);
    }
    
    

    return 0;
}

void moveBoard(int direction){
    switch (direction){
        case Up:
            moveUp();
            break;
        case Left:
            moveLeft();
            break;
        case Down:
            moveDown();
            break;
        case Right:
            moveRight();
            break;
    }
}

/**-Vector Naming- 
 * In the move[Direction]()functions below, vectors are named respectively to their relation to the original vector board.
 * (C)lockwise / (A)nti Clockwise - Direction of rotation.
 * 0-360 - Degrees of rotation.
 * (M)irrored - Board was mirrored after rotation.
 * 
 * For example: moveUp() uses the vector c90mBoard. If the global board is as follows: 
 *  \           |       |       |       |
 *           (J)|   1   |   2   |   3   |
 *       (I)    |       |       |       |
 *    ----------|-------+-------+-------|
 *              |
 *        a     | (0,0)   (0,1)   (0,2)
 *              |
 *    ----------|
 *              |
 *        b     | (1,0)
 *              |
 *    ----------|
 *              |
 *        c     | (2,0)
 *              |
 *    ----------|
 * 
 *      It would be represented in c90mBoard as this:  
 *  \           |       |       |       |
 *           (I)|   a   |   b   |   c   |
 *       (J)    |       |       |       |
 *    ----------|-------+-------+-------|
 *              |
 *        1     | (0,0)   (1,0)   (2,0)
 *              |
 *    ----------|
 *              |
 *        2     | (0,1)
 *              |
 *    ----------|
 *              |
 *        3     | (0,2)
 *              |
 *    ----------|  
 *    
 *    It was rotated 90 degrees clockwise and then mirrored.
 *    If it wasn't mirrored, the I index would progress as C, B, A; not A, B, C.
 */

void moveUp(){
    std::vector <std::vector <int>> c90mBoard;
    for (int i = 0; i < boardSize; i++){        //Rotate and mirror the board.
        for (int j = 0; j < boardSize; j++){
            c90mBoard.at(j).push_back(board.at(i).at(j));
        }
    }
    //After rotating, 
}

void moveLeft(){

}

void moveDown(){

}

void moveRight(){
    
}
