/**
 * \file GameManager.h
 * \class GameManager
 * \brief Provide an instance to manage the game
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Decorator/Player.h"
#include "../Strategy/ILevel.h"
#include "../Strategy/LevelOne.h"
#include "../Strategy/LevelTwo.h"
#include "Menu.h"
#include "../Decorator/Cape.h"
#include "../Decorator/Shoes.h"

class GameManager
{
 public:
  /** \brief The default destructor
   * \fn virtual ~GameManager ( void )
   */
  virtual ~GameManager(void);

  /** \brief Give the instance of the class, and create it if it's required
   * \fn static GameManager* getInstance(void)
   * \return A pointer on the instance of the class
   */
  static GameManager* getInstance(void) {
    if(!m_gameManager)
      m_gameManager = new GameManager(640,480, "Stickman-project");
    return m_gameManager;
  }

  /** \brief Set up the parameters and run the game loop
   * \fn void action ( void )
   */
  void action ( void );

  /** \brief Update the data of the game
   * \fn void update ( void )
   */
  void update ( void );

  /** \brief Draw the elements of the game on the screen
   * \fn void draw ( void )
   */
  void draw ( void );

  /** \brief Check if the player is colliding with an object on his right
   * \fn void collisionR ( void )
   */
  void collisionR ( void );

  /** \brief Check if the player is colliding with an object on his left
   * \fn void collisionL ( void )
   */
  void collisionL ( void );

  /** \brief Check if the player is colliding with an object on his top
   * \fn void collisionT ( void )
   */
  void collisionT ( void );

  /** \brief Check if the player is on the ground
   * \fn void collisionG ( void )
   */
  void collisionG ( void );
 protected:
 private:
  static GameManager* m_gameManager; ///< Static pointer on the unique instance of the class
  Player* m_player; ///< Pointer on the player
  sf::RenderWindow* m_screen; ///< Pointer on the screen
  sf::View* m_view; ///< Pointer on the view (2D camera)
  ILevel* m_level; ///< Pointer on the level
  char* m_colG; ///< Pointer to check the ground collision
  char* m_colL; ///< Pointer to check the left collision
  char* m_colT; ///< Pointer to check the top collision
  char* m_colR; ///< Pointer to check the right collision
  bool m_win; ///< Boolean to check if the player has won, true if he has, false otherwise
  bool m_lost; ///< Boolean to check if the player has lost, true if he has, false otherwise
  sf::Music* m_music; ///< Pointer to the music of the current level
  sf::Sound* m_upgradeSound; ///< Pointer to the upgrade sound
  sf::SoundBuffer* m_upgradeSoundBuffer; ///< Pointer to the buffer of the upgrade sound
  sf::Sound* m_lostSound; ///< Pointer to the lost sound
  sf::SoundBuffer* m_lostSoundBuffer; ///< Pointer to the buffer of the lost sound
  sf::Sound* m_winSound; ///< Pointer to the win sound
  sf::SoundBuffer* m_winSoundBuffer; ///< Pointer to the buffer of the win sound

  /** \brief Private constructor of the class
   * \fn GameManager ( int width, int height, std::string const& title )
   * \param width An integer representing the width of the screen
   * \param height An integer representing the height of the screen
   * \param title A string representing the title of the screen
   */
  GameManager ( int width, int height, std::string const& title );
};

#endif // GAMEMANAGER_H
