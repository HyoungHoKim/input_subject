#include "snake.hpp"

Snake::Snake()
{
	this->dir = STOP;
	this->x = 0;
	this->y = 0;
	this->num_tail = 0;
}

void Snake::set_x(int _x)
{
	this->x = _x;
}

void Snake::set_y(int _y)
{
	this->y = _y;
}

void Snake::set_num_tail(int _num_tail)
{
	this->num_tail = _num_tail;
}

void Snake::set_dir(Dir _dir)
{
	this->dir = _dir;
}

const int Snake::get_x(void) const
{
	return (this->x);
}
const int Snake::get_y(void) const
{
	return (this->y);
}

const int Snake::get_num_tail(void) const
{
	return (this->num_tail);
}

const int *Snake::get_tail_x(void) const
{
	return (this->tail_x);
}

const int *Snake::get_tail_y(void) const
{
	return (this->tail_y);
}

void Snake::move(void)
{
	int prevX = this->tail_x[0];
    int prevY = this->tail_y[0];
    int prev2X, prev2Y;
    this->tail_x[0] = this->x;
    this->tail_y[0] = this->y;
    // add new position and other one copy
    for (int i = 1; i < this->num_tail; i++)
    {
        prev2X = this->tail_x[i];
        prev2Y = this->tail_y[i];
        this->tail_x[i] = prevX;
        this->tail_y[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (this->dir)
    {
        case LEFT:
            this->x--;
            break;
        case RIGHT:
            this->x++;
            break;
        case UP:
            this->y++;
            break;
        case DOWN:
            this->y--;
            break;
        default: 
            break;
    }
}