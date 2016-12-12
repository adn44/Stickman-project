#include "../../include/Singleton/GameManager.h"

GameManager::GameManager ( int width, int height, std::string const& title )
{
   // set up the screen
   m_screen.reset(new sf::RenderWindow ( sf::VideoMode ( width, height ), title ));
   m_screen->setVerticalSyncEnabled(true);
   //m_screen->setFramerateLimit(60);

   // create the player
   m_player = new Player;

   // define a View (2D camera)
   m_view.reset(new sf::View ( sf::FloatRect ( 0, 0, m_screen->getSize().x, m_screen->getSize().y ) ));
   m_screen->setView ( *m_view );

   m_level.reset(new LevelOne);

   m_colG.reset(new char ( 'n' ));
   m_colL.reset(new char ( 'n' ));
   m_colT.reset(new char ( 'n' ));
   m_colR.reset(new char ( 'n' ));

   m_music.reset(new sf::Music);
   if(!m_music->openFromFile("music/level1.ogg")) {
      exit(EXIT_FAILURE);
   }
   m_music->setPlayingOffset(sf::seconds(14));
   m_music->play();

   m_lostSoundBuffer.reset(new sf::SoundBuffer);
   m_lostSoundBuffer->loadFromFile("sound/SF-yehaw.ogg");

   m_upgradeSoundBuffer.reset(new sf::SoundBuffer);
   m_upgradeSoundBuffer->loadFromFile("sound/SF-yehaw.ogg");

   m_upgradeSound.reset(new sf::Sound);
   m_upgradeSound->setBuffer(*m_upgradeSoundBuffer);
   m_upgradeSound->setVolume(50);

   m_lostSound.reset(new sf::Sound);
   m_lostSound->setBuffer(*m_lostSoundBuffer);
   m_lostSound->setVolume(50);

   m_winSoundBuffer.reset(new sf::SoundBuffer);
   m_winSoundBuffer->loadFromFile("sound/SF-crowd1.ogg");

   m_winSound.reset(new sf::Sound);
   m_winSound->setBuffer(*m_winSoundBuffer);
   m_winSound->setVolume(60);
}

GameManager::~GameManager ( void )
{
   delete m_player;
   m_player = nullptr;
}

void GameManager::action ( void )
{
   if(!m_screen->isOpen())
        m_screen->create(sf::VideoMode ( 640, 480 ), "Stickman-project");
   m_level->loadLevel ( m_player );
   m_win = false;
   m_lost = false;

   // properly close the window on quit
   sf::Event event;
   while ( m_screen->isOpen ( ) )
   {
      while ( m_screen->pollEvent ( event ) )
      {
         if ( event.type == sf::Event::Closed )
         {
            m_music->stop();
            m_screen->close ( );
            Menu& menu = Menu::getInstance();
            menu.action();
         }
      }
      update ( );
      draw ( );
   }
}

