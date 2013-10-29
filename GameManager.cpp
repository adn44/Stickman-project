#include "GameManager.h"
#include <iostream>
// INIT
GameManager::GameManager(std::string const& title, int width, int height)
{

    m_hero = new Hero("fang.png");

    // blit a static texture
    m_texture = new sf::Texture;
    if(!m_texture->loadFromFile("caisse_ok.jpg"))
    {
        exit(EXIT_FAILURE);
    }
    m_sprite = new sf::Sprite(*m_texture);

    // define the screen, 60Hz
    m_screen = new sf::RenderWindow(sf::VideoMode(width, height), title);
    //m_screen->useVerticalSync(true);
    m_screen->setFramerateLimit(60);

    sf::Vector2f position(80, 0);
    m_sprite->move(position.x, position.y);

    sf::Vector2f position2(50, 0);
    m_hero->pSkin()->move(position2.x, position2.y);

    // define a View (2D camera)
    sf::Vector2f center(m_hero->pSkin()->getPosition().x + m_hero->pSkin()->getLocalBounds().width/2, m_hero->pSkin()->getPosition().y + m_hero->pSkin()->getLocalBounds().height/2);
    sf::Vector2f halfSize(m_screen->getSize().x/2, m_screen->getSize().y/2);
    m_view = new sf::View(center, halfSize);

    // set the view in the screen
    m_screen->setView(*m_view);

    // game infinite loop
    while (m_screen->isOpen())
    {
        update();
        draw();
    }
}

GameManager::~GameManager()
{
}

void GameManager::controls()
{
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
    {
        m_screen->close();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
            m_hero->goRight();
            m_hero->jump();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
            m_hero->goRight();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        std::cout << "gauche2" << std::endl;
        if(!(collision() == "L"))
            m_hero->goLeft();
        std::cout << "sauter2" << std::endl;
        if(!(collision() == "U"))
            m_hero->jump();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        std::cout << "gauche" << std::endl;
        if(!(collision() == "L"))
            m_hero->goLeft();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        std::cout << "sauter" << std::endl;
        if(!(collision() == "U"))
            m_hero->jump();
    }
}

std::string GameManager::collision()
{

    /*// convert coords
    sf::Vector2f heroPos = m_screen->ConvertCoords(m_hero->skin().getPosition().x, m_hero->skin().getPosition().y);
    sf::Vector2f heroSize = m_screen->ConvertCoords(m_hero->skin().getLocalBounds().x, m_hero->skin().getLocalBounds().y);

    sf::Vector2f spritePos = m_screen->ConvertCoords(m_sprite->getPosition().x, m_sprite->getPosition().y);
    sf::Vector2f spriteSize = m_screen->ConvertCoords(m_sprite->getPosition().x, m_sprite->getPosition().y);*/

    // test collisions
    if( m_hero->skin().getPosition().x + m_hero->skin().getLocalBounds().width >= m_sprite->getPosition().x // si on est avant la collision
            && m_hero->skin().getPosition().x + m_hero->skin().getLocalBounds().width <= m_sprite->getPosition().x + m_sprite->getLocalBounds().width // et si on n'est pas après la collision
            && m_hero->skin().getPosition().y >= m_sprite->getPosition().y // si l'objet est au même niveau que l'autre objet
            && m_hero->skin().getPosition().y <= m_sprite->getPosition().y + m_sprite->getLocalBounds().height
            && m_hero->skin().getPosition().y + m_hero->skin().getLocalBounds().height >= m_sprite->getPosition().y // pour le point bas
            && m_hero->skin().getPosition().y + m_hero->skin().getLocalBounds().height <= m_sprite->getPosition().y + m_sprite->getLocalBounds().height )
    {
        return "R";
    }
    else if ( m_hero->skin().getPosition().x <= m_sprite->getPosition().x + m_sprite->getLocalBounds().width
              && !(m_hero->skin().getPosition().x <= m_sprite->getPosition().x + m_sprite->getLocalBounds().width - 1)
              && m_hero->skin().getPosition().y >= m_sprite->getPosition().y
              && m_hero->skin().getPosition().y <= m_sprite->getPosition().y + m_sprite->getLocalBounds().height
              && m_hero->skin().getPosition().y + m_hero->skin().getLocalBounds().height >= m_sprite->getPosition().y
              && m_hero->skin().getPosition().y + m_hero->skin().getLocalBounds().height <= m_sprite->getPosition().y + m_sprite->getLocalBounds().height )
    {
        return "L";
    }
    else
    {
        return "N";
    }
}

void GameManager::update()
{
    // Process events
    sf::Event event;
    while (m_screen->pollEvent(event))
    {
        // Close window : exit
        switch(event.type)
        {
        case sf::Event::Closed:
            m_screen->close();
            break;
        default:
            break;
        }
    }

    // check input
    controls();
    m_hero->jumpAnimation();

    // replace the center of the view to the hero position
    m_view->move((m_hero->skin().getPosition().x - m_view->getCenter().x) + m_hero->skin().getLocalBounds().width/2,
                 (m_hero->skin().getPosition().y - m_view->getCenter().y) + m_hero->skin().getLocalBounds().height/2);
}

void GameManager::draw()
{
    m_screen->clear();
    m_screen->draw(*m_sprite);
    m_hero->draw(m_screen);
    m_screen->display();
}
