#include <iostream>

#include "game.h"

int main(int argc, char** argv){
    std::cout << "--- Minesweeper game ---" << std::endl 
        << "Select difficulty :" << std::endl 
        << "1: Easy     2: Normal     3: Hard" << std::endl;
    unsigned short dif;
    std::cin >> dif;
    (new Game(dif))->start();
    return 0;
}