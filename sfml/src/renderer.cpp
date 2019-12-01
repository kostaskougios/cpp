#include "renderer.hpp"
#include <range/v3/algorithm/for_each.hpp>

namespace game
{
void Renderer::render(sf::RenderWindow *window, Game *game)
{
    auto &state = game->getState();

    window->clear();
    ranges::for_each(state, [&](Object *o) { o->render(window); });
    window->display();
}

} // namespace game
