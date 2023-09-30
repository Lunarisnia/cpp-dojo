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

int generateObstacleCount()
{
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

    // Player is out of bound so we kill them
    if ((player.get_position() > ROAD_WIDTH) || (player.get_position() < 0)) {
        player.kill();
        player.set_position((player.get_position() < 0) ? 0 : ROAD_WIDTH);
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
    if (!player.is_player_alive()) {
        std::cout << "Press Any Key Twice" << std::endl;
    }
}

void checkUserInput(bool *mainLoop)
{
    while (*mainLoop)
    {
        int pressedKey = getch();
        switch (pressedKey)
        {
        case KEY_LEFT:
            player.move_left();
            break;
        case KEY_RIGHT:
            player.move_right();
            break;
        default:
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Game::play()
{
    bool mainLoop = true;
    bool isInputValid = true;
    tick = 0;
    player.revive();

    // std::thread userInput(checkUserInput);
    // userInput.detach();
    while (mainLoop)
    {
        render(&mainLoop);
        if (tick == 0)
        {
            std::thread userInput(checkUserInput, &mainLoop);
            userInput.detach();
        }
        tick++;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    getch();
}