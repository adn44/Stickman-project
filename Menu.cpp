#include "Menu.h"

Menu::Menu()
{
    m_screen = new sf::RenderWindow(sf::VideoMode(640,480), "Menu");

    m_bgTexture = new sf::Texture;
    m_playTexture = new sf::Texture;
    m_optionTexture = new sf::Texture;
    m_activePlayTexture = new sf::Texture;
    m_activeOptionTexture = new sf::Texture;

    if (!m_bgTexture->loadFromFile("menu_background.png")
        || !m_playTexture->loadFromFile("lancer_partie.png")
        || !m_optionTexture->loadFromFile("options.png")
        || !m_activePlayTexture->loadFromFile("lancer_partie_actif.png")
        || !m_activeOptionTexture->loadFromFile("options_actif.png"))
    {
        exit(EXIT_FAILURE);
    }

    m_bgSprite = new sf::Sprite(*m_bgTexture);

    m_playSprite = new sf::Sprite(*m_playTexture);
    m_playSprite->move(30, 180);

    m_optionSprite = new sf::Sprite(*m_optionTexture);
    m_optionSprite->move(37, m_playSprite->getPosition().y + m_playSprite->getLocalBounds().height + 30);
}

Menu::~Menu()
{
}

void Menu::action() {
    sf::Event event;
    while (m_screen->isOpen()) {
        while(m_screen->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                m_screen->close();
            }
        }

        if(sf::Mouse::getPosition(*m_screen).x >= m_playSprite->getPosition().x
            && sf::Mouse::getPosition(*m_screen).x <= m_playSprite->getPosition().x + m_playSprite->getGlobalBounds().width
            && sf::Mouse::getPosition(*m_screen).y >= m_playSprite->getPosition().y
            && sf::Mouse::getPosition(*m_screen).y <= m_playSprite->getPosition().y + m_playSprite->getGlobalBounds().height)
        {
            m_playSprite->setTexture(*m_activePlayTexture);
        }
        else{
            m_playSprite->setTexture(*m_playTexture);
        }

        if(sf::Mouse::getPosition(*m_screen).x >= m_optionSprite->getPosition().x
            && sf::Mouse::getPosition(*m_screen).x <= m_optionSprite->getPosition().x + m_optionSprite->getGlobalBounds().width
            && sf::Mouse::getPosition(*m_screen).y >= m_optionSprite->getPosition().y
            && sf::Mouse::getPosition(*m_screen).y <= m_optionSprite->getPosition().y + m_optionSprite->getGlobalBounds().height)
        {
            m_optionSprite->setTexture(*m_activeOptionTexture);
        }
        else{
            m_optionSprite->setTexture(*m_optionTexture);
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(sf::Mouse::getPosition(*m_screen).x >= m_playSprite->getPosition().x
            && sf::Mouse::getPosition(*m_screen).x <= m_playSprite->getPosition().x + m_playSprite->getGlobalBounds().width
            && sf::Mouse::getPosition(*m_screen).y >= m_playSprite->getPosition().y
            && sf::Mouse::getPosition(*m_screen).y <= m_playSprite->getPosition().y + m_playSprite->getGlobalBounds().height)
            {
                m_screen->close();
                GameManager gameManager(640, 480, "Stickman Project");
                gameManager.action();
            }
        }

        m_screen->clear();
        m_screen->draw(*m_bgSprite);
        m_screen->draw(*m_playSprite);
        m_screen->draw(*m_optionSprite);
        m_screen->display();
    }
}
