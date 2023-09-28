#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <vector>
#include <stack>

#include "game.h"
#include "road.h"

int tick = 0;

int roadWidth = 10;
Road renderedRoad[6];

// Should render roadBlank
void Game::render(int max)
{
    system("cls");
    if (tick > 0)
    {
        // This will remove the last element and left the first element empty to be replaced
        for (int y = 5; y > 0; y--) {
            // Copy the previous element 
            renderedRoad[y] = renderedRoad[y - 1]; 
        }
        renderedRoad[0] = Road();
        renderedRoad[0].set_metadata(roadWidth, false);
    }
    else
    {
        for (int y = 0; y < 6; y++)
        {
            renderedRoad[y] = Road();
            renderedRoad[y].set_metadata(roadWidth, false);
        }
    }

    for (int y = 0; y < 6; y++)
    {
        renderedRoad[y].draw_road();
    }
}

void Game::play()
{
    int i = 6;
    while (true)
    {
        render(i);
        // Wait for input
        int pressedKey = getch();
        tick++;
        // Calculate score
    }
}