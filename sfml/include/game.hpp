#pragma once

#include <vector>
#include "object.hpp"

namespace game
{
class Game
{
private:
    std::vector<Object *> m_state;

public:
    Game(std::vector<Object *> state) : m_state(state){};

    std::vector<Object *> &getState();
};

} // namespace game