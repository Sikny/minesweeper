#include <iostream>
#include <SFML/Graphics.hpp>

class Case{
    public:
        Case();
        Case(float x, float y, unsigned short indX, unsigned short indY, float caseSize);
        unsigned short getX();
        unsigned short getY();
        void draw(sf::RenderWindow&, sf::Font);
        void hover();
        std::string select(Case* board);
        void unhover();
        bool hasMouseOver(sf::Vector2i mousePos);
        void setBomb();
        bool hasBomb();
        bool isReturned();
        std::string getStatus();
        unsigned short testCase(Case* board);
        void setLimits(unsigned short min, unsigned short max);
    private:
        float posX, posY;
        unsigned short indX, indY;
        unsigned short min, max;
        float caseSize;
        sf::Color color;
        sf::Color fontColor;
        bool bomb, returned;
        sf::Text status;
        sf::RectangleShape shape;
};