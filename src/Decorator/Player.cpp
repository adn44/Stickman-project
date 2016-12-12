#include "../../include/Decorator/Player.h"

Player::Player(int x, int y) : m_onGround(false), m_jumping(false), m_dx(0), m_dy(0), m_currentFrame(0.0)
{
   m_texture.reset(new sf::Texture);
   for (auto& t : m_animTab)
      t.reset(new sf::Texture);

   m_jumpTexture.reset(new sf::Texture);
   m_fallTexture.reset(new sf::Texture);

   if (!m_texture->loadFromFile("img/normal_gauche.png")
         || !m_animTab[0]->loadFromFile("img/run1.png")
         || !m_animTab[1]->loadFromFile("img/run2.png")
         || !m_animTab[2]->loadFromFile("img/run3.png")
         || !m_animTab[3]->loadFromFile("img/run4.png")
         || !m_animTab[4]->loadFromFile("img/run5.png")
         || !m_animTab[5]->loadFromFile("img/run6.png")
         || !m_jumpTexture->loadFromFile("img/jump.png")
         || !m_fallTexture->loadFromFile("img/fall.png"))
   {
      exit(EXIT_FAILURE);
   }

   m_sprite.reset(new sf::Sprite(*m_texture));
   m_sprite->setPosition(x, y);

   m_jumpSoundBuffer.reset(new sf::SoundBuffer);
   m_jumpSoundBuffer->loadFromFile("sound/saut.ogg");

   m_jumpSound.reset(new sf::Sound);
   m_jumpSound->setBuffer(*m_jumpSoundBuffer);
   m_jumpSound->setVolume(60);

   m_speed = 2;
   m_jumpSpeed = 3;
   m_jumpHeight = 100;
}

Player::~Player()
{
   //dtor
}

sf::Sprite* Player::getSprite()
{
   return m_sprite.get();
}

sf::IntRect* Player::getRect() {
   return m_rect.get();
}

bool Player::getOnGround()
{
   return m_onGround;
}

void Player::setOnGround(bool value)
{
   m_onGround = value;
}

void Player::goRight(){
   m_sprite->setTexture(*m_animTab[0]);
   m_rect.reset(new sf::IntRect(0, 0, 35, 80));
   m_sprite->setTextureRect(*m_rect);

   m_sprite->move(getSpeed(), 0);
   m_dx = 1;

   m_currentFrame += 0.08;
   if (m_currentFrame > 6)
      m_currentFrame = 0.0;

   m_sprite->setTexture(*(m_animTab[(int)m_currentFrame]));
}

void Player::goLeft(){
   m_sprite->setTexture(*m_animTab[0]);
   m_rect.reset(new sf::IntRect(35, 0, -35, 80));
   m_sprite->setTextureRect(*m_rect);

   m_sprite->move(-getSpeed(), 0);
   m_dx = -1;

   m_currentFrame += 0.08;
   if (m_currentFrame > 6)
      m_currentFrame = 0.0;

   m_sprite->setTexture(*(m_animTab[(int)m_currentFrame]));
}

void Player::fall(){
   m_sprite->move(0, m_jumpSpeed);
   m_sprite->setTexture(*m_fallTexture);
}

void Player::controls(char collisionR, char collisionL, char collisionT, char collisionG){
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && collisionR != 'R'){
      goRight();
   }
   else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && collisionL != 'L'){
      goLeft();
   }
   else{
      m_sprite->setTexture(*m_texture);
   }

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && collisionT != 'T' && collisionG == 'G'){
      jump();
   }
}

void Player::jump() {
   if(!m_jumping && m_onGround) {
      m_jump = getJumpHeight();
      m_jumping = true;
      m_jumpSound->play();
   }
}

void Player::jumpAnimation(char collisionR, char collisionL, char collisionT, char collisionG) {
   if (m_jumping)
   {
      if(m_jump == 0 || ( collisionG == 'G' && m_jump <= getJumpHeight()/2 ) ) {
         m_jumping = false;
      }
      else if (m_jump <= getJumpHeight()/2 && collisionG != 'G') {
         m_sprite->move(0, getJumpSpeed());
         m_sprite->setTexture(*m_fallTexture);
      }
      else if (m_jump > getJumpHeight()/2 && collisionT != 'T') {
         m_sprite->move(0, -getJumpSpeed());
         m_sprite->setTexture(*m_jumpTexture);
      }
      m_jump--;
   }
}

int Player::getPositionX( int inc ) {
   return m_sprite->getPosition().x + inc;
}

int Player::getPositionY( int inc ) {
   return m_sprite->getPosition().y + inc;
}

int Player::getWidth( int inc ) {
   return m_sprite->getGlobalBounds().width + inc;
}

int Player::getHeight( int inc ) {
   return m_sprite->getGlobalBounds().height + inc;
}

bool Player::getJumping() {
   return m_jumping;
}

void Player::setJumping(bool value) {
   m_jumping = value;
}

int Player::getSpeed(){
   return m_speed;
}

int Player::getJumpSpeed(){
   return m_jumpSpeed;
}

int Player::getJumpHeight(){
   return m_jumpHeight;
}

void Player::setSpeed(int speed){
   m_speed = speed;
}

void Player::setJumpSpeed(int jumpSpeed){
   m_jumpSpeed = jumpSpeed;
}

void Player::setJumpHeight(int jumpHeight){
   m_jumpHeight = jumpHeight;
}

sf::Texture* Player::getTexture(){
   return m_texture.get();
}

sf::Texture* Player::getRunTexture1(){
   return m_animTab[0].get();
}
sf::Texture* Player::getRunTexture2(){
   return m_animTab[1].get();
}
sf::Texture* Player::getRunTexture3(){
   return m_animTab[2].get();
}
sf::Texture* Player::getRunTexture4(){
   return m_animTab[3].get();
}
sf::Texture* Player::getRunTexture5(){
   return m_animTab[4].get();
}
sf::Texture* Player::getRunTexture6(){
   return m_animTab[5].get();
}

sf::Sound* Player::getJumpSound(){
   return m_jumpSound.get();
}
sf::SoundBuffer* Player::getJumpSoundBuffer(){
   return m_jumpSoundBuffer.get();
}
int Player::getJump(){
   return m_jump;
}
double Player::getCurrentFrame(){
   return m_currentFrame;
}
