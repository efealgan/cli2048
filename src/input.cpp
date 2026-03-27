#include "input.h"

char getInput() {
#ifdef _WIN32
    return _getch(); // instantly gets a key without waiting for Enter
#else
    char buf = 0;
    struct termios old = {0};
    
    if (tcgetattr(0, &old) < 0){
        perror("tcsetattr()");
    }
        
    //change terminal settings
    old.c_lflag &= ~ICANON; // disable buffered I/O
    old.c_lflag &= ~ECHO;   // disable echo mode

    if (tcsetattr(0, TCSANOW, &old) < 0){
        perror("tcsetattr ICANON");
    }
    if (read(0, &buf, 1) < 0){
        perror("read()");
    }
    //restore original terminal settings
    old.c_lflag |= ICANON; 
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0){
        perror("tcsetattr ~ICANON");
    }
    return buf;
#endif
}

int processInput(char input){
    switch (input){
        case 'w':
        case 'W':
            std::cout << "Pressed UP\n";
            return Up;
        case 'a':
        case 'A':
            std::cout << "Pressed LEFT\n";
            return Left;
        case 's':
        case 'S':
            std::cout << "Pressed DOWN\n";
            return Down;
        case 'd':
        case 'D':
            std::cout << "Pressed RIGHT\n";
            return Right;
        case 'q':
        case 'Q':
            std::cout << "Pressed QUIT\n";
            return -1;
        default:
            std::cout << "Input wasn't accepted. Please try again.\n";
            processInput(getInput());
            return -1;
    }
}