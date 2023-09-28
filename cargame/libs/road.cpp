#include <iostream>

#include "road.h"

void Road::set_metadata(int roadWidth, int obstacleCount)
{
    Road::roadWidth = roadWidth;
    Road::obstacleCount = obstacleCount;
    if (Road::obstacleCount > 0)
    {
        int lastPosition = 0;
        for (int i = 0; i < Road::obstacleCount; i++)
        {
            int newPosition = std::rand() % (roadWidth - 1) + 1;
            do
            {
                if (newPosition == lastPosition)
                {
                    newPosition = std::rand() % (roadWidth - 1) + 1;
                }
            } while (newPosition == lastPosition);

            Road::obstaclePosition.push_back(newPosition);
        }
    }
}

bool isObstaclePosition(std::vector<int> obstaclePosition, int currentPosition) {
    bool matched = false;
    for(auto i = obstaclePosition.begin(); i != obstaclePosition.end(); i++) {
        if (currentPosition == *i) {
            matched = true;
        } 
    }
    return matched;
}

void Road::draw_road()
{
    for (int i = 0; i <= roadWidth; i++)
    {
        if (i == 0 || (i == roadWidth))
        {
            std::cout << '*';
        }
        else
        {
            // if has obstacle should render obstacle too randomly along this
            if (isObstaclePosition(obstaclePosition, i)) {
                std::cout << 'O';
            } else {
                std::cout << ' ';
            }
            // if this is the most bottom lane should also render player
        }
    }
    std::cout << std::endl;
}

void Road::draw_player(int x, int y)
{
    // Draw the player in the corresponding position
    // Check if the player hit anything
    // if the player hit something then game over
    std::cout << "Unimplemented" << std::endl;
}
