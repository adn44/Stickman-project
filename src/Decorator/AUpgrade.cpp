#include "../../include/Decorator/AUpgrade.h"
#include <iostream>

AUpgrade::AUpgrade(Player* character, int x, int y) : Player(x, y){
    m_character = character;
}

AUpgrade::~AUpgrade()
{
    //dtor
}
