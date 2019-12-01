#pragma once

#include <vector>
#include "object.hpp"

namespace game
{

class Object;

class Game
{
private:
    int m_width;
    int m_height;
    std::vector<Object *> m_state;

public:
    Game(std::vector<Object *> state, int width, int height) : m_width(width), m_height(height), m_state(state){};
    ~Game();

    std::vector<Object *> &getState();

    Game *nextMove();

    int width();
    int height();
};

} // namespace game