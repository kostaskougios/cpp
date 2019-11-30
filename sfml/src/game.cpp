#include "game.hpp"

namespace game
{
std::vector<Object *> &Game::getState()
{
    return m_state;
}

int Game::width() { return m_width; };
int Game::height() { return m_height; };

} // namespace game