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
    m_newSprite->move(30, m_continueSprite->getPosition().y + m_continueSprite->getLocalBounds().height + 15);

    m_optionTexture = new sf::Texture;
    m_optionSprite = new sf::Sprite;
    loadSprite(m_optionTexture, m_optionSprite, "menu_bouton3.png");
    m_optionSprite->move(30, m_newSprite->getPosition().y + m_newSprite->getLocalBounds().height + 15);


    // define the screen, 60Hz
    m_screen = new sf::RenderWindow(sf::VideoMode(width, height), title);
    m_screen->setVerticalSyncEnabled(true);
    m_screen->setFramerateLimit(60);

    // game infinite loop
    while (m_screen->isOpen())
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
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(sf::Mouse::getPosition().x >= m_newSprite->getPosition().x && sf::Mouse::getPosition().x <= m_newSprite->getPosition().x + m_newSprite->getGlobalBounds().width
           && sf::Mouse::getPosition().y >= m_newSprite->getPosition().y && sf::Mouse::getPosition().y <= m_newSprite->getPosition().y + m_newSprite->getGlobalBounds().height)
           {
                std::cout << "mouse: " << sf::Mouse::getPosition().x << " | " << sf::Mouse::getPosition().y << std::endl;
               m_screen->close();
               GameManager gm("Jeu", 800, 600);
           }
    }
}

void Menu::update()
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
