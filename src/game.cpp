#include "game.h"



//each vector in the board vector is a row. first vector is the top row, and first element in that vector is the leftmost element/cell.

std::vector <std::vector<int>> board;
int boardSize = 4;
int largestPossiblePower;
std::vector <tile> tiles;
tile empty;
int boardCapacity = 16;

void initGame(){
    //assign values to the "empty" tile object
    empty.power, empty.decimalValue, empty.strLen = 0;
    empty.string = "";


    tiles.push_back(empty);

    largestPossiblePower = pow(boardSize, 2)+1;

    //create tile objects as long as they can be achieved with the given board size.
    for (int i = 0; i < largestPossiblePower; i++){
        tiles.push_back(tile(i+1));
    }

    initBoard(boardSize);
}

void initBoard(int size){
    std::vector <int> row;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){ 
            row.push_back(0);
        }
        board.push_back(row);
        row.clear();
    }
}

int spawnTile(){
    std::random_device rd;
    std::mt19937 gen(rd());
    //initialize coordinates
    int boardCol = 0;
    int boardRow = 0;

    std::uniform_int_distribution<> dice(1,10);
    int diceRoll = dice(gen);
    std::cout << "Dice roll: " << diceRoll << std::endl;
    std::uniform_int_distribution<> coordinate(0, boardSize-1);


    //check if there is an empty space || Game Over
    if(isBoardFull(board)){
        std::cout << "Game Over!\n";
    }

    //find an empty space
    else{
        do{
            boardCol = coordinate(gen);
            std::cout << "Board Column: " << boardCol << std::endl;
            boardRow = coordinate(gen);

        } while (board.at(boardRow).at(boardCol) != 0);


        if (diceRoll < 9){
            board.at(boardRow).at(boardCol) = 1;
        }
        else{
            board.at(boardRow).at(boardCol) = 2;
        }
    }
    

    return 0;
}

bool isBoardFull(std::vector <std::vector<int>> board){
    bool answer = false;
    int occupiedSlots = 0;

    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            if (board.at(i).at(j)){
                occupiedSlots++;
            }
        }
    }

    if (occupiedSlots == boardCapacity){
        answer = true;
    }
    
    return answer;
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
    //After rotating, we make the movements here.
}

void moveLeft(){
    for (int i = 0; i < boardSize; i++){
        board.at(i) = moveToBegin(board.at(i));
    }
    
}

void moveDown(){

}

void moveRight(){
    
}

std::vector <int> moveToBegin(std::vector<int> vector){
    vector.erase(find(vector.begin(), vector.end(), 0));
    return vector;
}

void moveToEnd(std::vector<int> vector){

}