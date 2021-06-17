#ifndef SNAKE_HPP
# define SNAKE_HPP

enum Dir {
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Snake
{
private:
	int x;
	int y;
	Dir dir;
	int tail_x[50];
	int tail_y[50];
	int num_tail;

public:
	Snake();
	
	void set_x(int _x);
	void set_y(int _y);
	void set_num_tail(int _num_tail);
	void set_dir(Dir _dir);
	const int get_x(void) const;
	const int get_y(void) const;
	const int get_num_tail(void) const;
	const int *get_tail_x(void) const;
	const int *get_tail_y(void) const;
	
	void move(void);
};

#endif 