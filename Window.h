#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class Window
{
protected:
    virtual void loadSprite(sf::Texture* texture, sf::Sprite* sprite, std::string const& path)
    {
        if(!texture->loadFromFile(path))
        {
            exit(EXIT_FAILURE);
        }
        sprite->setTexture(*texture);
    }
};

#endif // WINDOW_H_INCLUDED
