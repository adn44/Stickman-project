#include "Hero.h"

#include <iostream>

Hero::Hero() : m_right(true), m_jumping(false), m_onGround(false), m_jump(0)
{
}

Hero::Hero(std::string const& skinPath) : m_right(true), m_jumping(false), m_jump(0), m_currentFrame(0)
{
    //m_skinPicture = new sf::Image;
    setSprite(skinPath);
    m_skinSprite->setTextureRect( sf::IntRect(40, 244, 40, 50) );
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
                m_skinSprite->setTextureRect(sf::IntRect(0, 244, 40, 50));
            }
            else if(m_jump <= JUMP_HEIGHT/2) {
                m_skinSprite->move(0, SPEED);
            }
            else {
                m_skinSprite->move(0, -SPEED);
            }

            m_jump--;
    }
}

void Hero::goRight()
{
    if(!m_right){
        m_right = true;
    }
    m_skinSprite->move(SPEED,0);
    m_currentFrame += 0.08;

    if (m_currentFrame > 6)
        m_currentFrame -= 6;
    m_skinSprite->setTextureRect( sf::IntRect(int(m_currentFrame)*40, 244, 40, 50));
}

void Hero::goLeft()
{
    if(m_right){
        m_right = false;
    }
    m_skinSprite->move(-SPEED,0);
    m_currentFrame += 0.08;

    if (m_currentFrame > 6)
        m_currentFrame -= 6;
    m_skinSprite->setTextureRect(sf::IntRect(40*int(m_currentFrame)+40, 244, -40, 50));
}

void Hero::draw(sf::RenderWindow* screen)
{
    screen->draw(*m_skinSprite);
}
