#include "game.hpp"

namespace game
{
std::vector<Object *> &Game::getState()
{
    return m_state;
}
} // namespace game