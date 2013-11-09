#include "GameManager.h"
GameManager::GameManager ( int width, int height, std::string const& title )
{
    // set up the screen
    m_screen = new sf::RenderWindow ( sf::VideoMode ( width, height ), title );
    m_screen->setVerticalSyncEnabled(true);
    m_screen->setFramerateLimit(60);

    // create the player
    m_player = new Player;

    // define a View (2D camera)
    m_view = new sf::View ( sf::FloatRect ( 0, 0, m_screen->getSize().x, m_screen->getSize().y ) );
    m_screen->setView ( *m_view );

    m_level = new LevelOne ( );

    m_colG = new char ( 'n' );
    m_colL = new char ( 'n' );
    m_colT = new char ( 'n' );
    m_colR = new char ( 'n' );
}

GameManager::~GameManager ( void )
{
}

void GameManager::action ( void )
{
    m_level->loadLevel ( m_player );

    // properly close the window on quit
    sf::Event event;
    while ( m_screen->isOpen ( ) )
    {
        while ( m_screen->pollEvent ( event ) )
        {
            if ( event.type == sf::Event::Closed )
            {
                m_screen->close ( );
            }
        }
        update ( );
        draw ( );
    }
}

void GameManager::collisionR ( void )
{
for ( sf::Sprite* r : *( m_level->getBlocks ( ) ) )
    {
        if ( m_player->getPositionX ( ) + m_player->getWidth ( ) == r->getPosition().x
                && ( ( m_player->getPositionY ( ) <= r->getPosition().y && r->getPosition().y < m_player->getPositionY ( ) + m_player->getHeight ( ) )
                    || ( r->getPosition().y <= m_player->getPositionY() && m_player->getPositionY() < r->getPosition().y + r->getGlobalBounds().height ) ) )
        {
            *m_colR = 'R';
        }
    }
}

void GameManager::collisionL ( void )
{
    for ( sf::Sprite* r : *( m_level->getBlocks ( ) ) )
    {
        if ( m_player->getPositionX ( ) == r->getPosition().x + r->getGlobalBounds().width
                && ( ( m_player->getPositionY ( ) <= r->getPosition().y && r->getPosition().y < m_player->getPositionY ( ) + m_player->getHeight ( ) )
                    || ( r->getPosition().y <= m_player->getPositionY ( ) && m_player->getPositionY ( ) < r->getPosition().y + r->getGlobalBounds().height ) ) )
        {
            *m_colL = 'L';
        }
    }
}

void GameManager::collisionT ( void )
{
    for(sf::Sprite* r : *( m_level->getBlocks ( ) ) )
    {
        if ( m_player->getPositionY ( ) == r->getPosition().y + r->getGlobalBounds().height
                && ( ( m_player->getPositionX() >= r->getPosition().x && m_player->getPositionX() < r->getPosition().x + r->getGlobalBounds().width )
                    || ( m_player->getPositionX ( ) + m_player->getWidth ( ) > r->getPosition().x && m_player->getPositionX ( ) + m_player->getWidth ( ) <= r->getPosition().x + r->getGlobalBounds().width ) ) )
        {
            m_player->setJumping ( false );
            *m_colT = 'T';
        }
    }
}

void GameManager::collisionG ( void )
{
    for(sf::Sprite* r : *( m_level->getBlocks ( ) ) )
    {
        if ( m_player->getPositionY ( ) + m_player->getHeight ( ) == r->getPosition().y
            && ( ( m_player->getPositionX ( ) >= r->getPosition().x && m_player->getPositionX ( ) < r->getPosition().x + r->getGlobalBounds().width )
            || ( m_player->getPositionX() + m_player->getWidth ( ) > r->getPosition().x && m_player->getPositionX ( ) + m_player->getWidth ( ) <= r->getPosition().x + r->getGlobalBounds().width ) ) )
        {
            m_player->setOnGround ( true );
            *m_colG = 'G';
        }
    }
}

void GameManager::update ( void )
{
    *m_colR = 'n', *m_colL = 'n', *m_colT = 'n', *m_colG = 'n';
    collisionR ( ); collisionL ( ); collisionT ( ); collisionG ( );

    m_player->controls ( *m_colR, *m_colL, *m_colT, *m_colG );
    m_player->jumpAnimation ( *m_colR, *m_colL, *m_colT, *m_colG );
    if ( *m_colG != 'G' && !( m_player->getJumping ( ) ) )
    {
        m_player->fall ( );
    }

    if ( true )
    {
        m_view->setCenter ( m_player->getPositionX ( ) + m_player->getWidth ( ) / 2, m_player->getPositionY ( ) + m_player->getWidth ( ) / 2 );
        m_screen->setView ( *m_view );
    }
}

void GameManager::draw ( void )
{
    m_screen->clear ( sf::Color::White );
    m_level->drawLevel ( m_screen );
    m_screen->draw ( *( m_player->getSprite ( ) ) );
    m_screen->display ( );
}
