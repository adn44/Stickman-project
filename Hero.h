#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include <string>
#include "Character.h"

const int SPEED = 1;
const int JUMP_HEIGHT= 50;

class Hero : public Character {
    public:
        Hero();
        Hero(std::string const& skin);
        ~Hero();
        virtual void jump();
        virtual void goRight();
        virtual void goLeft();
        virtual void draw(sf::RenderWindow* screen);
        virtual void jumpAnimation();
    private:
        bool m_right;
        bool m_jumping;
        int m_jump;
};

#endif // HERO_H_INCLUDED
