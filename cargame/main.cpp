#include <iostream>
#include <string>
#include <curses.h>


int main()
{
    int cursorLocationIndex = 1;
    std::string choices[2] = {"New Game", "Exit"};

    while (true)
    {
        std::cout << "Welcome to CarGame" << std::endl;
        for (int i = 0; i < choices->length(); i++)
        {
            if (cursorLocationIndex == i)
            {
                std::cout << "> " << choices[i] << std::endl;
            }
            else
            {
                std::cout << choices[i] << std::endl;
            }
        }
        int ch = getch();
        // TODO: Implement this
    }

    // system("clear");

    return 0;
}