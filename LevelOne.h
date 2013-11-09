#ifndef LEVELONE_H_INCLUDED
#define LEVELONE_H_INCLUDED
#include <vector>
#include "ILevel.h"
#include "Player.h"
#include <iostream>

class LevelOne : public ILevel
{
    public:
        LevelOne ( void );
        ~LevelOne ( void );
        int getHeight ( void );
        int getWidth ( void );
        void loadLevel ( Player* player );
        void drawLevel ( sf::RenderWindow* screen );
        std::vector<sf::Sprite*>* getBlocks ( void );
    private:
        std::vector<std::string>* m_tileMap;
        std::vector<sf::Sprite*>* m_blocks;
        sf::Texture* m_texture;
};

#endif // LEVELONE_H_INCLUDED
