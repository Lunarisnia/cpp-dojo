#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

#include "game.h"

// Should render road
void Game::render(int max)
{
    int i = 0;
    system("cls");
    do
    {
        std::cout << " * ";
        i++;
    } while (i < max);
}

void Game::play()
{
    int i = 0;
    while (true)
    {
        render(i);
        // Wait for input
        int pressedKey = getch();
        i++; // Testing
        // Calculate score
    }
}