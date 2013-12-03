/**
 * \file IBlock.h
 * \class IBlock
 * \brief Interface that will be implemented by all the different kinds of blocks
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef IBLOCK_H_INCLUDED
#define IBLOCK_H_INCLUDED

#include <SFML/Graphics.hpp>

class IBlock {
 public:
  /** \brief Return the texture of the block
   * \fn virtual sf::Texture* getTexture() = 0
   * \return The texture of the block
   */
  virtual sf::Texture* getTexture() = 0;

  /** \brief Return the sprite of the block
   * \fn virtual sf::Sprite* getSprite() = 0
   * \return The sprite of the block
   */
  virtual sf::Sprite* getSprite() = 0;
 protected:
 private:
};

#endif // IBLOCK_H_INCLUDED