void GameManager::collisionR ( void )
{
   int tmp = m_player->getPositionX() + m_player->getWidth();
   for ( sf::Sprite* r : *( m_level->getBlocks ( ) ) )
   {
      if ( m_player->getPositionX ( ) + m_player->getWidth ( )  >= r->getPosition().x
            && !(r->getPosition().x + 10 < m_player->getPositionX())
            && ( ( m_player->getPositionY ( ) <= r->getPosition().y && r->getPosition().y < m_player->getPositionY ( ) + m_player->getHeight ( ) )
               || ( r->getPosition().y <= m_player->getPositionY() && m_player->getPositionY() < r->getPosition().y + r->getGlobalBounds().height ) ) )
      {
         m_player->getSprite()->setPosition(m_player->getPositionX(-(tmp - r->getPosition().x)), m_player->getPositionY());
         *m_colR = 'R';
      }
   }

   if ( m_player->getPositionX ( ) + m_player->getWidth ( )  >= m_level->getEndSprite()->getPosition().x
         && !(m_level->getEndSprite()->getPosition().x + 10 < m_player->getPositionX())
         && ( ( m_player->getPositionY ( ) <= m_level->getEndSprite()->getPosition().y && m_level->getEndSprite()->getPosition().y < m_player->getPositionY ( ) + m_player->getHeight ( ) )
            || ( m_level->getEndSprite()->getPosition().y <= m_player->getPositionY() && m_player->getPositionY() < m_level->getEndSprite()->getPosition().y + m_level->getEndSprite()->getGlobalBounds().height ) ) )
   {
      m_win = true;
   }

   if ( m_player->getPositionX ( ) + m_player->getWidth ( )  >= m_level->getCapeSprite()->getPosition().x
         && !(m_level->getCapeSprite()->getPosition().x + 10 < m_player->getPositionX())
         && ( ( m_player->getPositionY ( ) <= m_level->getCapeSprite()->getPosition().y && m_level->getCapeSprite()->getPosition().y < m_player->getPositionY ( ) + m_player->getHeight ( ) )
            || ( m_level->getCapeSprite()->getPosition().y <= m_player->getPositionY() && m_player->getPositionY() < m_level->getCapeSprite()->getPosition().y + m_level->getCapeSprite()->getGlobalBounds().height ) ) )
   {
      m_level->removeElement('A');
      m_player = new Cape(m_player, m_player->getPositionX(), m_player->getPositionY());
      m_upgradeSound->play();
   }

   if ( m_player->getPositionX ( ) + m_player->getWidth ( )  >= m_level->getShoesSprite()->getPosition().x
         && !(m_level->getShoesSprite()->getPosition().x + 10 < m_player->getPositionX())
         && ( ( m_player->getPositionY ( ) <= m_level->getShoesSprite()->getPosition().y && m_level->getShoesSprite()->getPosition().y < m_player->getPositionY ( ) + m_player->getHeight ( ) )
            || ( m_level->getShoesSprite()->getPosition().y <= m_player->getPositionY() && m_player->getPositionY() < m_level->getShoesSprite()->getPosition().y + m_level->getShoesSprite()->getGlobalBounds().height ) ) )
   {
      m_level->removeElement('O');
      m_player = new Shoes(m_player, m_player->getPositionX(), m_player->getPositionY());
      m_upgradeSound->play();
   }
}

void GameManager::collisionL ( void )
{
   int tmp = m_player->getPositionX();
   for ( sf::Sprite* r : *( m_level->getBlocks ( ) ) )
   {
      if ( m_player->getPositionX ( ) <= r->getPosition().x + r->getGlobalBounds().width
            && !(r->getPosition().x + r->getLocalBounds().width - 15 > m_player->getPositionX())
            && ( ( m_player->getPositionY ( ) <= r->getPosition().y && r->getPosition().y < m_player->getPositionY ( ) + m_player->getHeight ( ) )
               || ( r->getPosition().y <= m_player->getPositionY ( ) && m_player->getPositionY ( ) < r->getPosition().y + r->getGlobalBounds().height ) ) )
      {
         //std::cout << tmp << " | " << r->getPosition().x + r->getLocalBounds().width << " | " << ((int)(tmp + r->getPosition().x + r->getLocalBounds().width)) % (80*2+80) << std::endl;
         m_player->getSprite()->setPosition(m_player->getPositionX(r->getPosition().x + r->getLocalBounds().width - tmp), m_player->getPositionY());
         *m_colL = 'L';
      }
   }

   if ( m_player->getPositionX ( ) <= m_level->getCapeSprite()->getPosition().x + m_level->getCapeSprite()->getGlobalBounds().width
         && !(m_level->getCapeSprite()->getPosition().x + m_level->getCapeSprite()->getLocalBounds().width - 15 > m_player->getPositionX())
         && ( ( m_player->getPositionY ( ) <= m_level->getCapeSprite()->getPosition().y && m_level->getCapeSprite()->getPosition().y < m_player->getPositionY ( ) + m_player->getHeight ( ) )
            || ( m_level->getCapeSprite()->getPosition().y <= m_player->getPositionY ( ) && m_player->getPositionY ( ) < m_level->getCapeSprite()->getPosition().y + m_level->getCapeSprite()->getGlobalBounds().height ) ) )
   {
      m_level->removeElement('A');
      m_player = new Cape(m_player, m_player->getPositionX(), m_player->getPositionY());
      m_upgradeSound->play();
   }

   if ( m_player->getPositionX ( ) <= m_level->getShoesSprite()->getPosition().x + m_level->getShoesSprite()->getGlobalBounds().width
         && !(m_level->getShoesSprite()->getPosition().x + m_level->getShoesSprite()->getLocalBounds().width - 15 > m_player->getPositionX())
         && ( ( m_player->getPositionY ( ) <= m_level->getShoesSprite()->getPosition().y && m_level->getShoesSprite()->getPosition().y < m_player->getPositionY ( ) + m_player->getHeight ( ) )
            || ( m_level->getShoesSprite()->getPosition().y <= m_player->getPositionY ( ) && m_player->getPositionY ( ) < m_level->getShoesSprite()->getPosition().y + m_level->getShoesSprite()->getGlobalBounds().height ) ) )
   {
      m_level->removeElement('O');
      m_player = new Shoes(m_player, m_player->getPositionX(), m_player->getPositionY());
      m_upgradeSound->play();
   }
}

