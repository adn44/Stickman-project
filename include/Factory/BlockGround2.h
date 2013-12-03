/**
 * \file BlockGround2.h
 * \class BlockGround2
 * \brief Another concrete block that implements IBlock
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef BLOCKGROUND2_H
#define BLOCKGROUND2_H

#include "IBlock.h"

class BlockGround2 : public IBlock
{
 public:
  /** \brief Default constructor
   * \fn BlockGround2()
   */
  BlockGround2();

  /** \brief Default destructor
   * \fn virtual ~BlockGround2()
   */
  virtual ~BlockGround2();

  /** \brief Return the texture of the block
   * \fn sf::Texture* getTexture()
   * \return The texture of the block
   */
  sf::Texture* getTexture();

  /** \brief Return the sprite of the block
   * \fn sf::Sprite* getSprite()
   * \return The sprite of the block
   */
  sf::Sprite* getSprite();
 protected:
 private:
  sf::Texture* m_texture; ///< The texture of the block
  sf::Sprite* m_sprite; ///< The sprite of the block

};

#endif // BLOCKGROUND2_H
