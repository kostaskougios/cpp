#pragma once

#include "object.hpp"

namespace game
{

class Player : public Object
{
private:
    int m_x;
    int m_y;

public:
    Player(int x, int y) : m_x(x), m_y(y){};

    void render(sf::RenderWindow *);
    Object *nextMove(Game &);
};

} // namespace game