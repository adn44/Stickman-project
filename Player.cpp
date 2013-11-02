#include "Player.h"

Player::Player() : m_onGround(false), m_jumping(false), m_currentFrame(0), m_dx(0), m_dy(0)
{
    m_texture = new sf::Texture;
    if (!m_texture->loadFromFile("fang.png"))
    {
        exit(EXIT_FAILURE);
    }

    m_rect = new sf::IntRect(0, 189, 40, 50);

    m_sprite = new sf::Sprite(*m_texture);
    m_sprite->setTextureRect(*m_rect);
}

Player::~Player()
{
    //dtor
}

sf::IntRect* Player::getRect() {
    return m_rect;
}

sf::Sprite* Player::getSprite()
{
    return m_sprite;
}

bool Player::getOnGround()
{
    return m_onGround;
}

void Player::setOnGround(bool value)
{
    m_onGround = value;
}

void Player::goRight()
{
    // move the player
    m_sprite->move(SPEED, 0);

    // set delta x
    m_dx = 1;

    // animation
    m_currentFrame += 0.08;

    if (m_currentFrame > 6)
        m_currentFrame -= 6;

    m_rect = new sf::IntRect(40*int(m_currentFrame), 244, 40, 50);
    m_sprite->setTextureRect(*m_rect);
}

void Player::goLeft()
{
    m_sprite->move(-SPEED, 0);
    m_dx = -1;

    m_currentFrame += 0.08;

    if (m_currentFrame > 6)
        m_currentFrame -= 6;

    m_rect = new sf::IntRect(40*int(m_currentFrame)+40, 244, -40, 50);
    m_sprite->setTextureRect(*m_rect);
}

void Player::fall()
{
    m_sprite->move(0, SPEED);
    m_dy = 1;
}

void Player::controls(char collisionR, char collisionL, char collisionT, char collisionG)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && collisionR != 'R')
    {
        goRight();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && collisionL != 'L')
    {
        goLeft();
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && collisionT != 'T' && collisionG == 'G')
    {
        jump();
    }
}

void Player::jump() {
    if(!m_jumping && m_onGround) {
        m_jump = JUMP_HEIGHT;
        m_jumping = true;
        m_dy = -1;
    }
}

void Player::jumpAnimation(char collisionR, char collisionL, char collisionT, char collisionG) {
    if (m_jumping)
    {
        if(m_jump == 0) {
            m_jumping = false;
            m_rect = new sf::IntRect(0, 189, 40, 50);
            m_sprite->setTextureRect(*m_rect);
        }
        else if (m_jump <= JUMP_HEIGHT/2 && collisionG != 'G') {
            m_sprite->move(0, SPEED);
        }
        else if (m_jump > JUMP_HEIGHT/2 && collisionT != 'T'){
            m_sprite->move(0, -SPEED);
        }

        m_jump--;
    }
}

int Player::getDx()
{
    return m_dx;
}

int Player::getDy(){
    return m_dy;
}

void Player::setDx( int value){
    m_dx = value;
}

void Player::setDy(int value){
    m_dy = value;
}

bool Player::getJumping() {
    return m_jumping;
}

void Player::setJumping(bool value) {
    m_jumping = value;
}
