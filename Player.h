#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

const int SPEED = 1;
const int JUMP_HEIGHT = 80;

class Player
{
    public:
        Player();
        virtual ~Player();
        sf::Sprite* getSprite();
        bool getOnGround();
        void setOnGround(bool value);
        void goRight();
        void goLeft();
        void fall();
        void controls(char collisionR, char collisionL, char collisionT, char collisionG);
        int getDx();
        int getDy();
        void setDx( int value);
        void setDy(int value);
        void jump();
        void jumpAnimation(char collisionR, char collisionL, char collisionT, char collisionG);
        bool getJumping();
        void setJumping(bool value);
        sf::IntRect* getRect();
    protected:
    private:
        sf::Texture* m_texture;
        sf::Sprite* m_sprite;
        sf::IntRect* m_rect;
        bool m_onGround;
        bool m_jumping;
        int m_jump;
        double m_currentFrame;
        int m_dx;
        int m_dy;
};

#endif // PLAYER_H
