#pragma once

#include <SFML/Window/Joystick.hpp>

namespace game {
    class Controller {
    private:
        int n;
    public:
        Controller(int no): n(no) {};

        float x();
        float y();

    };
}
