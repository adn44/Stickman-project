#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

const int SPEED = 2;
const int JUMP_SPEED = 1;
const int JUMP_HEIGHT = 200;

class Player
{
    public:
        Player ( void );
        virtual ~Player ( void );
        sf::Sprite* getSprite ( void );
        bool getOnGround ( void );
        void setOnGround ( bool value );
        void goRight ( void );
        void goLeft ( void );
        void fall ( void );
        void controls ( char collisionR, char collisionL, char collisionT, char collisionG );
        int getPositionX ( int inc = 0 );
        int getPositionY ( int inc = 0 );
        int getWidth ( int inc = 0 );
        int getHeight ( int inc = 0 );
        void jump ( void );
        void jumpAnimation ( char collisionR, char collisionL, char collisionT, char collisionG );
        bool getJumping ( void );
        void setJumping ( bool value );
        sf::IntRect* getRect ( void );
    protected:
    private:
        sf::Texture* m_texture;
        sf::Sprite* m_sprite;
        sf::IntRect* m_rect;
        sf::Vector2i* m_A;
        sf::Vector2i* m_V;
        bool m_onGround;
        bool m_jumping;
        int m_jump;
        double m_currentFrame;
};

#endif // PLAYER_H
