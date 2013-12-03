#include "../../include/Decorator/Cape.h"
#include <iostream>

Cape::Cape(Player* character, int posX, int posY) : AUpgrade(character, posX, posY)
{

}

Cape::~Cape()
{
  //dtor
}

int Cape::getJumpSpeed(){
  return m_character->getJumpSpeed() + 2;
}

int Cape::getJumpHeight(){
  return m_character->getJumpHeight() + 20;
}

int Cape::getSpeed() {
  return m_character->getSpeed();
}
