#include "../../include/Decorator/Shoes.h"

Shoes::Shoes(Player* character, int posX, int posY) : AUpgrade(character, posX, posY)
{
  //ctor
}

Shoes::~Shoes()
{
  //dtor
}

int Shoes::getSpeed() {
  return m_character->getJumpSpeed() + 2;
}

int Shoes::getJumpSpeed(){
  return m_character->getJumpSpeed();
}

int Shoes::getJumpHeight(){
  return m_character->getJumpHeight();
}
