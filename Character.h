#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Character{
    public:
        virtual void jump() = 0;
        virtual void jumpAnimation() = 0;
        virtual void goRight() = 0;
        virtual void goLeft() = 0;
        virtual void draw(sf::RenderWindow* screen) = 0;
        sf::Sprite skin();
        sf::Sprite* pSkin();
        void setSprite(std::string const& path);
        void changeSkin(std::string const& path);
    protected:
        sf::Texture* m_skinTexture;
        sf::Sprite* m_skinSprite;
};

#endif // CHARACTER_H_INCLUDED
