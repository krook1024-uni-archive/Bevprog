#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

class Labda {
	public:
	Labda();
	void draw();
	int xj = 0, xk = 0, yj = 0, yk = 0, mx = 0, my = 0;
};


int main()
{
	Labda labda;
	for(;;) labda.draw();
	return 0;
}

Labda::Labda() {
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	int h, w;
	getmaxyx(stdscr, h, w);
	mx = w*2;
	my = h*2;
}

void Labda::draw() {
	xj = (xj-1) % mx;
	xk = (xk+1) % mx;

	yj = (yj-1) % my;
	yk = (yk+1) % my;

	clear();

        mvprintw (abs ((yj + (my - yk)) / 2), abs ((xj + (mx - xk)) / 2), "o");

	refresh();
	usleep(30000);
}
