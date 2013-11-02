#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

const int H = 5;
const int W = 5;

class GameManager
{
    public:
        GameManager(int width, int height, std::string const& title);
        virtual ~GameManager();
        void action();
        void update();
        void draw();
        //char collision();
        char collisionR();
        char collisionL();
        char collisionT();
        char collisionG();
    protected:
    private:
        Player* m_player;
        std::string m_tileMap[H];
        sf::RenderWindow* m_screen;
        sf::View* m_view;
};

#endif // GAMEMANAGER_H
