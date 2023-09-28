#include <iostream>

#include "road.h"
#include "player.h"

void Road::set_metadata(int roadWidth, int obstacleCount, Player *player)
{
    Road::roadWidth = roadWidth;
    Road::obstacleCount = obstacleCount;
    Road::player = player;
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

bool isObstaclePosition(std::vector<int> obstaclePosition, int currentPosition)
{
    bool matched = false;
    for (auto i = obstaclePosition.begin(); i != obstaclePosition.end(); i++)
    {
        if (currentPosition == *i)
        {
            matched = true;
        }
    }
    return matched;
}

bool isPlayerPosition(int currentPosition, int playerPosition)
{
    return currentPosition == playerPosition;
}

void Road::draw_road(int yAxis, int displayLength)
{
    for (int i = 0; i <= roadWidth; i++)
    {
        if (i == 0 || (i == roadWidth))
        {
            if (yAxis == displayLength - 1)
            {
                if (isPlayerPosition(i, player->get_position()))
                {
                    std::cout << player->get_avatar();

                    // Set gameover because it hits the wall
                }
                else
                {
                    std::cout << '*';
                }
            }
            else
            {
                std::cout << '*';
            }
        }
        else
        {
            if (yAxis == displayLength - 1)
            {
                if (isPlayerPosition(i, player->get_position()))
                {
                    std::cout << player->get_avatar();

                    // Set gameover because it hits an obstacle
                    if (isObstaclePosition(obstaclePosition, i)) {
                    }
                }
                else
                {
                    // if has obstacle should render obstacle too randomly along this
                    if (isObstaclePosition(obstaclePosition, i))
                    {
                        std::cout << 'O';
                    }
                    else
                    {
                        std::cout << ' ';
                    }
                }
            }
            else
            {
                // if has obstacle should render obstacle too randomly along this
                if (isObstaclePosition(obstaclePosition, i))
                {
                    std::cout << 'O';
                }
                else
                {
                    std::cout << ' ';
                }
            }
        }
    }
    std::cout << std::endl;
}