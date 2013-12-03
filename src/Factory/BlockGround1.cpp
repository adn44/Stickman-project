#include "../../include/Factory/BlockGround1.h"

BlockGround1::BlockGround1()
{
  m_texture = new sf::Texture;
  if(!m_texture->loadFromFile("img/sol1.png")){
    exit(EXIT_FAILURE);
  }
  m_sprite = new sf::Sprite(*m_texture);
}

BlockGround1::~BlockGround1()
{
  //dtor
}

sf::Sprite* BlockGround1::getSprite(){
  return m_sprite;
}

sf::Texture* BlockGround1::getTexture(){
  return m_texture;
}
