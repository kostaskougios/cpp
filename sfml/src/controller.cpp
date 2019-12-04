#include "controller.hpp"

namespace game {
    float Controller::x() {
        return sf::Joystick::getAxisPosition(n, sf::Joystick::X);
    }

    float Controller::y() {
        return sf::Joystick::getAxisPosition(n, sf::Joystick::Y);
    }
}