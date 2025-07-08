#ifndef INPUT_H
#define INPUT_H

#include <iostream>

#ifdef _WIN32
    #include <conio.h> // Windows
#else
    #include <termios.h> // Linux
    #include <unistd.h>
#endif

char getInput();
enum Direction{
    Up,
    Left,
    Down,
    Right
};
int processInput(char input);

#endif //INPUT_H