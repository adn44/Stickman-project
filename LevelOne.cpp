#include "LevelOne.h"
#include <SFML/Graphics.hpp>

LevelOne::LevelOne ( void )
{
    m_tileMap = new std::vector<std::string>;
    m_tileMap->push_back ( "               " );
    m_tileMap->push_back ( "               " );
    m_tileMap->push_back ( "  P       QQQQ " );
    m_tileMap->push_back ( "         Q     " );
    m_tileMap->push_back ( "QQQQQ Q QQQQQQQ" );

    m_blocks = new std::vector<sf::Sprite*>;
    m_texture = new sf::Texture;
}

LevelOne::~LevelOne ( void )
{
}

int LevelOne::getHeight ( void )
{
    return m_tileMap->size ( );
}

int LevelOne::getWidth ( void )
{
    return m_tileMap->at(0).length ( );
}

void LevelOne::loadLevel ( Player* player )
{
    int n = 0;

    for ( int i=0; i<getHeight ( ); i++ )
    {
        for(int j=0; j<getWidth ( ); j++ )
        {
            switch ( ( m_tileMap->at ( i ) )[j] )
            {
            case 'Q':
                if ( !m_texture->loadFromFile ( "sol1.png" ) ) {
                    exit ( EXIT_FAILURE );
                }
                m_blocks->push_back ( new sf::Sprite ( *m_texture ) );
                m_blocks->at(n)->setPosition ( j*78, i*80 );
                n++;
                break;
            case 'P':
                player->getSprite()->setPosition ( j*80, i*80 );
                break;
            }
        }
    }
}

void LevelOne::drawLevel ( sf::RenderWindow* screen )
{
for ( sf::Sprite* s : *m_blocks )
    {
        screen->draw ( *s );
    }
}

std::vector<sf::Sprite*>* LevelOne::getBlocks ( void )
{
    return m_blocks;
}
