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
#include <memory>
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
      GameManager(GameManager const&) = delete;
      GameManager(GameManager&&) = delete;
      GameManager& operator=(GameManager const&) = delete;
      GameManager& operator=(GameManager&&) = delete;

      /** \brief The default destructor
       * \fn virtual ~GameManager ( void )
       */
      virtual ~GameManager(void);

      /** \brief Give the instance of the class, and create it if it's required
       * \fn static GameManager* getInstance(void)
       * \return A pointer on the instance of the class
       */
      static GameManager& getInstance(void) {
         static GameManager gameManager(640,480, "Stickman-project");
         return gameManager;
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
      Player* m_player{nullptr}; ///< Pointer on the player
      std::unique_ptr<sf::RenderWindow> m_screen{nullptr}; ///< Pointer on the screen
      std::unique_ptr<sf::View> m_view{nullptr}; ///< Pointer on the view (2D camera)
      std::unique_ptr<ILevel> m_level{nullptr}; ///< Pointer on the level
      std::unique_ptr<char> m_colG{nullptr}; ///< Pointer to check the ground collision
      std::unique_ptr<char> m_colL{nullptr}; ///< Pointer to check the left collision
      std::unique_ptr<char> m_colT{nullptr}; ///< Pointer to check the top collision
      std::unique_ptr<char> m_colR{nullptr}; ///< Pointer to check the right collision
      std::unique_ptr<sf::Music> m_music{nullptr}; ///< Pointer to the music of the current level
      std::unique_ptr<sf::Sound> m_upgradeSound{nullptr}; ///< Pointer to the upgrade sound
      std::unique_ptr<sf::SoundBuffer> m_upgradeSoundBuffer{nullptr}; ///< Pointer to the buffer of the upgrade sound
      std::unique_ptr<sf::Sound> m_lostSound{nullptr}; ///< Pointer to the lost sound
      std::unique_ptr<sf::SoundBuffer> m_lostSoundBuffer{nullptr}; ///< Pointer to the buffer of the lost sound
      std::unique_ptr<sf::Sound> m_winSound{nullptr}; ///< Pointer to the win sound
      std::unique_ptr<sf::SoundBuffer> m_winSoundBuffer{nullptr}; ///< Pointer to the buffer of the win sound
      bool m_win{false}; ///< Boolean to check if the player has won, true if he has, false otherwise
      bool m_lost{false}; ///< Boolean to check if the player has lost, true if he has, false otherwise

      /** \brief Private constructor of the class
       * \fn GameManager ( int width, int height, std::string const& title )
       * \param width An integer representing the width of the screen
       * \param height An integer representing the height of the screen
       * \param title A string representing the title of the screen
       */
      GameManager ( int width, int height, std::string const& title );
};

#endif // GAMEMANAGER_H
