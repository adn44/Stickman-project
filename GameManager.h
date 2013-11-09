#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "ILevel.h"
#include "LevelOne.h"

const int H = 5;
const int W = 15;

class GameManager
{
    public:
        GameManager ( int width, int height, std::string const& title );
        virtual ~GameManager ( void );
        void action ( void );
        void update ( void );
        void draw ( void );
        void collisionR ( void );
        void collisionL ( void );
        void collisionT ( void );
        void collisionG ( void );
    protected:
    private:
        Player* m_player;
        sf::RenderWindow* m_screen;
        sf::View* m_view;
        ILevel* m_level;
        char* m_colG;
        char* m_colL;
        char* m_colT;
        char* m_colR;
};

#endif // GAMEMANAGER_H
