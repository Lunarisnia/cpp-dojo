#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <vector>
#include <cmath>

#include "game.h"
#include "road.h"
#include "player.h"
#include "constants/keyboard_codes.h"

int tick = 0;

const int ROAD_WIDTH = 10;
const int DISPLAY_LENGTH = 6;
Road renderedRoad[DISPLAY_LENGTH];
Player player = Player(ROAD_WIDTH);

int generateObstacleCount() {
    return std::rand() % 2;
}

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
        renderedRoad[0].set_metadata(ROAD_WIDTH, generateObstacleCount(), &player);
    }
    else
    {
        for (int y = 0; y < 6; y++)
        {
            renderedRoad[y] = Road();
            renderedRoad[y].set_metadata(ROAD_WIDTH, generateObstacleCount(), &player);
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
    std::cout << "Score: " << tick << std::endl;
}

void Game::play()
{
    bool mainLoop = true;
    bool isInputValid = true;
    tick = 0;
    player.revive();
    while (mainLoop)
    {
        if (isInputValid)
        {
            render(&mainLoop);
        }
        // Wait for input
        int pressedKey = getch(); // TODO: This should not block the main thread later
        switch (pressedKey)
        {
        case KEY_LEFT:
            player.move_left();
            isInputValid = true;
            break;
        case KEY_RIGHT:
            player.move_right();
            isInputValid = true;
            break;
        default:
            isInputValid = false;
            break;
        }
        // std::this_thread::sleep_for(std::chrono::milliseconds(50));
        if (isInputValid)
        {
            tick++;
        }
        // Calculate score
    }
}