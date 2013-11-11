#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "GameManager.h"

class Menu
{
    public:
        virtual ~Menu ( void );
        static Menu* getInstance(void) {
            if(!m_menu)
                m_menu = new Menu();
            return m_menu;
        }
        void action ( void );
    protected:
    private:
        static Menu* m_menu;
        sf::RenderWindow* m_screen;
        sf::Texture* m_bgTexture;
        sf::Sprite* m_bgSprite;
        sf::Texture* m_playTexture;
        sf::Sprite* m_playSprite;
        sf::Texture* m_activePlayTexture;
        sf::Texture* m_optionTexture;
        sf::Sprite* m_optionSprite;
        sf::Texture* m_activeOptionTexture;
        Menu ( void );
};

#endif // MENU_H
