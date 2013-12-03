/**
 * \file BlockGround1.h
 * \class BlockGround1
 * \brief A concrete block that implements IBlock
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef BLOCKGROUND1_H
#define BLOCKGROUND1_H

#include "IBlock.h"

class BlockGround1 : public IBlock
{
 public:
  /** \brief Default constructor
   * \fn BlockGround1()
   */
  BlockGround1();

  /** \brief Default destructor
   * \fn virtual ~BlockGround1()
   */
  virtual ~BlockGround1();

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

#endif // BLOCKGROUND1_H
