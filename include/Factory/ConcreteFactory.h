/**
 * \file ConcreteFactory.h
 * \class ConcreteFactory
 * \brief A concrete factory to create blocks
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H

#include <iostream>
#include "AFactory.h"
#include "IBlock.h"
#include "BlockGround1.h"
#include "BlockGround2.h"
#include "BlockGround3.h"

class ConcreteFactory : public AFactory
{
 public:
  /** \brief Default constructor
   * \fn ConcreteFactory()
   */
  ConcreteFactory();

  /** \brief Default destructor
   * \fn ~ConcreteFactory()
   */
  ~ConcreteFactory();

  /** \brief Create a block according to the given character
   * \fn virtual IBlock* build(char s)
   * \param s A char that indicate the block to construct
   * \return The block constructed
   */
  virtual IBlock* build(char s);
 protected:
 private:
};

#endif // CONCRETEFACTORY_H
