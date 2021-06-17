#ifndef GAMEMODE_HPP
# define GAMEMODE_HPP

# include <cstdlib>
# include <ncurses.h>
# include <unistd.h>
# include "snake.hpp"

class GameMode
{
private:
	bool game_over;
	const int WIDTH;
	const int HEIGHT;
	int fruit_x;
	int fruit_y;
	int score;
	Snake snake;
public:
	GameMode(int w, int h) : WIDTH(w), HEIGHT(h)
	{
		game_over = false;
		snake.set_x(WIDTH / 2);
		snake.set_y(HEIGHT / 2);
		fruit_x = (rand() % WIDTH) + 1;
		fruit_y = (rand() % HEIGHT) + 1;
		score = 0;
	}

	const bool get_game_over(void) const;
	void render(void);
	void poll_input(void);
	void update(void);
};

#endif