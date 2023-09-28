#include <iostream>

#include "road.h"

// Road::Road(bool hasObstacle, int roadWidth) {
//     Road::hasObstacle = hasObstacle;
//     Road::roadWidth = roadWidth;
// }

void Road::set_metadata(int roadWidth, bool hasObstacle) {
    Road::roadWidth = roadWidth;
    Road::hasObstacle = hasObstacle;
}

void Road::draw_road() {
    for (int i = 0; i <= roadWidth; i++)
    {
        if (i == 0 || (i == roadWidth)) {
            std::cout << '*';
        } else {
            // if has obstacle should render obstacle too randomly along this
            // if this is the most bottom lane should also render player
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}

void Road::draw_player(int x, int y) {
    // Draw the player in the corresponding position
    // Check if the player hit anything
    // if the player hit something then game over
    std::cout << "Unimplemented" << std::endl;
}

