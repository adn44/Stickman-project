/**
 * \file Shoes.h
 * \class Shoes
 * \brief Shoes class
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef SHOES_H
#define SHOES_H

#include "AUpgrade.h"

class Shoes : public AUpgrade
{
 public:
  /** \brief Default constructor
   * \fn Shoes(Player* character, int posX, int posY)
   * \param character Decorated character
   * \param posX Position x
   * \param posY Position y
   */
  Shoes(Player* character, int posX, int posY);

  /** \brief Default destructor
   * \fn ~Shoes()
   */
  virtual ~Shoes();

  /** \brief Get the jumping speed value
   * \fn virtual int getJumpSpeed()
   * \return Jump speed value
   */
  virtual int getJumpSpeed();

  /** \brief Get the jumping height value
   * \fn virtual int getJumpHeight()
   * \return Jumping height value
   */
  virtual int getJumpHeight();

  /** \brief Get the speed value
   * \fn virtual int getSpeed()
   * \return Speed value
   */
  virtual int getSpeed();
 protected:
 private:
};

#endif // SHOES_H
