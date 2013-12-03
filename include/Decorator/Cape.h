/**
 * \file Cape.h
 * \class Cape
 * \brief Cape upgrade
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef CAPE_H
#define CAPE_H

#include "AUpgrade.h"

class Cape : public AUpgrade
{
 public:
  /** \brief Default constructor
   * \fn Cape(Player* character, int posX, int posY)
   * \param character Decorated character
   * \param posX Position x
   * \param posY Position y
   */
  Cape(Player* character, int posX, int posY);

  /** \brief Default destructor
   * \fn ~Cape()
   */
  virtual ~Cape();

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

#endif // CAPE_H
