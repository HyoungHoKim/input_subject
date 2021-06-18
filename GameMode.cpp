#include "GameMode.hpp"

const bool GameMode::get_game_over(void) const
{
	return (this->game_over);
}

void GameMode::render(void)
{
    clear();

    for (int i = 0; i < this->HEIGHT + 2; i++)
    {
        for (int j = 0; j < this->WIDTH + 2; j++)
        {
            if (i == 0 || i == this->HEIGHT + 1)
            {
                mvprintw(i, j, "0");
            }
            else if (j == 0 || j == this->WIDTH + 1)
            {
                mvprintw(i, j, "0");
            } 
            else if (i == this->player.get_y() && j == this->player.get_x())
            {
                mvprintw(i, j, "0");
            }
        }
    }    
}

void GameMode::poll_input()
{
    keypad(stdscr, true);
    halfdelay(1); 

    int c = getch();
    
    if  (c == KEY_LEFT || c == KEY_RIGHT || c == KEY_UP || c == KEY_DOWN)
    {   
        if (c == KEY_LEFT)
            this->player.set_dir(LEFT);
        if (c == KEY_RIGHT)
            this->player.set_dir(RIGHT);
        if (c == KEY_DOWN) 
            this->player.set_dir(UP);
        if (c == KEY_UP)
        {
            if (start - end < 1.5)
                this->player.dash = true;
            else
                this->player.dash = false;
            this->start = clock();
            this->player.set_dir(DOWN);
            this->end = clock();
        }
    }
    if (c == 'q')
        this->game_over = true;
}

void GameMode::update()
{
    this->player.move();

    if (this->player.get_x() < 1)
        this->player.set_x(this->WIDTH);
    if (this->player.get_x() > this->WIDTH)
        this->player.set_x(0);
    if (this->player.get_y() < 1)
        this->player.set_y(this->HEIGHT);
    if (this->player.get_y() > this->HEIGHT)
        this->player.set_y(0);
}