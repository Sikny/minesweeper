#include "game.h"

Game::Game(unsigned short difficulty_p) : cellSize(30.0f), difficulty(difficulty_p){
    switch(difficulty){
        case 1:
            boardSize = 10;
            nBombs = 15;
            difficulty_str = "Easy";
            break;
        case 2:
            boardSize = 15;
            nBombs = 50;
            difficulty_str = "Normal";
            break;
        case 3:
            boardSize = 20;
            nBombs = 100;
            difficulty_str = "Hard";
            break;
        default:
            std::exit(EXIT_FAILURE);
    }
    std::cout << "Building board..." << std::endl;
    board = new Case[boardSize*boardSize];
    for(unsigned short i = 0; i < boardSize; i++){
        for(unsigned short j = 0; j < boardSize; j++){
            board[i*boardSize+j] = Case(i*(cellSize+1)+cellSize-boardSize/2, j*(cellSize+1)+cellSize-boardSize/2, i, j, cellSize);
            board[i*boardSize+j].setLimits(0, boardSize-1);
        }
    }
    std::cout << "Setting bombs..." << std::endl;
    unsigned short plantedBombs = 0;
    std::srand(std::time(nullptr));
    while(plantedBombs < nBombs){
        unsigned short selectedCase = 0;
        do{
            selectedCase = (rand() % static_cast<unsigned short>(boardSize*boardSize));
        } while(board[selectedCase].hasBomb());
        plantedBombs++;
        board[selectedCase].setBomb();
    }
}

bool Game::hasWon(){
    unsigned short solvedCases = 0;
    for(unsigned short i = 0; i < boardSize*boardSize; i++){
        if(board[i].isReturned()) solvedCases++;
    }
    return (boardSize*boardSize-solvedCases) == nBombs;
}

void Game::start(){
    unsigned int windowSize = cellSize*boardSize+cellSize*2;
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Minesweeper - " + difficulty_str);
    sf::Font font;
    font.loadFromFile("arial.ttf");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for(unsigned short i = 0; i < boardSize*boardSize; i++){
                    if(board[i].hasMouseOver(mousePos)){
                        std::string status = board[i].select(board);
                        if(!status.empty()) {
                            std::cout << status << std::endl;
                            std::exit(EXIT_SUCCESS);
                        }
                        if(hasWon()){
                            std::cout << "You win" << std::endl;
                            std::exit(EXIT_SUCCESS);
                        }
                    }
                }
            }
            else if(event.type == sf::Event::MouseMoved){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for(unsigned short i = 0; i < boardSize*boardSize; i++){
                    if(board[i].hasMouseOver(mousePos)){
                        if(event.type == sf::Event::MouseMoved) board[i].hover();
                    }
                    else board[i].unhover();
                }
            }
        }

        window.clear();
        for(unsigned short i = 0; i < boardSize*boardSize; i++)
            board[i].draw(window, font);
        window.display();
    }
}