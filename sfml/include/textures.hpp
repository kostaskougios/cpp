#pragma once

#include <SFML/Graphics.hpp>

namespace game
{
class Textures
{
private:
    void loadFromFile(std::string, sf::Texture &);

public:
    sf::Texture player1;
    Textures();
};

} // namespace game
