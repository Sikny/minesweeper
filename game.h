#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "case.h"

class Game{
    public:
        Game(unsigned short difficulty);
        void start();
        void buildBoard(unsigned short difficulty);
        bool hasWon();
        
    private:
        unsigned short boardSize; // number of cases
        float cellSize;    // in px
        unsigned short difficulty;
        std::string difficulty_str;
        unsigned short nBombs;
        Case* board;
};