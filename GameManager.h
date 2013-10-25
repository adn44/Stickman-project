#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include "Hero.h"

class GameManager {
    private:
        sf::RenderWindow* m_screen;
        sf::View* m_view; // in Level
        sf::Texture* m_texture; // destroy
        sf::Sprite* m_sprite; // destroy
        Hero* m_hero; // in Level

        void controls();
        std::string collision();
        void update();
        void draw();

    public:
        GameManager(std::string const& title, int width, int height);
        ~GameManager();
};

#endif // GAMEMANAGER_H_INCLUDED
