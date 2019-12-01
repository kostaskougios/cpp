#pragma once

#include <SFML/Graphics.hpp>
#include "game.hpp"

namespace game
{
class Game;

class Object
{
public:
    virtual ~Object(){};

    virtual void render(sf::RenderWindow *window) = 0;
    virtual Object *nextMove(Game &game) = 0;
};
} // namespace game