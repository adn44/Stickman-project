#include "GameManager.h"
#include <iostream>
// INIT
GameManager::GameManager(std::string const& title, int width, int height) {

    m_hero = new Hero("caisse.jpg");

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
    sf::Vector2f center(m_hero->pSkin()->getPosition().x + m_hero->pSkin()->getSize().x/2, m_hero->pSkin()->getPosition().y + m_hero->pSkin()->getSize().y/2);
    sf::Vector2f halfSize(m_screen->getWidth()/2, m_screen->getHeight()/2);
    m_view = new sf::View(center, halfSize);

    // set the view in the screen
    m_screen->SetView(*m_view);

    // game infinite loop
    while (m_screen->IsOpened())
    {
        update();
        draw();
    }
}

GameManager::~GameManager() {
}

void GameManager::controls() {
    if ( m_screen->GetInput().IsKeyDown(sf::Key::Right) && m_screen->GetInput().IsKeyDown(sf::Key::Escape) )
    {
        m_screen->Close();
    }
    else if(m_screen->GetInput().IsKeyDown(sf::Key::Right) && m_screen->GetInput().IsKeyDown(sf::Key::Space)) {
        std::cout << "droite2" << std::endl;
        if(!(collision() == "R"))
            m_hero->goRight();
        std::cout << "sauter3" << std::endl;
        if(!(collision() == "U"))
            m_hero->jump();
    }
    else if(m_screen->GetInput().IsKeyDown(sf::Key::Right)) {
        std::cout << "droite" << std::endl;
        if(!(collision() == "R"))
            m_hero->goRight();
    }
    else if(m_screen->GetInput().IsKeyDown(sf::Key::Left) && m_screen->GetInput().IsKeyDown(sf::Key::Space)) {
        std::cout << "gauche2" << std::endl;
        if(!(collision() == "L"))
            m_hero->goLeft();
        std::cout << "sauter2" << std::endl;
        if(!(collision() == "U"))
            m_hero->jump();
    }
    else if(m_screen->GetInput().IsKeyDown(sf::Key::Left)) {
        std::cout << "gauche" << std::endl;
        if(!(collision() == "L"))
            m_hero->goLeft();
    }
    else if(m_screen->GetInput().IsKeyDown(sf::Key::Space)) {
        std::cout << "sauter" << std::endl;
        if(!(collision() == "U"))
            m_hero->jump();
    }
}

std::string GameManager::collision() {

    /*// convert coords
    sf::Vector2f heroPos = m_screen->ConvertCoords(m_hero->skin().GetPosition().x, m_hero->skin().GetPosition().y);
    sf::Vector2f heroSize = m_screen->ConvertCoords(m_hero->skin().GetSize().x, m_hero->skin().GetSize().y);

    sf::Vector2f spritePos = m_screen->ConvertCoords(m_sprite->GetPosition().x, m_sprite->GetPosition().y);
    sf::Vector2f spriteSize = m_screen->ConvertCoords(m_sprite->GetPosition().x, m_sprite->GetPosition().y);*/

    // test collisions
    if(m_hero->skin().GetPosition().x + m_hero->skin().GetSize().x >= m_sprite->GetPosition().x // si on est avant la collision
       && m_hero->skin().GetPosition().x + m_hero->skin().GetSize().x <= m_sprite->GetPosition().x + m_sprite->GetSize().x // et si on n'est pas après la collision
       && m_hero->skin().GetPosition().y >= m_sprite->GetPosition().y // si l'objet est au même niveau que l'autre objet
       && m_hero->skin().GetPosition().y <= m_sprite->GetPosition().y + m_sprite->GetSize().y
       && m_hero->skin().GetPosition().y + m_hero->skin().GetSize().y >= m_sprite->GetPosition().y // pour le point bas
       && m_hero->skin().GetPosition().y + m_hero->skin().GetSize().y <= m_sprite->GetPosition().y + m_sprite->GetSize().y) {
        return "R";
    }
    else if (m_hero->skin().GetPosition().x <= m_sprite->GetPosition().x + m_sprite->GetSize().x
              && !(m_hero->skin().GetPosition().x <= m_sprite->GetPosition().x + m_sprite->GetSize().x - 1)
              && m_hero->skin().GetPosition().y >= m_sprite->GetPosition().y
              && m_hero->skin().GetPosition().y <= m_sprite->GetPosition().y + m_sprite->GetSize().y
              && m_hero->skin().GetPosition().y + m_hero->skin().GetSize().y >= m_sprite->GetPosition().y
              && m_hero->skin().GetPosition().y + m_hero->skin().GetSize().y <= m_sprite->GetPosition().y + m_sprite->GetSize().y){
        return "L";
    }
    else {
        return "N";
    }
}

void GameManager::update() {
    // Process events
    sf::Event event;
    while (m_screen->GetEvent(event))
    {
        // Close window : exit
        switch(event.Type)
        {
        case sf::Event::Closed:
            m_screen->Close();
            break;
        }
    }

    // check input
    controls();
    m_hero->jumpAnimation();

    // replace the center of the view to the hero position
    m_view->Move((m_hero->skin().GetPosition().x - m_view->GetCenter().x) + m_hero->skin().GetSize().x/2,
                 (m_hero->skin().GetPosition().y - m_view->GetCenter().y) + m_hero->skin().GetSize().y/2);
}

void GameManager::draw() {
    m_screen->Clear();
    m_screen->Draw(*m_sprite);
    m_hero->draw(m_screen);
    m_screen->Display();
}
