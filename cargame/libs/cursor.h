#ifndef CURSOR_H
#define CURSOR_H

class Cursor
{
    int cursorPosition = 0;
    int optionCount = 0;

public:
    Cursor(int opt_count);
    void wait_for_input(void (*on_confirm)(int cursorIndex));
    void move_up();
    void move_down();
    void confirm_action(void (*on_confirm)(int cursorIndex));
    int get_cursor_position_index();

protected:
    virtual void moveUp();
    virtual void moveDown();
    virtual void confirmAction(void (*on_confirm)(int cursorIndex));
};
#endif