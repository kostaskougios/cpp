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
    Renderer(sf::RenderWindow *window, Game game) : w(window)
    {
        auto &state = game.getState();
        };
};

} // namespace game
