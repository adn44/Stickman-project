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
        virtual ~GameManager ( void );
        static GameManager* getInstance(void) {
            if(!m_gameManager)
                m_gameManager = new GameManager(640,480, "Stickman-project");
            return m_gameManager;
        }
        void action ( void );
        void update ( void );
        void draw ( void );
        void collisionR ( void );
        void collisionL ( void );
        void collisionT ( void );
        void collisionG ( void );
    protected:
    private:
        static GameManager* m_gameManager;
        Player* m_player;
        sf::RenderWindow* m_screen;
        sf::View* m_view;
        ILevel* m_level;
        char* m_colG;
        char* m_colL;
        char* m_colT;
        char* m_colR;
        GameManager ( int width, int height, std::string const& title );
};

#endif // GAMEMANAGER_H
