#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include "Hero.h"
#include "GameManager.h"
#include "Window.h"

class Menu : public Window {
    private:
        sf::RenderWindow* m_screen;
        sf::Texture* m_backgroundTexture;
        sf::Sprite* m_backgroundSprite;
        sf::Texture* m_continueTexture;
        sf::Sprite* m_continueSprite;
        sf::Texture* m_newTexture;
        sf::Sprite* m_newSprite;
        sf::Texture* m_optionTexture;
        sf::Sprite* m_optionSprite;
        void controls();
        void update();
        void draw();

    public:
        Menu(std::string const& title, int width, int height);
        ~Menu();
};

#endif // MENU_H_INCLUDED
