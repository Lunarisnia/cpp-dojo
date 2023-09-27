#include <iostream>
// TODO: find a way to make this dynamic
#include <conio.h> // Windows
// #include <curses.h> // Mac

#include "cursor.h"

Cursor::Cursor(int opt_count)
{
    optionCount = opt_count;
};

void Cursor::move_down()
{
    moveDown();
}

void Cursor::moveDown()
{
    if (cursorPosition < (optionCount - 1))
    {
        cursorPosition++;
    }
}

void Cursor::move_up()
{
    moveUp();
}

void Cursor::moveUp()
{
    if (cursorPosition > 0)
    {
        cursorPosition--;
    }
}

int Cursor::get_cursor_position_index() {
    return cursorPosition;
}

void Cursor::wait_for_input(void (*on_confirm)(int cursorIndex))
{
    int pressedKey = getch();
    switch (pressedKey)
    {
    case KEY_UP:
        move_up();
        break;
    case KEY_DOWN:
        move_down();
        break;
    case ENTER:
        confirm_action(on_confirm);
        break;
    case ESCAPE:
        exit(0);
    default:
        break;
    }
}

void Cursor::confirm_action(void (*on_confirm)(int cursorIndex)) {
    confirmAction(on_confirm);
}

void Cursor::confirmAction(void (*on_confirm)(int cursorIndex)) {
    on_confirm(cursorPosition);
}