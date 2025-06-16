//
// Created by BasLocal on 09/06/2025.
//

#include <iostream>

#include "protx/protx/ProtX.h"

int main() {
    try {
        protx::ProtX game;
        game.run();
    } catch (const std::exception &e) {
        // std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
