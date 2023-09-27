#include <iostream>
#include <string>

#include "libs/cursor.h"
#include "libs/game.h"

void clearConsole()
{
    // TODO: Check if os is Windows/mac/linux and set the command accordingly
    system("cls");
}

Game game;

void onConfirm(int cursorIndex) {
    switch (cursorIndex)
    {
    case 0:
        // TODO: Start making the game
        // std::cout << "New Game Starts here!!" << std::endl;
        game.play();
        break;
    case 1:
        clearConsole();
        std::cout << "Thank you! Good bye..." << std::endl;
        exit(0);
        break;
    
    default:
        std::cout << "WHAT!???? HOW DO YOU FIND THIS?" << std::endl;
        exit(0); 
        break;
    }
}

int main()
{
    std::string choices[2] = {"New Game", "Exit"};
    int choicesCount = sizeof(choices) / sizeof(choices[0]);
    Cursor cursor(choicesCount);

    while (true)
    {
        clearConsole();
        std::cout << "Welcome to CarGame" << std::endl;
        int choicesCount = sizeof(choices) / sizeof(choices[0]);
        for (int i = 0; i < choicesCount; i++)
        {
            if (cursor.get_cursor_position_index() == i)
            {
                std::cout << "> " << choices[i] << std::endl;
            }
            else
            {
                std::cout << choices[i] << std::endl;
            }
        }
        cursor.wait_for_input(onConfirm);
    }

    return 0;
}