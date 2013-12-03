#include "../../include/Singleton/Menu.h"

Menu* Menu::m_menu = nullptr;

Menu::Menu ( void ) : m_saxguy(false)
{
    m_screen = new sf::RenderWindow ( sf::VideoMode ( 640, 480 ), "Menu" );

    m_bgTexture = new sf::Texture;
    m_playTexture = new sf::Texture;
    m_optionTexture = new sf::Texture;
    m_activePlayTexture = new sf::Texture;
    m_activeOptionTexture = new sf::Texture;
    m_saxTexture = new sf::Texture;
    m_saxDanceTexture = new sf::Texture;

    if ( !m_bgTexture->loadFromFile ( "img/menu_background.png" )
            || !m_playTexture->loadFromFile ( "img/lancer_partie.png" )
            || !m_optionTexture->loadFromFile ( "img/options.png" )
            || !m_activePlayTexture->loadFromFile ( "img/lancer_partie_actif.png" )
            || !m_activeOptionTexture->loadFromFile ( "img/options_actif.png" )
            || !m_saxTexture->loadFromFile ( "img/menu_sax.jpg" )
            || !m_saxDanceTexture->loadFromFile ( "img/menu_sax1.jpg" ) )
    {
        exit ( EXIT_FAILURE );
    }

    m_bgSprite = new sf::Sprite ( *m_bgTexture );

    m_playSprite = new sf::Sprite ( *m_playTexture );
    m_playSprite->move ( 30, 180 );

    m_optionSprite = new sf::Sprite ( *m_optionTexture );
    m_optionSprite->move ( 37, m_playSprite->getPosition().y + m_playSprite->getLocalBounds().height + 30 );

    m_music = new sf::Music;
    if(!m_music->openFromFile("music/menu.ogg")) {
        exit(EXIT_FAILURE);
    }
    m_music->setPlayingOffset(sf::seconds(5.5));
    m_music->setVolume(50);
    m_music->play();

    m_soundBuffer = new sf::SoundBuffer;
    m_soundBuffer->loadFromFile("sound/button.ogg");

    m_sound = new sf::Sound;
    m_sound->setBuffer(*m_soundBuffer);
    m_sound->setVolume(15);

    m_played = false;
    m_onButton = false;
}

Menu::~Menu ( void )
{
}

void Menu::action() {
    if(!m_screen->isOpen())
        m_screen->create(sf::VideoMode ( 640, 480 ), "Menu");
    m_music->setPlayingOffset(sf::seconds(5.5));
    m_music->play();

    m_sound->setBuffer(*m_soundBuffer);
    m_sound->setVolume(15);

    double anim(0.0);
    m_saxguy = false;
    m_bgSprite->setTexture(*m_bgTexture);

    sf::Event event;
    while (m_screen->isOpen()) {
        while(m_screen->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                m_music->stop();
                m_screen->close();
            }
        }

        if(sf::Mouse::getPosition(*m_screen).x >= m_playSprite->getPosition().x
                && sf::Mouse::getPosition(*m_screen).x <= m_playSprite->getPosition().x + m_playSprite->getGlobalBounds().width
                && sf::Mouse::getPosition(*m_screen).y >= m_playSprite->getPosition().y
                && sf::Mouse::getPosition(*m_screen).y <= m_playSprite->getPosition().y + m_playSprite->getGlobalBounds().height)
        {
            if(m_sound->getStatus() == sf::SoundSource::Stopped && !m_played) {
                m_sound->play();
                m_played = true;
            }
            m_playSprite->setTexture(*m_activePlayTexture);
        }
        else {
            m_played = false;
            m_playSprite->setTexture(*m_playTexture);
        }

        if(sf::Mouse::getPosition(*m_screen).x >= m_optionSprite->getPosition().x
                && sf::Mouse::getPosition(*m_screen).x <= m_optionSprite->getPosition().x + m_optionSprite->getGlobalBounds().width
                && sf::Mouse::getPosition(*m_screen).y >= m_optionSprite->getPosition().y
                && sf::Mouse::getPosition(*m_screen).y <= m_optionSprite->getPosition().y + m_optionSprite->getGlobalBounds().height)
        {
            if(m_sound->getStatus() == sf::SoundSource::Stopped && m_onButton) {
                m_sound->play();
                m_onButton = false;
            }
            m_optionSprite->setTexture(*m_activeOptionTexture);
        }
        else {
            m_optionSprite->setTexture(*m_optionTexture);
            m_onButton = true;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if(sf::Mouse::getPosition(*m_screen).x >= m_playSprite->getPosition().x
                    && sf::Mouse::getPosition(*m_screen).x <= m_playSprite->getPosition().x + m_playSprite->getGlobalBounds().width
                    && sf::Mouse::getPosition(*m_screen).y >= m_playSprite->getPosition().y
                    && sf::Mouse::getPosition(*m_screen).y <= m_playSprite->getPosition().y + m_playSprite->getGlobalBounds().height)
            {
                m_music->stop();
                m_screen->close();
                GameManager* gameManager = GameManager::getInstance();
                gameManager->action();
            }
        }

        // easter eggs EPIC SAX GUY
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                    if(!m_music->openFromFile("music/saxguy.ogg")) {
                        exit(EXIT_FAILURE);
                    }
                    m_music->stop();
                    m_music->play();
                    m_saxguy = true;
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            m_music->stop();
        }

        // anim menu
        if(m_saxguy) {

            anim += 0.06;

            if(anim > 6.0)
                anim = 0.0;

            if((int)anim % 2 == 0) {
                m_bgSprite->setTexture(*m_saxTexture);
            }
            else if ((int)anim % 2 == 1) {
                m_bgSprite->setTexture(*m_saxDanceTexture);
            }

        }

        m_screen->clear();
        m_screen->draw(*m_bgSprite);
        m_screen->draw(*m_playSprite);
        m_screen->draw(*m_optionSprite);
        m_screen->display();
    }
}
