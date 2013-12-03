#include "../../include/Factory/BlockGround3.h"

BlockGround3::BlockGround3()
{
  m_texture = new sf::Texture;
  if(!m_texture->loadFromFile("img/sol3.png")){
    exit(EXIT_FAILURE);
  }
  m_sprite = new sf::Sprite(*m_texture);
}

BlockGround3::~BlockGround3()
{
  //dtor
}

sf::Sprite* BlockGround3::getSprite(){
  return m_sprite;
}

sf::Texture* BlockGround3::getTexture(){
  return m_texture;
}

