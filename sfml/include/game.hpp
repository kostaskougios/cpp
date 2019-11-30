#pragma once

#include <vector>
#include "object.hpp"

namespace game
{
class Game
{
private:
    std::vector<Object> state;

public:
    Game(){};

    std::vector<Object> &getState();
};

} // namespace game