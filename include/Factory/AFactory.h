/**
 * \file AFactory.h
 * \class AFactory
 * \brief Provide a factory to create blocks
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef AFACTORY_H
#define AFACTORY_H

#include "IBlock.h"

class AFactory
{
 public:
  /** \brief Default destructor
   * \fn virtual ~AFactory()
   */
  virtual ~AFactory();

  /** \brief Create a block using the build() method
   * \fn IBlock* createBlock(char c)
   * \param c A char that indicate the block to construct
   * \return The block constructed
   */
  IBlock* createBlock(char c);

  /** \brief Create a block according to the given character
   * \fn virtual IBlock* build(char s) = 0
   * \param s A char that indicate the block to construct
   * \return The block constructed
   */
  virtual IBlock* build(char s) = 0;
 protected:
  IBlock* m_block; ///< The block constructed
 private:
};

#endif // AFACTORY_H
