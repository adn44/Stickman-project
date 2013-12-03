#include "../../include/Factory/ConcreteFactory.h"

ConcreteFactory::ConcreteFactory() : AFactory()
{
}

ConcreteFactory::~ConcreteFactory()
{
}

IBlock* ConcreteFactory::build(char s){
  switch(s){
  case 'Q':
    m_block = new BlockGround1;
    break;
  case 'S':
    m_block = new BlockGround2;
    break;
  case 'D':
    m_block = new BlockGround3;
    break;
  default:
    std::cout << "empty block" << std::endl;
  }
  return m_block;
}
