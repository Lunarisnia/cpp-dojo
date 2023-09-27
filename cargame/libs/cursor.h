#ifndef CURSOR_H
#define CURSOR_H
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESCAPE 27

class Cursor
{
    int cursorPosition = 0;
    int optionCount = 0;

public:
    Cursor(int opt_count);
    void wait_for_input(void (*on_confirm)());
    void move_up();
    void move_down();
    void confirm_action(void (*on_confirm)());
    int get_cursor_position_index();

protected:
    virtual void moveUp();
    virtual void moveDown();
    virtual void confirmAction(void (*on_confirm)());
};
#endif