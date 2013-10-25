#include "Character.h"

sf::Sprite Character::skin()
{
    return *m_skinSprite;
}

sf::Sprite* Character::pSkin()
{
    return m_skinSprite;
}

void Character::setSprite(std::string const& path)
{
    m_skinTexture = new sf::Texture;
    if(!m_skinTexture->loadFromFile(path))
    {
        exit(EXIT_FAILURE);
    }
    m_skinSprite = new sf::Sprite(*m_skinTexture);
}

void Character::changeSkin(std::string const& path)
{
    m_skinTexture = new sf::Texture;
    if(!m_skinTexture->loadFromFile(path))
    {
        exit(EXIT_FAILURE);
    }
    sf::Vector2f oldPosition(m_skinSprite->getPosition());
    m_skinSprite->setTexture(*m_skinTexture);
    m_skinSprite->setPosition(oldPosition.x, oldPosition.y);
}
