#pragma once
#include <SFML/Graphics.hpp>

namespace game
{
class Game;

struct RenderContext
{
    sf::RenderWindow *window;
    Game &game;

    RenderContext(sf::RenderWindow *w, Game &g) : window(w), game(g){};
};

} // namespace game
