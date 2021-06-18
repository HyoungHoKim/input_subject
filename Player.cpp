#include "Player.hpp"

Player::Player()
{
	this->dir = STOP;
	this->x = 0;
	this->y = 0;
	this->num_tail = 0;
	dash = false;
}

void Player::set_x(int _x)
{
	this->x = _x;
}

void Player::set_y(int _y)
{
	this->y = _y;
}

void Player::set_num_tail(int _num_tail)
{
	this->num_tail = _num_tail;
}

void Player::set_dir(Dir _dir)
{
	this->dir = _dir;
}

const int Player::get_x(void) const
{
	return (this->x);
}
const int Player::get_y(void) const
{
	return (this->y);
}

const int Player::get_num_tail(void) const
{
	return (this->num_tail);
}

const int *Player::get_tail_x(void) const
{
	return (this->tail_x);
}

const int *Player::get_tail_y(void) const
{
	return (this->tail_y);
}

void Player::move(void)
{
	int speed;
	if (this->dash)
		speed = 4;
	else
		speed = 1;

    if (this->dir == LEFT)
        this->x -= speed;
    if (this->dir == RIGHT)
        this->x += speed;
    if (this->dir == UP)
        this->y += speed;
    if (this->dir == DOWN)
        this->y -= speed;
    this->dir = STOP;
	this->dash = false;
}