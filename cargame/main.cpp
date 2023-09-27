#include <iostream>
#include <string>

#include "libs/cursor.h"

void clearConsole()
{
    // TODO: Check if os is Windows/mac/linux and set the command accordingly
    system("cls");
}

void onConfirm() {
    // TODO: Implement this further and start the games
    std::cout << "CONFIRMED" << std::endl;
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