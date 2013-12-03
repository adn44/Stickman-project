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
#include "GameManager.h"

class Menu
{
 public:
  /** \brief Default destructor
   * \fn virtual ~Menu ( void )
   */
  virtual ~Menu ( void );

  /** \brief Get menu instance
   * \fn static Menu* getInstance(void)
   * \return Menu instance
   */
  static Menu* getInstance(void) {
    if(!m_menu)
      m_menu = new Menu();
    return m_menu;
  }

  /** \brief Method that implements the behavior of the menu
   * \fn void action ( void )
   */
  void action ( void );
 protected:
 private:
  static Menu* m_menu; ///< Instance
  sf::RenderWindow* m_screen; ///< Screen
  sf::Texture* m_bgTexture; ///< Background texture
  sf::Sprite* m_bgSprite; ///< Background sprite
  sf::Texture* m_saxTexture; ///< Epic sax guy texture
  sf::Texture* m_saxDanceTexture; ///< Epic sax guy dance texture
  sf::Texture* m_playTexture; ///< Play button texture
  sf::Sprite* m_playSprite; ///< Play button sprite
  sf::Texture* m_activePlayTexture; ///< Active play button texture
  sf::Texture* m_optionTexture; ///< Option button texture
  sf::Sprite* m_optionSprite; ///< Option button sprite
  sf::Texture* m_activeOptionTexture; ///< Active option button sprite
  sf::Music* m_music; ///< Music of the game
  sf::Sound* m_sound; ///< Sound of the buttons
  sf::SoundBuffer* m_soundBuffer; ///< Sound buffer of the buttons
  bool m_played; ///< Boolean to know when the buttons sound has to be played or not
  bool m_onButton; ///< Boolean to know when the mouse is currently on the button
  bool m_saxguy; ///< Boolean to know when the EPIC SAX GUY mode is ON or OFF
  /** \brief Private constructor
   * \fn Menu ( void )
   */
  Menu ( void );
};

#endif // MENU_H
