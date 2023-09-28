#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <vector>
#include <cmath>

#include "game.h"
#include "road.h"
#include "player.h"

int tick = 0;

const int ROAD_WIDTH = 10;
const int DISPLAY_LENGTH = 6;
Road renderedRoad[DISPLAY_LENGTH];
Player player = Player(ROAD_WIDTH);

// Should render roadBlank
void Game::render(bool *mainLoop)
{
    system("cls");
    if (tick > 0)
    {
        // This will remove the last element and left the first element empty to be replaced
        for (int y = DISPLAY_LENGTH - 1; y > 0; y--)
        {
            // Copy the previous element
            renderedRoad[y] = renderedRoad[y - 1];
        }
        renderedRoad[0] = Road();
        renderedRoad[0].set_metadata(ROAD_WIDTH, 2, &player);
    }
    else
    {
        for (int y = 0; y < 6; y++)
        {
            renderedRoad[y] = Road();
            renderedRoad[y].set_metadata(ROAD_WIDTH, 1, &player);
        }
    }
    for (int y = 0; y < DISPLAY_LENGTH; y++)
    {
        renderedRoad[y].draw_road(y, DISPLAY_LENGTH, tick);
    }

    // Player is dead, stop the main loop
    if (!player.is_player_alive())
    {
        system("cls");
        *mainLoop = false;
        for (int y = 0; y < DISPLAY_LENGTH; y++)
        {
            if (!player.is_player_alive() && (y == (std::floor(DISPLAY_LENGTH / 2))))
            {
                renderedRoad[y].draw_game_over();
            }
            else
            {
                renderedRoad[y].draw_road(y, DISPLAY_LENGTH, tick);
            }
        }
    }
}

void Game::play()
{
    bool mainLoop = true;
    player = Player(ROAD_WIDTH);
    while (mainLoop)
    {
        render(&mainLoop);
        // Wait for input
        int pressedKey = getch(); // TODO: This should not block the main thread later
        if (pressedKey == ESCAPE)
        {
            exit(0);
        }
        // std::this_thread::sleep_for(std::chrono::milliseconds(50));
        tick++;
        // Calculate score
    }
}