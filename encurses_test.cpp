/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encurses_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:52:30 by vmazurok          #+#    #+#             */
/*   Updated: 2018/06/30 18:50:06 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <cstdlib>
#include <iostream>
#include <iostream>
#include <locale>

//
//class Windows{
//private:
//	WINDOW *_win;
//public:
//	Windows() {
//		_win = newwin(20, 20, 0, 0);
//	}
//	virtual ~Windows() {}
//	void shift(int x, int y) {wmove(_win, y, x);}
//};

std::string s;

void edges(WINDOW * win)
{
	int max_i;
	int max_j;
	setlocale(LC_ALL, "");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			if (j == 0 || j == 19) {
				mvwaddstr(win, i, j, "ᛄ");
			}
			else if (i == 0 || i == 9)
				mvwaddch(win, i, j, '-');
			wrefresh(win);
		}
	}
}

void draw_windows(int width, int height, WINDOW **win)
{
	for (int i = 0; i < height * width; i++) {
		edges(win[i]);
		wrefresh(win[i]);
	}
}

void create_greed(WINDOW **win, int width, int height)
{
	int i = 0;
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			win[i++] = newwin(10, 20, 10 * h + 1, 20 * w + 1);
		}
	}
}

int main()
{
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	setlocale(LC_ALL, "");
	WINDOW **win;
	win = new WINDOW * [6];
	create_greed(win, 3, 2);
	while (getch() != 27) {
		for (int i = 0; i < 6; i++) {
			draw_windows(3, 2, win);
		}
	}
	for (int k = 0; k < 6; k++) {
		delwin(win[k]);
	}
	delete [] win;
	endwin();
	return 0;
}