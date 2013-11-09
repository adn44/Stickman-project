#ifndef ILEVEL_H_INCLUDED
#define ILEVEL_H_INCLUDED
#include "Player.h"

class ILevel
{
    public:
        virtual ~ILevel ( void ){};
        virtual void loadLevel ( Player* player ) = 0;
        virtual void drawLevel ( sf::RenderWindow* screen ) = 0;
        virtual std::vector<sf::Sprite*>* getBlocks ( void ) = 0;
};

#endif // ILEVEL_H_INCLUDED
