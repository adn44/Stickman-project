/**
 * \file Menu.h
 * \class Menu
 * \brief Game menu
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "GameManager.h"

class Menu
{
   public:
      Menu(Menu const&) = delete;
      Menu(Menu&&) = delete;
      Menu& operator=(Menu const&) = delete;
      Menu& operator=(Menu&&) = delete;
      /** \brief Default destructor
       * \fn virtual ~Menu ( void )
       */
      virtual ~Menu ( void );

      /** \brief Get menu instance
       * \fn static Menu* getInstance(void)
       * \return Menu instance
       */
      static Menu& getInstance(void) {
         static Menu m_menu; ///< Instance
         return m_menu;
      }

      /** \brief Method that implements the behavior of the menu
       * \fn void action ( void )
       */
      void action ( void );
   protected:
   private:
      std::unique_ptr<sf::RenderWindow> m_screen{nullptr}; ///< Screen
      std::unique_ptr<sf::Texture> m_bgTexture{nullptr}; ///< Background texture
      std::unique_ptr<sf::Sprite> m_bgSprite{nullptr}; ///< Background sprite
      std::unique_ptr<sf::Texture> m_saxTexture{nullptr}; ///< Epic sax guy texture
      std::unique_ptr<sf::Texture> m_saxDanceTexture{nullptr}; ///< Epic sax guy dance texture
      std::unique_ptr<sf::Texture> m_playTexture{nullptr}; ///< Play button texture
      std::unique_ptr<sf::Sprite> m_playSprite{nullptr}; ///< Play button sprite
      std::unique_ptr<sf::Texture> m_activePlayTexture{nullptr}; ///< Active play button texture
      std::unique_ptr<sf::Texture> m_optionTexture{nullptr}; ///< Option button texture
      std::unique_ptr<sf::Sprite> m_optionSprite{nullptr}; ///< Option button sprite
      std::unique_ptr<sf::Texture> m_activeOptionTexture{nullptr}; ///< Active option button sprite
      std::unique_ptr<sf::Music> m_music{nullptr}; ///< Music of the game
      std::unique_ptr<sf::Sound> m_sound{nullptr}; ///< Sound of the buttons
      std::unique_ptr<sf::SoundBuffer> m_soundBuffer{nullptr}; ///< Sound buffer of the buttons
      bool m_played; ///< Boolean to know when the buttons sound has to be played or not
      bool m_onButton; ///< Boolean to know when the mouse is currently on the button
      bool m_saxguy; ///< Boolean to know when the EPIC SAX GUY mode is ON or OFF
      /** \brief Private constructor
       * \fn Menu ( void )
       */
      Menu ( void );
};

#endif // MENU_H
