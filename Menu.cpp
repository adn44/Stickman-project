#include "Menu.h"

Menu::Menu(std::string const& title, int width, int height)
{
    // blit a static picture
    m_backgroundTexture = new sf::Texture;
    m_backgroundSprite = new sf::Sprite;
    loadSprite(m_backgroundTexture, m_backgroundSprite, "menu_background.png");

    m_continueTexture = new sf::Texture;
    m_continueSprite = new sf::Sprite;
    loadSprite(m_continueTexture, m_continueSprite, "menu_bouton1.png");
    m_continueSprite->move(30, 130);

    m_newTexture = new sf::Texture;
    m_newSprite = new sf::Sprite;
    loadSprite(m_newTexture, m_newSprite, "menu_bouton2.png");
    m_newSprite->move(30, m_continueSprite->getPosition().y + m_continueSprite->getSize().y + 15);

    m_optionTexture = new sf::Texture;
    m_optionSprite = new sf::Sprite;
    loadSprite(m_optionTexture, m_optionSprite, "menu_bouton3.png");
    m_optionSprite->move(30, m_newSprite->getPosition().y + m_newSprite->getSize().y + 15);


    // define the screen, 60Hz
    m_screen = new sf::RenderWindow(sf::VideoMode(width, height), title);
    m_screen->useVerticalSync(true);
    m_screen->setFramerateLimit(60);

    // game infinite loop
    while (m_screen->isOpened())
    {
        update();
        draw();
    }
}

Menu::~Menu()
{
}

void Menu::controls()
{
    /*if(m_screen->GetInput().IsMouseButtonDown(sf::Mouse::Left)){
        if(m_screen->GetInput().GetMouseX() >= m_hero->skin().GetPosition().x && m_screen->GetInput().GetMouseX() <= m_hero->skin().GetPosition().x + m_hero->skin().GetSize().x
           && m_screen->GetInput().GetMouseY() >= m_hero->skin().GetPosition().y && m_screen->GetInput().GetMouseY() <= m_hero->skin().GetPosition().y + m_hero->skin().GetSize().y)
           {
               m_screen->Close();
               GameManager gm("Jeu", 800, 600);
           }
    }*/
}

void Menu::update()
{
        // Process events
        sf::Event event;
        while (m_screen->getEvent(event))
        {
            // Close window : exit
            switch(event.type)
            {
            case sf::Event::Closed:
                m_screen->close();
                break;
            }
        }

        controls();
}

void Menu::draw()
{
    m_screen->clear();
    m_screen->draw(*m_backgroundSprite);
    m_screen->draw(*m_continueSprite);
    m_screen->draw(*m_newSprite);
    m_screen->draw(*m_optionSprite);
    m_screen->display();
}