void GameManager::collisionT ( void )
{
   for(sf::Sprite* r : *( m_level->getBlocks ( ) ) )
   {
      if ( m_player->getPositionY ( ) >= r->getPosition().y + r->getGlobalBounds().height
            && (r->getGlobalBounds().contains(m_player->getPositionX(), m_player->getPositionY(-m_player->getJumpSpeed()))
               || r->getGlobalBounds().contains(m_player->getPositionX(m_player->getWidth()), m_player->getPositionY(-m_player->getJumpSpeed())))
            && !(r->getPosition().y + r->getLocalBounds().height - 10 > m_player->getPositionY())
            && ( ( m_player->getPositionX() >= r->getPosition().x && m_player->getPositionX() < r->getPosition().x + r->getGlobalBounds().width )
               || ( m_player->getPositionX ( ) + m_player->getWidth ( ) > r->getPosition().x && m_player->getPositionX ( ) + m_player->getWidth ( ) <= r->getPosition().x + r->getGlobalBounds().width ) ) )
      {
         m_player->setJumping ( false );
         //std::cout << tmp << " | " << r->getPosition().y + r->getLocalBounds().height << " | " << tmp - (r->getPosition().y + r->getLocalBounds().height) << std::endl;
         *m_colT = 'T';
      }
   }

   /*if (  m_player->getPositionY ( ) >= m_level->getCapeSprite()->getPosition().y + m_level->getCapeSprite()->getGlobalBounds().height
     && (m_level->getCapeSprite()->getGlobalBounds().contains(m_player->getPositionX(), m_player->getPositionY(-m_player->getJumpSpeed()))
     || m_level->getCapeSprite()->getGlobalBounds().contains(m_player->getPositionX(m_player->getWidth()), m_player->getPositionY(-m_player->getJumpSpeed())))
     && !(m_level->getCapeSprite()->getPosition().y + m_level->getCapeSprite()->getLocalBounds().height - 10 > m_player->getPositionY())
     && ( ( m_player->getPositionX() >= m_level->getCapeSprite()->getPosition().x && m_player->getPositionX() < m_level->getCapeSprite()->getPosition().x + m_level->getCapeSprite()->getGlobalBounds().width )
     || ( m_player->getPositionX ( ) + m_player->getWidth ( ) > m_level->getCapeSprite()->getPosition().x && m_player->getPositionX ( ) + m_player->getWidth ( ) <= m_level->getCapeSprite()->getPosition().x + m_level->getCapeSprite()->getGlobalBounds().width ) ) )
     {
     m_level->removeElement('A');
     m_player = new Cape(m_player, m_player->getPositionX(), m_player->getPositionY());
     m_upgradeSound->play();
     }*/
}

