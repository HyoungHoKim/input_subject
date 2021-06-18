#ifndef GAMEMODE_HPP
# define GAMEMODE_HPP

# include <cstdlib>
# include <ncurses.h>
# include <unistd.h>
# include <ctime>
# include "Player.hpp"

class GameMode
{
private:
	bool game_over;
	const int WIDTH;
	const int HEIGHT;
	clock_t start;
	clock_t end;
	Player player;

public:
	GameMode(int w, int h) : WIDTH(w), HEIGHT(h)
	{
		game_over = false;
		player.set_x(WIDTH / 2);
		player.set_y(HEIGHT / 2);
		start = 0;
		end = 0;
	}

	const bool get_game_over(void) const;
	void render(void);
	void poll_input(void);
	void update(void);
};

#endif