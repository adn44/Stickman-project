#include "../../include/Strategy/LevelTwo.h"

LevelTwo::LevelTwo ( void )
{
  m_tileMap = new std::vector<std::string>;
  m_tileMap->push_back ( "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ" );
  m_tileMap->push_back ( "Q       D    D       DDD                                                       Q" );
  m_tileMap->push_back ( "Q       D             D                                                       EQ" );
  m_tileMap->push_back ( "QA                                                    QQQQQQQQQQQQQQQQQQQQQQQQQQ" );
  m_tileMap->push_back ( "QQQ                             SQQQQQQQQQQQQQQQQQQQQQ        Q                 " );
  m_tileMap->push_back ( "Q      Q           QSSSS SSD  Q                               Q                 " );
  m_tileMap->push_back ( "Q P     QQ                          DDD                       Q                 " );
  m_tileMap->push_back ( "Q    Q     D              O        S   S                      Q                 " );
  m_tileMap->push_back ( "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ                 " );

  m_blocks = new std::vector<sf::Sprite*>;
  m_factory = new ConcreteFactory;

  m_endTexture = new sf::Texture;
  if(!m_endTexture->loadFromFile("img/end.png")) {
    exit(EXIT_FAILURE);
  }

  m_endSprite = new sf::Sprite(*m_endTexture);

  m_capeTexture = new sf::Texture;
  if(!m_capeTexture->loadFromFile("img/cape.png")){
    exit(EXIT_FAILURE);
  }
  m_capeSprite = new sf::Sprite(*m_capeTexture);

  m_drawCape = true;
  m_drawShoes = true;

  m_next = NULL;

  m_shoesTexture = new sf::Texture;
  if(!m_shoesTexture->loadFromFile("img/shoes.png")) {
    exit(EXIT_FAILURE);
  }

  m_shoesSprite = new sf::Sprite(*m_shoesTexture);
}

LevelTwo::~LevelTwo ( void )
{
}

int LevelTwo::getHeight ( void )
{
  return m_tileMap->size ( );
}

int LevelTwo::getWidth ( void )
{
  return m_tileMap->at(0).length ( );
}

void LevelTwo::loadLevel ( Player* player )
{
  int n = 0;

  for ( int i=0; i<getHeight ( ); i++ )
    {
      for(int j=0; j<getWidth ( ); j++ )
        {
	  switch ( ( m_tileMap->at ( i ) )[j] )
            {
	    case 'P':
	      player->getSprite()->setPosition ( j*78, i*80 );
	      break;
	    case 'E':
	      m_endSprite->setPosition(j*78, i*80);
	      break;
	    case 'A':
	      m_capeSprite->setPosition(j*78,i*80);
	      break;
	    case 'O':
	      m_shoesSprite->setPosition(j*78,i*80);
	      break;
	    case ' ':
	      break;
	    default:
	      m_block = m_factory->createBlock((m_tileMap->at(i))[j]);
	      m_blocks->push_back(m_block->getSprite());
	      m_blocks->at(n)->setPosition(j*78, i*80);
	      n++;
	      break;
            }
        }
    }
}

void LevelTwo::drawLevel ( sf::RenderWindow* screen )
{
  for ( sf::Sprite* s : *m_blocks )
    {
      screen->draw ( *s );
    }

  screen->draw(*m_endSprite);

  if(m_drawCape){
    screen->draw(*m_capeSprite);
  }

  if(m_drawShoes){
    screen->draw(*m_shoesSprite);
  }
}

std::vector<sf::Sprite*>* LevelTwo::getBlocks ( void )
{
  return m_blocks;
}

sf::Sprite* LevelTwo::getEndSprite ( void ) {
  return m_endSprite;
}

sf::Sprite* LevelTwo::getCapeSprite(){
  return m_capeSprite;
}

sf::Sprite* LevelTwo::getShoesSprite(){
  return m_shoesSprite;
}

void LevelTwo::removeElement(char target){
  if(target == 'A'){
    m_drawCape = false;
    m_capeSprite->setPosition(-500, -500);
  }
  else if(target == 'O'){
    m_drawShoes = false;
    m_shoesSprite->setPosition(-500, -500);
  }
}

ILevel* LevelTwo::getNext(void) {
  return m_next;
}
