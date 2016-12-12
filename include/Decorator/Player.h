/**
 * \file Player.h
 * \class Player
 * \brief Player class
 * \author Adrien Bodineau and Alexandre Gomes
 * \version 1.0
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>

class Player
{
   public:
      /** \brief Default constructor
       * \fn Player(int x = 0, int y = 0)
       * \param x Position x
       * \param y Position y
       */
      Player(int x = 0, int y = 0);

      /** \brief Default destructor
       * \fn virtual ~Player ( void )
       */
      virtual ~Player ( void );

      /** \brief Set onGround
       * \fn virtual void setOnGround ( bool value )
       * \param value New value of onGround
       */
      virtual void setOnGround ( bool value );

      /** \brief Function to make the player go to the right
       * \fn virtual void goRight ( void )
       */
      virtual void goRight ( void );

      /** \brief Function to make the player go to the left
       * \fn virtual void goLeft ( void )
       */
      virtual void goLeft ( void );

      /** \brief Function to make the player fall
       * \fn virtual void fall ( void )
       */
      virtual void fall ( void );

      /** \brief Indicate what the player have to do according to the collisions and the press buttons
       * \fn virtual void controls ( char collisionR, char collisionL, char collisionT, char collisionG )
       * \param collisionR Character to indicate the right collision
       * \param collisionL Character to indicate the left collision
       * \param collisionT Character to indicate the top collision
       * \param collisionG Character to indicate the ground collision
       */
      virtual void controls ( char collisionR, char collisionL, char collisionT, char collisionG );

      /** \brief Set up the jump
       * \fn virtual void jump ( void )
       */
      virtual void jump ( void );

      /** \brief Make the player jump
       * \fn virtual void jumpAnimation ( char collisionR, char collisionL, char collisionT, char collisionG )
       * \param collisionR
       * \param collisionL
       * \param collisionT
       * \param collisionG
       */
      virtual void jumpAnimation ( char collisionR, char collisionL, char collisionT, char collisionG );

      /** \brief Set the jumping value
       * \fn virtual void setJumping ( bool value )
       * \param value New value of jumping
       */
      virtual void setJumping ( bool value );

      /** \brief Set the speed value
       * \fn virtual void setSpeed(int speed)
       * \param speed New value of speed
       */
      virtual void setSpeed(int speed);

      /** \brief Set the jumping speed value
       * \fn virtual void setJumpSpeed(int jumpSpeed)
       * \param jumpSpeed New value of jump speed
       */
      virtual void setJumpSpeed(int jumpSpeed);

      /** \brief Set the jumping height value
       * \fn virtual void setJumpHeight(int jumpHeight)
       * \param jumpHeight New value of jumping height
       */
      virtual void setJumpHeight(int jumpHeight);

      /** \brief Get the rect of the player
       * \fn virtual sf::IntRect* getRect ( void )
       * \return Player's rect
       */
      virtual sf::IntRect* getRect ( void );

      /** \brief Get the jumping value
       * \fn virtual bool getJumping ( void )
       * \return Jumping value
       */
      virtual bool getJumping ( void );

      /** \brief Get the speed value
       * \fn virtual int getSpeed()
       * \return Speed value
       */
      virtual int getSpeed();

      /** \brief Get the jumping speed value
       * \fn virtual int getJumpSpeed()
       * \return Jump speed value
       */
      virtual int getJumpSpeed();

      /** \brief Get the jumping height value
       * \fn virtual int getJumpHeight()
       * \return Jumping height value
       */
      virtual int getJumpHeight();

      /** \brief Get the sprite of the player
       * \fn virtual sf::Sprite* getSprite ( void )
       * \return Sprite of the player
       */
      virtual sf::Sprite* getSprite ( void );

      /** \brief Get the boolean onGround
       * \fn virtual bool getOnGround ( void )
       * \return Value of onGround
       */
      virtual bool getOnGround ( void );

      /** \brief Get the position x
       * \fn virtual int getPositionX ( int inc = 0 )
       * \param inc Get the position x+inc
       * \return Position x
       */
      virtual int getPositionX ( int inc = 0 );

      /** \brief Get the position y
       * \fn virtual int getPositionY ( int inc = 0 )
       * \param inc Get the position y+inc
       * \return Position y
       */
      virtual int getPositionY ( int inc = 0 );

      /** \brief Get the player's width
       * \fn virtual int getWidth ( int inc = 0 )
       * \return Player's width
       */
      virtual int getWidth ( int inc = 0 );

      /** \brief Get the player's height
       * \fn virtual int getHeight ( int inc = 0 )
       * \return Player's height
       */
      virtual int getHeight ( int inc = 0 );

      /** \brief Get the player's texture
       * \fn virtual sf::Texture* getTexture()
       * \return Player's texture
       */
      virtual sf::Texture* getTexture();

      /** \brief Get the player's run texture 1
       * \fn virtual sf::Texture* getRunTexture1()
       * \return Player's run texture 1
       */
      virtual sf::Texture* getRunTexture1();

      /** \brief Get the player's run texture 2
       * \fn virtual sf::Texture* getRunTexture2()
       * \return Player's run texture 2
       */
      virtual sf::Texture* getRunTexture2();

      /** \brief Get the player's run texture 3
       * \fn virtual sf::Texture* getRunTexture3()
       * \return Player's run texture 3
       */
      virtual sf::Texture* getRunTexture3();

      /** \brief Get the player's run texture 4
       * \fn virtual sf::Texture* getRunTexture4()
       * \return Player's run texture 4
       */
      virtual sf::Texture* getRunTexture4();

      /** \brief Get the player's run texture 5
       * \fn virtual sf::Texture* getRunTexture5()
       * \return Player's run texture 5
       */
      virtual sf::Texture* getRunTexture5();

      /** \brief Get the player's run texture 6
       * \fn virtual sf::Texture* getRunTexture6()
       * \return Player's run texture 6
       */
      virtual sf::Texture* getRunTexture6();

      /** \brief Get the jump sound
       * \fn virtual sf::Sound* getJumpSound()
       * \return Jump sound
       */
      virtual sf::Sound* getJumpSound();

      /** \brief Get the jump sound buffer
       * \fn virtual sf::SoundBuffer* getJumpSoundBuffer()
       * \return Jump sound buffer
       */
      virtual sf::SoundBuffer* getJumpSoundBuffer();

      /** \brief Get the value of jump
       * \fn virtual int getJump()
       * \return Jump value
       */
      virtual int getJump();

      /** \brief Get the player's current frame
       * \fn virtual double getCurrentFrame()
       * \return Player's current frame
       */
      virtual double getCurrentFrame();
   protected:
         std::unique_ptr<sf::Texture> m_texture{nullptr}; ///< Player's texture
         std::array<std::unique_ptr<sf::Texture>, 6> m_animTab; ///< Array of the run textures
         std::unique_ptr<sf::Texture> m_jumpTexture{nullptr}; ///< Player's jump texture
         std::unique_ptr<sf::Texture> m_fallTexture{nullptr}; ///< Player's fall texture
         std::unique_ptr<sf::Sprite> m_sprite{nullptr}; ///< Player's sprite
         std::unique_ptr<sf::Sound> m_jumpSound{nullptr}; ///< Jump sound
         std::unique_ptr<sf::SoundBuffer> m_jumpSoundBuffer{nullptr}; ///< Jump sound buffer
         std::unique_ptr<sf::IntRect> m_rect{nullptr}; ///< Player's rect
         int m_dx; ///< Position x
         int m_dy; ///< Position y
         bool m_onGround; ///< Boolean to know if the player is on the ground
         bool m_jumping; ///< Boolean to know if the player is jumping
         int m_jump; ///< Value of the jump
         double m_currentFrame; ///< Value of the current frame
         int m_speed; ///< Player's speed
         int m_jumpSpeed; ///< Jump speed
         int m_jumpHeight; ///< Jump height
};

#endif // PLAYER_H
