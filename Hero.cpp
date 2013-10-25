#include "Hero.h"

#include <iostream>

Hero::Hero() : m_right(true), m_jumping(false), m_jump(0)
{
}

Hero::Hero(std::string const& skin) : m_right(true), m_jumping(false), m_jump(0)
{
    //m_skinPicture = new sf::Image;
    setSprite("caisse.jpg");
}

Hero::~Hero()
{

}

void Hero::jump()
{
    if(!m_jumping){
        m_jump = JUMP_HEIGHT;
        m_jumping = true;
    }
}

void Hero::jumpAnimation() {

    if(m_jumping){
            if(m_jump == 0){
                m_jump = 0;
                m_jumping = false;
            }
            else if(m_jump <= JUMP_HEIGHT/2) {
                m_skinSprite->Move(0, SPEED);
            }
            else {
                m_skinSprite->Move(0, -SPEED);
            }

            m_jump--;
    }
}

void Hero::goRight()
{
    if(!m_right){
        m_right = true;
        //changeSkin("caisse.jpg");
    }
    m_skinSprite->Move(SPEED,0);
}

void Hero::goLeft()
{
    if(m_right){
        m_right = false;
        //changeSkin("caisse_ok.jpg");
    }
    m_skinSprite->Move(-SPEED,0);
}

void Hero::draw(sf::RenderWindow* screen)
{
    screen->Draw(*m_skinSprite);
}
