/**
 * \file AUpgrade.h
 * \class AUpgrade
 * \brief Abstract class for the upgrades
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef AUPGRADE_H
#define AUPGRADE_H

#include "Player.h"

class AUpgrade : public Player
{
 public:
  /** \brief Default constructor
   * \fn AUpgrade()
   */
  AUpgrade();

  /** \brief Another constructor
   * \fn AUpgrade(Player* character, int x, int y)
   * \param character Decorated character
   * \param x Position x
   * \param y Position y
   */
  AUpgrade(Player* character, int x, int y);

  /** \brief Default destructor
   * \fn virtual ~AUpgrade()
   */
  virtual ~AUpgrade();
 protected:
  Player* m_character; ///< Decorated character
 private:
};

#endif // AUPGRADE_H
