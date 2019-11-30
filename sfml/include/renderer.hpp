#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"

namespace game
{

class Renderer
{
private:
    sf::RenderWindow *w;

public:
    void render(sf::RenderWindow *, Game &);
};

} // namespace game
