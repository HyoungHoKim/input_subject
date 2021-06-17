#include "GameMode.hpp"

void Initalize()
{
	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0);
}

int main(void)
{
	GameMode gamemode(20, 40);

	while (!gamemode.get_game_over())
	{
		gamemode.render();
		gamemode.poll_input();
		gamemode.update();
	}
	getch();
    sleep(1); 
    endwin();

    return 0;
}