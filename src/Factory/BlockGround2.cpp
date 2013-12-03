#include "../../include/Factory/BlockGround2.h"

BlockGround2::BlockGround2()
{
  m_texture = new sf::Texture;
  if(!m_texture->loadFromFile("img/sol2.png")){
    exit(EXIT_FAILURE);
  }
  m_sprite = new sf::Sprite(*m_texture);
}

BlockGround2::~BlockGround2()
{
  //dtor
}

sf::Sprite* BlockGround2::getSprite(){
  return m_sprite;
}

sf::Texture* BlockGround2::getTexture(){
  return m_texture;
}

