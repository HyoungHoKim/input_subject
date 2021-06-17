#include "GameMode.hpp"

const bool GameMode::get_game_over(void) const
{
	return (this->game_over);
}

void GameMode::render(void)
{
    clear();

    for (int i = 0; i< this->HEIGHT + 2; i++)
    {
        for (int j = 0; j < this->WIDTH + 2; j++)
        {
            if (i==0 || i==21)
            {
                mvprintw(i, j, "0");
            }
            else if (j == 0 || j == 21)
            {
                mvprintw(i, j, "0");
            } 
            else if (i == this->snake.get_y() && j == this->snake.get_x())
            {
                mvprintw(i, j, "*");
            }
            else if (i == this->fruit_x && j == this->fruit_y)
            {
                mvprintw(i, j, "@");
            }
            else
            {   
                for (int k = 0; k < this->snake.get_num_tail(); k++)
                {
                    if ((this->snake.get_tail_x())[k] == j 
						&& (this->snake.get_tail_y())[k] == i)
                    {
                        mvprintw(i,j, "o");
                    }
                }

            }
            
        }
    }    
	
    mvprintw(7, 29, "Use direction keys to eat fruit");
    mvprintw(9, 43, "   ^ ");
    mvprintw(10, 43, "<  v  >");
    mvprintw(14, 29, "** If you collide with wall or tail, Snake will die");

    mvprintw(16, 29, "$$ Score = %d", this->score);
//  mvprintw(17, 29, "$$ Remain Time = %d", current_time);
    refresh();
}

void GameMode::poll_input()
{
    keypad(stdscr, true); // Check whether there is input, function from ncurses
    halfdelay(1); 

    int c = getch(); // Save the typed key by gamer

    switch(c)
    {
        case KEY_LEFT:
            this->snake.set_dir(LEFT);
            break;
        case KEY_RIGHT:
            this->snake.set_dir(RIGHT);
            break;
        case KEY_DOWN: // definition is opposite between up and down
            this->snake.set_dir(UP);
            break;
        case KEY_UP:
            this->snake.set_dir(DOWN);
            break;
        case KEY_EXIT:
            this->game_over = true;
            break;

    }    
}

void GameMode::update()
{
    this->snake.move();

// if snake goes outside from the map, game will be over    
    if (this->snake.get_x() > this->WIDTH || this->snake.get_x() < 1
		|| this->snake.get_y() < 1 || this->snake.get_y() > this->HEIGHT)
    {
        this->game_over=true;
    }

// if snake eats the fruit on the map, score will increase    
    if (this->snake.get_x() == this->fruit_x 
		&& this->snake.get_y() == this->fruit_y)
    {
        this->score++;
        this->fruit_x = (rand() % WIDTH)+1;
        this->fruit_y = (rand() % HEIGHT)+1;
        this->snake.set_num_tail(this->snake.get_num_tail() + 1);
    }

    for (int i = 0; i < this->snake.get_num_tail(); i++)
    {
        if((this->snake.get_tail_x())[i] == this->snake.get_x() 
			&& (this->snake.get_tail_y())[i] == this->snake.get_y())
        {
            this->game_over = true;
        }
        
    }

}
