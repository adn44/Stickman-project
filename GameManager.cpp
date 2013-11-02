#include "GameManager.h"

GameManager::GameManager(int width, int height, std::string const& title)
{
    // set up the screen
    m_screen = new sf::RenderWindow(sf::VideoMode(width,height), title);
    m_screen->setVerticalSyncEnabled(true);
    m_screen->setFramerateLimit(60);

    // create the player
    m_player = new Player;

    // define a View (2D camera)
    m_view = new sf::View(sf::FloatRect(0, 0, m_screen->getSize().x, m_screen->getSize().y));
    m_screen->setView(*m_view);

    // load the map
    m_tileMap[0] = "  P  ";
    m_tileMap[1] = "  B  ";
    m_tileMap[2] = "     ";
    m_tileMap[3] = "    B";
    m_tileMap[4] = "B B B";
}

GameManager::~GameManager()
{
}

void GameManager::action()
{
    sf::RectangleShape r(sf::Vector2f(40,32));
    r.setFillColor(sf::Color::Black);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            switch(m_tileMap[i][j])
            {
            case 'B':
                r.setPosition(j*40,i*32);
                m_screen->draw( r );
                break;
            case 'P':
                m_player->getSprite()->setPosition(j*40, i*32);
                break;
            }
        }
    }

    sf::Event event;
    while(m_screen->isOpen())
    {
        while(m_screen->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                m_screen->close();
            }
        }

        update();
        draw();
    }
}

char GameManager::collisionR()
{
    sf::RectangleShape r(sf::Vector2f(40,32));
    r.setFillColor(sf::Color::Black);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            r.setPosition(j*40,i*32);
            switch(m_tileMap[i][j])
            {
                case 'B':
                    if(m_player->getSprite()->getPosition().x + m_player->getSprite()->getGlobalBounds().width == r.getPosition().x
                            && ((m_player->getSprite()->getPosition().y <= r.getPosition().y && r.getPosition().y < m_player->getSprite()->getPosition().y + m_player->getSprite()->getGlobalBounds().height)
                                || (r.getPosition().y <= m_player->getSprite()->getPosition().y && m_player->getSprite()->getPosition().y < r.getPosition().y + r.getGlobalBounds().height)))
                    {
                        return 'R';
                    }
                    break;
            }
        }
    }
    return 'n';
}

char GameManager::collisionL(){
    sf::RectangleShape r(sf::Vector2f(40,32));
    r.setFillColor(sf::Color::Black);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            r.setPosition(j*40,i*32);
            switch(m_tileMap[i][j])
            {
                case 'B':
                    if(m_player->getSprite()->getPosition().x == r.getPosition().x + r.getGlobalBounds().width
                            && ((m_player->getSprite()->getPosition().y <= r.getPosition().y && r.getPosition().y < m_player->getSprite()->getPosition().y + m_player->getSprite()->getGlobalBounds().height)
                                || (r.getPosition().y <= m_player->getSprite()->getPosition().y && m_player->getSprite()->getPosition().y < r.getPosition().y + r.getGlobalBounds().height)))
                    {
                        return 'L';
                    }
                    break;
            }
        }
    }
    return 'n';
}

char GameManager::collisionT(){
    sf::RectangleShape r(sf::Vector2f(40,32));
    r.setFillColor(sf::Color::Black);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            r.setPosition(j*40,i*32);
            switch(m_tileMap[i][j])
            {
                case 'B':
                    if(m_player->getSprite()->getPosition().y == r.getPosition().y + r.getGlobalBounds().height
                    && ((m_player->getSprite()->getPosition().x >= r.getPosition().x && m_player->getSprite()->getPosition().x < r.getPosition().x + r.getGlobalBounds().width)
                        || (m_player->getSprite()->getPosition().x + m_player->getSprite()->getGlobalBounds().width > r.getPosition().x && m_player->getSprite()->getPosition().x + m_player->getSprite()->getGlobalBounds().width <= r.getPosition().x + r.getGlobalBounds().width)))
                    {
                        m_player->setJumping(false);
                        return 'T';
                    }
                    break;
            }
        }
    }
    return 'n';
}

char GameManager::collisionG(){
    sf::RectangleShape r(sf::Vector2f(40,32));
    r.setFillColor(sf::Color::Black);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            switch(m_tileMap[i][j])
            {
                case 'B':
                    r.setPosition(j*40,i*32);
                    if(r.getGlobalBounds().intersects(m_player->getSprite()->getGlobalBounds()))
                    {
                        m_player->getSprite()->move(0,-SPEED);
                        m_player->setOnGround(true);
                        return 'G';
                    }
                    break;
            }
        }
    }
    return 'n';
}

void GameManager::update()
{
    m_player->controls(collisionR(), collisionL(), collisionT(), collisionG());

    m_player->jumpAnimation(collisionR(), collisionL(), collisionT(), collisionG());

    if (collisionG() != 'G' && !(m_player->getJumping()))
    {
        m_player->fall();
    }

    if(true){
        m_view->setCenter(m_player->getSprite()->getPosition().x + m_player->getSprite()->getGlobalBounds().width/2, m_player->getSprite()->getPosition().y + m_player->getSprite()->getGlobalBounds().height/2);
        m_screen->setView(*m_view);
    }
}

void GameManager::draw()
{
    m_screen->clear(sf::Color::White);

    sf::RectangleShape r(sf::Vector2f(40,32));
    r.setFillColor(sf::Color::Black);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            switch(m_tileMap[i][j])
            {
            case 'B':
                r.setPosition(j*40,i*32);
                m_screen->draw( r );
                break;
            }
        }
    }

    m_screen->draw(*(m_player->getSprite()));
    m_screen->display();
}