void GameManager::collisionG ( void )
{
   int tmp = m_player->getPositionY(m_player->getHeight());
   for(sf::Sprite* r : *( m_level->getBlocks ( ) ) )
   {
      if ( m_player->getPositionY ( ) + m_player->getHeight ( ) >= r->getPosition().y
            && !(r->getPosition().y + 15 < m_player->getPositionY())
            && (r->getGlobalBounds().contains(m_player->getPositionX(), m_player->getPositionY(m_player->getHeight(m_player->getJumpSpeed())))
               || r->getGlobalBounds().contains(m_player->getPositionX(m_player->getWidth()), m_player->getPositionY(m_player->getHeight(m_player->getJumpSpeed()))))
            && ( ( m_player->getPositionX ( ) >= r->getPosition().x && m_player->getPositionX ( ) < r->getPosition().x + r->getGlobalBounds().width - 6 )
               || ( m_player->getPositionX() + m_player->getWidth ( ) > r->getPosition().x + 6 && m_player->getPositionX ( ) + m_player->getWidth ( ) <= r->getPosition().x + r->getGlobalBounds().width ) ) )
      {
         //std::cout << tmp << " | " << r->getPosition().y << " | " << tmp - r->getPosition().y << std::endl;
         if ( tmp - r->getPosition().y > 0)
            m_player->getSprite()->move(0, -(tmp - r->getPosition().y));
         m_player->setOnGround ( true );
         *m_colG = 'G';
      }
   }
}

void GameManager::update ( void )
{
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
   {
      m_music->stop();
   }

   if(!m_lost && !m_win) {
      *m_colR = 'n', *m_colL = 'n', *m_colT = 'n', *m_colG = 'n';
      collisionG ( );
      collisionR ( );
      collisionL ( );
      collisionT ( );

      m_player->controls ( *m_colR, *m_colL, *m_colT, *m_colG );
      m_player->jumpAnimation ( *m_colR, *m_colL, *m_colT, *m_colG );
      if ( *m_colG != 'G' && !( m_player->getJumping ( ) ) )
      {
         m_player->fall ( );
      }

      m_view->setCenter ( m_player->getPositionX ( ) + m_player->getWidth ( ) / 2, m_player->getPositionY ( ) + m_player->getWidth ( ) / 2 );
      m_screen->setView ( *m_view );

      if(m_view->getCenter().y >= m_level->getHeight() * 80 + 100)
         m_lost = true;
   }
   else if(m_lost) {
      m_lost = false;
      m_music->setVolume(40);
      m_lostSound->setVolume(80);
      m_lostSound->play();
      m_screen->close();
      Menu& m = Menu::getInstance();
      m.action();
   }
   else if(m_win) {
      if(m_level->getNext()) {
         m_win = false;
         m_winSound->setVolume(80);
         m_winSound->play();
         m_player = new Player;
         m_level.reset(m_level->getNext());
         m_level->loadLevel(m_player);
      }
      else {
         m_win = false;
         m_music->stop();
         m_winSound->setVolume(80);
         m_winSound->play();

         m_screen->close();
         Menu& m = Menu::getInstance();
         m.action();
      }
   }
   //std::cout << *m_colG << *m_colL << *m_colR << *m_colT << std::endl;
   //std::cout << m_view->getCenter().y << std::endl;
   //std::cout << m_player->getPositionX() << " | " << m_player->getPositionY() << " | " << m_player->getJumpHeight() << " | " << m_player->getJumpSpeed() << std::endl;
}

void GameManager::draw ( void )
{
   m_screen->clear ( sf::Color::White );
   m_level->drawLevel ( m_screen.get() );
   m_screen->draw ( *( m_player->getSprite() ) );
   m_screen->display ( );
}
