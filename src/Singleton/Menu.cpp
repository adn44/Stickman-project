#include "../../include/Singleton/Menu.h"
#include <iostream>

Menu::Menu ( void ) : m_saxguy(false)
{
   m_screen.reset(new sf::RenderWindow ( sf::VideoMode ( 640, 480 ), "Menu" ));
   m_screen->setVerticalSyncEnabled(true);

   m_bgTexture.reset(new sf::Texture);
   m_playTexture.reset(new sf::Texture);
   m_optionTexture.reset(new sf::Texture);
   m_activePlayTexture.reset(new sf::Texture);
   m_activeOptionTexture.reset(new sf::Texture);
   m_saxTexture.reset(new sf::Texture);
   m_saxDanceTexture.reset(new sf::Texture);

   if ( !m_bgTexture->loadFromFile ( "img/menu_background.png" )
         || !m_playTexture->loadFromFile ( "img/lancer_partie.png" )
         || !m_optionTexture->loadFromFile ( "img/options.png" )
         || !m_activePlayTexture->loadFromFile ( "img/lancer_partie_actif.png" )
         || !m_activeOptionTexture->loadFromFile ( "img/options_actif.png" )
         || !m_saxTexture->loadFromFile ( "img/menu_sax.jpg" )
         || !m_saxDanceTexture->loadFromFile ( "img/menu_sax1.jpg" ) )
   {
      exit ( EXIT_FAILURE );
   }

   m_bgSprite.reset(new sf::Sprite ( *m_bgTexture ));

   m_playSprite.reset(new sf::Sprite ( *m_playTexture ));
   m_playSprite->move ( 30, 180 );

   m_optionSprite.reset(new sf::Sprite ( *m_optionTexture ));
   m_optionSprite->move ( 37, m_playSprite->getPosition().y + m_playSprite->getLocalBounds().height + 30 );

   m_music.reset(new sf::Music);
   if(!m_music->openFromFile("music/menu.ogg")) {
      exit(EXIT_FAILURE);
   }
   m_music->setPlayingOffset(sf::seconds(5.5));
   m_music->setVolume(50);
   m_music->play();

   m_soundBuffer.reset(new sf::SoundBuffer);
   m_soundBuffer->loadFromFile("sound/button.ogg");

   m_sound.reset(new sf::Sound);
   m_sound->setBuffer(*m_soundBuffer);
   m_sound->setVolume(15);

   m_played = false;
   m_onButton = false;
}

Menu::~Menu ( void )
{
   std::cout << "DESTRUCT MENU" << std::endl;
}

void Menu::action() {
   if(!m_screen->isOpen())
      m_screen->create(sf::VideoMode ( 640, 480 ), "Menu");
   m_music->setPlayingOffset(sf::seconds(5.5));
   m_music->play();

   m_sound->setBuffer(*m_soundBuffer);
   m_sound->setVolume(15);

   double anim(0.0);
   m_saxguy = false;
   m_bgSprite->setTexture(*m_bgTexture);

   sf::Event event;
   sf::Vector2i mousePos(sf::Mouse::getPosition(*m_screen));
   while (m_screen->isOpen()) {
      while(m_screen->pollEvent(event))
      {
         if(event.type == sf::Event::Closed)
         {
            m_music->stop();
            m_screen->close();
         }
      }

      mousePos = sf::Mouse::getPosition(*m_screen);

      if(m_playSprite->getGlobalBounds().contains(mousePos.x, mousePos.y))
      {
         if(m_sound->getStatus() == sf::SoundSource::Stopped && !m_played) {
            m_sound->play();
            m_played = true;
         }
         m_playSprite->setTexture(*m_activePlayTexture);
         if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            m_music->stop();
            m_screen->close();
            GameManager& gameManager = GameManager::getInstance();
            gameManager.action();
         }
      }
      else {
         m_played = false;
         m_playSprite->setTexture(*m_playTexture);
      }

      if(m_optionSprite->getGlobalBounds().contains(mousePos.x, mousePos.y))
      {
         if(m_sound->getStatus() == sf::SoundSource::Stopped && m_onButton) {
            m_sound->play();
            m_onButton = false;
         }
         m_optionSprite->setTexture(*m_activeOptionTexture);
      }
      else {
         m_optionSprite->setTexture(*m_optionTexture);
         m_onButton = true;
      } 

      // easter eggs EPIC SAX GUY
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      {
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
               if(!m_music->openFromFile("music/saxguy.ogg")) {
                  exit(EXIT_FAILURE);
               }
               m_music->stop();
               m_music->play();
               m_saxguy = true;
            }
         }
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
      {
         m_music->stop();
      }

      // anim menu
      if(m_saxguy) {

         anim += 0.06;

         if(anim > 6.0)
            anim = 0.0;

         if((int)anim % 2 == 0) {
            m_bgSprite->setTexture(*m_saxTexture);
         }
         else if ((int)anim % 2 == 1) {
            m_bgSprite->setTexture(*m_saxDanceTexture);
         }

      }

      m_screen->clear();
      m_screen->draw(*m_bgSprite);
      m_screen->draw(*m_playSprite);
      m_screen->draw(*m_optionSprite);
      m_screen->display();
   }
}
