#include "game.hpp"
#include "object.hpp"
#include <range/v3/view/transform.hpp>
#include <range/v3/algorithm/for_each.hpp>

namespace game
{
Game::~Game()
{
    ranges::for_each(m_state, [](Object *o) { delete o; });
}

std::vector<Object *> &Game::getState()
{
    return m_state;
}

int Game::width() { return m_width; };
int Game::height() { return m_height; };

Game *Game::nextMove()
{
    std::vector<Object *> next = m_state | ranges::view::transform([this](Object *o) { return o->nextMove(*this); }) | ranges::to_vector;
    return new Game(next, m_width, m_height);
}

} // namespace game