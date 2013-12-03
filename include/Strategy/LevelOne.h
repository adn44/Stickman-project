/**
 * \file LevelOne.h
 * \class LevelOne
 * \brief Implements the first level of the game
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef LEVELONE_H_INCLUDED
#define LEVELONE_H_INCLUDED

#include <vector>
#include <iostream>
#include "ILevel.h"
#include "../Decorator/Player.h"
#include "../Factory/AFactory.h"
#include "LevelTwo.h"

class LevelOne : public ILevel
{
 public:
  /** \brief Default constructor
   * \fn LevelOne ( void )
   */
  LevelOne ( void );

  /** \brief Default destructor
   * \fn ~LevelOne ( void )
   */
  ~LevelOne ( void );

  /** \brief Get the height of the level
   * \fn int getHeight ( void )
   * \return The height of the level
   */
  int getHeight ( void );

  /** \brief Get the width of the level
   * \fn int getWidth ( void )
   * \return The width of the level
   */
  int getWidth ( void );

  /** \brief Load the level and the player according the tile map
   * \fn virtual void loadLevel ( Player* player )
   * \param player The pointer to the player, so the method can set his position
   */
  virtual void loadLevel ( Player* player );

  /** \brief Draw all the elements of the level on the given screen
   * \fn virtual void drawLevel ( sf::RenderWindow* screen )
   * \param screen The screen where the elements will be displayed
   */
  virtual void drawLevel ( sf::RenderWindow* screen );

  /** \brief Get the blocks of the level
   * \fn virtual std::vector<sf::Sprite*>* getBlocks ( void )
   * \return A vector with all the elements
   */
  virtual std::vector<sf::Sprite*>* getBlocks ( void );

  /** \brief Get a pointer on the sprite of the end
   * \fn virtual sf::Sprite* getEndSprite ( void )
   * \return The pointer on the sprite of the end
   */
  virtual sf::Sprite* getEndSprite ( void );

  /** \brief Get a pointer on the sprite of the cape
   * \fn virtual sf::Sprite* getCapeSprite ( void )
   * \return The pointer on the sprite of the cape
   */
  virtual sf::Sprite* getCapeSprite();

  /** \brief Get a pointer on the sprite of the shoes
   * \fn virtual sf::Sprite* getShoesSprite ( void )
   * \return The pointer on the sprite of the shoes
   */
  virtual sf::Sprite* getShoesSprite();

  /** \brief Remove an element from the map
   * \fn virtual void removeElement(char target)
   * \param target Character representing the element to remove
   */
  virtual void removeElement(char target);

  /** \brief Get the next level
   * \fn virtual ILevel* getNext(void) = 0
   * \return Next level, NULL if this is the last level
   */
  virtual ILevel* getNext(void);
 private:
  std::vector<std::string>* m_tileMap; ///< The tile map (i.e. the map of the level)
  std::vector<sf::Sprite*>* m_blocks; ///< Contains all the elements of the level
  IBlock* m_block; ///< Constructed block
  sf::Texture* m_endTexture; ///< Texture of the end sprite
  sf::Sprite* m_endSprite; ///< Sprite of the end sprite
  AFactory* m_factory; ///< The factory that will create the blocks
  sf::Texture* m_capeTexture; ///< Cape texture
  sf::Sprite* m_capeSprite; ///< Cape sprite
  sf::Texture* m_shoesTexture; ///< Shoes texture
  sf::Sprite* m_shoesSprite; ///< Shoes sprite
  ILevel* m_next; ///< Next level
  bool m_drawCape; ///< Boolean to know when the cape has to be draw or not
  bool m_drawShoes; ///< Boolean to know when the shoes has to be draw or not
};

#endif // LEVELONE_H_INCLUDED
