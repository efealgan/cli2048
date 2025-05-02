#ifndef DRAWING_H
#define DRAWING_H

#include <vector>
#include <iostream>
#include <string>

#include "game.h"

/**
 * @brief Tile Width in characters.
 */
extern int tileSizeV;

/**
 * @brief Tile Height in characters.
 * @note Shouldn't be changed manually, if needed, change tileSizeV instead.
 */
extern int tileSizeH;

struct tile {
    int power;
    int decimalValue;
    std::string string;
    int strLen;
    tile() : power(0), decimalValue(0), string(""), strLen(0) {}
    tile(int power);
} extern empty;

/**
 * @brief Used in drawBoard, stores the index for drawn rows. 
 */
extern int rowCounter;

/**
 * @brief Draws the board with provided board vector.
 * @note This function doesn't check vector size to draw the board, it uses boardSize, reducing flexibility.
 */
void drawBoard(std::vector<std::vector<int>> boardData);

/**
 * @brief Draws the first line of the board. 
 * @note Utilizes boardData and tileSizeH.
 */
void drawUpperBorder();

/**
 * @brief Draws the provided row data. 
 * @note Contents of the passed vector should be in order from left to right.
 * @param tilesToDraw The vector containing tiles in left to right order.
 */
void drawRow(std::vector<tile> tilesToDraw);

/**
 * @brief Draws the border between rows.
 */
void drawInnerBorder();

/** 
 * @brief Draws the last line of the board.
 */
void drawLowerBorder();

/**
 * @brief Calculates necessary padding after printing a value in a tile.
 */
int calcPaddingR(int length);

#endif //DRAWING_H