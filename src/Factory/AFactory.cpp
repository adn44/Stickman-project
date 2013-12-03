#include "../../include/Factory/AFactory.h"

AFactory::~AFactory(){
}

IBlock* AFactory::createBlock(char c) {
  m_block = build(c);
  return m_block;
}
