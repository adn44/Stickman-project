#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "GameManager.h"

class Menu
{
    public:
        Menu ( void );
        virtual ~Menu ( void );
        void action ( void );
    protected:
    private:
        sf::RenderWindow* m_screen;
        sf::Texture* m_bgTexture;
        sf::Sprite* m_bgSprite;
        sf::Texture* m_playTexture;
        sf::Sprite* m_playSprite;
        sf::Texture* m_activePlayTexture;
        sf::Texture* m_optionTexture;
        sf::Sprite* m_optionSprite;
        sf::Texture* m_activeOptionTexture;
};

#endif // MENU_H
