#pragma once

#include <SFML/Graphics.hpp>

namespace game
{
class Object
{
public:
    virtual void render(sf::RenderWindow *window) = 0;
};
} // namespace game