/**
 * \file ILevel.h
 * \class ILevel
 * \brief Interface that will be implemented by the levels
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef ILEVEL_H_INCLUDED
#define ILEVEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Decorator/Player.h"
#include "../Factory/AFactory.h"
#include "../Factory/ConcreteFactory.h"

class ILevel
{
 public:
  /** \brief Default destructor
   * \fn virtual ~ILevel(){}
   */
  virtual ~ILevel(){};

  /** \brief Get the height of the level
   * \fn virtual int getHeight ( void ) = 0
   * \return The height of the level
   */
  virtual int getHeight ( void ) = 0;

  /** \brief Get the width of the level
   * \fn virtual int getWidth ( void ) = 0
   * \return The width of the level
   */
  virtual int getWidth ( void ) = 0;

  /** \brief Load the level and the player according the tile map
   * \fn virtual void loadLevel(Player* player) = 0
   * \param player The pointer to the player, so the method can set his position
   */
  virtual void loadLevel(Player* player) = 0;

  /** \brief Draw all the elements of the level on the given screen
   * \fn virtual void drawLevel(sf::RenderWindow* screen) = 0
   * \param screen The screen where the elements will be displayed
   */
  virtual void drawLevel(sf::RenderWindow* screen) = 0;

  /** \brief Get the blocks of the level
   * \fn virtual std::vector<sf::Sprite*>* getBlocks() = 0
   * \return A vector with all the elements
   */
  virtual std::vector<sf::Sprite*>* getBlocks() = 0;

  /** \brief Get the sprite of the end
   * \fn virtual sf::Sprite* getEndSprite ( void ) = 0
   * \return The sprite of the end
   */
  virtual sf::Sprite* getEndSprite ( void ) = 0;

  /** \brief Get the next level
   * \fn virtual ILevel* getNext(void) = 0
   * \return Next level, NULL if this is the last level
   */
  virtual ILevel* getNext(void) = 0;

  /** \brief Get the sprite of the cape
   * \fn virtual sf::Sprite* getCapeSprite() = 0
   * \return Sprite of the cape
   */
  virtual sf::Sprite* getCapeSprite() = 0;

  /** \brief Get the sprite of the shoes
   * \fn virtual sf::Sprite* getShoesSprite() = 0
   * \return Sprite of the shoes
   */
  virtual sf::Sprite* getShoesSprite() = 0;

  /** \brief Remove an element from the map
   * \fn virtual void removeElement(char target) = 0
   * \param target Character representing the element to remove
   */
  virtual void removeElement(char target) = 0;
};

#endif // ILEVEL_H_INCLUDED
