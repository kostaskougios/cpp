#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <range/v3/all.hpp>

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
        ranges::for_each(state, [&](Object &o) { o.render(window); });
    };
};

} // namespace game
