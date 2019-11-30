#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "renderer.hpp"

int main()
{
    int Width = 1024;
    int Height = 768;
    int Radius = 20;
    sf::RenderWindow window(sf::VideoMode(Width, Height), "Silly game production");

    window.setFramerateLimit(240);
    sf::CircleShape shape(Radius);
    shape.setFillColor(sf::Color::Magenta);
    shape.setScale(1.f, 1.f);

    int dx = 1;
    int dy = 1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        auto position = shape.getPosition();
        if (position.x < 0 || position.x > Width - Radius)
            dx = -dx;
        if (position.y < 0 || position.y > Height - Radius)
            dy = -dy;
        shape.setPosition(position.x + dx, position.y + dy);
        window.display();
    }

    return 0;
}