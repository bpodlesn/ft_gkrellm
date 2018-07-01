/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:42:23 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 16:14:05 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Network.hpp"

Network::Network() {
	_mode = NCURSES;
	_width = 30;
	_height = 15;
	_win = newwin(_height, _width, 6, 2 * _width + 5);
}

Network::~Network() {
	delwin(_win);
}

void Network::getInfo() {
	size_t i;
	std::string line;
	system("top -n 0 -l 1 | grep -E '^Networks:' &> newinfo");
	std::ifstream in ("newinfo");
	getline(in, line, 'u');
	std::string s1(line);
	i = s1.find("kets: ") + 6;
	_pocketsIn = line.substr(i, s1.find("in") - i);
	_pocketsOut = s1.substr(s1.find("in") + 4, s1.find("out") - s1.find("in") - 4);
	in.close();
	system("rm newinfo");
}

void Network::display() {
	static int f;
	std::stringstream ss;
	setlocale(LC_ALL, "");
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
//			if (i == 0 && j == 0)
//				mvwaddstr(_win, i, j, "+");
//			if (i == 4 && j == 0)
//				mvwaddstr(_win, i, j, "+");
//			if (i == 4 && j == 19)
//				mvwaddstr(_win, i, j, "+");
//			if (i == 0 && j == 19)
//				mvwaddstr(_win, i, j, "+");
			if (i == 0 || i == _height - 1)
				mvwaddstr(_win, i, j, "-");
			else if (j == 0 || j == _width - 1)
				mvwaddstr(_win, i, j, "|");
		}
	}
	wrefresh(_win);
	getInfo();
	wattron(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 1, 2, "✉️     Network module    ✉️");
	wattroff(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 2, 2, "Pockets In: ");
	mvwaddstr(_win, 2, 15, _pocketsIn.c_str());
	mvwaddstr(_win, 3, 2, "Pockets Out: ");
	mvwaddstr(_win, 3, 15, _pocketsOut.c_str());
	int i;
	if (f < 2 || (f > 4 && f < 6)) {
		i = 4;
		mvwaddstr(_win, i++, 3, "                        ");
		mvwaddstr(_win, i++, 3, "                        ");
		mvwaddstr(_win, i++, 3, "  yo+:-------------+oy  ");
		mvwaddstr(_win, i++, 3, "  + `::.        -::  +  ");
		mvwaddstr(_win, i++, 3, "  +    .::`  .::`    +  ");
		mvwaddstr(_win, i++, 3, "  +    `::::::::`    +  ");
		mvwaddstr(_win, i++, 3, "  + `::.        -::` +  ");
		mvwaddstr(_win, i++, 3, "  yo+--------------+oy  ");
		mvwaddstr(_win, i++, 3, "                        ");
		mvwaddstr(_win, i++, 3, "                        ");
	}
	else if (f < 4) {
		i = 4;
		mvwaddstr(_win, i++, 1, "                              ");
		mvwaddstr(_win, i++, 1, "                `--o+:        ");
		mvwaddstr(_win, i++, 1, "           ``---- -- -:       ");
		mvwaddstr(_win, i++, 1, "       ``-:-.    --   .:      ");
		mvwaddstr(_win, i++, 1, "    -//-.       ::     ./     ");
		mvwaddstr(_win, i++, 1, "    o-.-----.-.:/-----..-o    ");
		mvwaddstr(_win, i++, 1, "    `/.     ::`.     .-::-    ");
		mvwaddstr(_win, i++, 1, "      /.   :-    .---``       ");
		mvwaddstr(_win, i++, 1, "       :- :- .---``           ");
		mvwaddstr(_win, i++, 1, "        :o+--`                ");
	}
	else if (f < 8) {
		i = 4;
		mvwaddstr(_win, i++, 1, "                              ");
		mvwaddstr(_win, i++, 1, "        +s::-`                ");
		mvwaddstr(_win, i++, 1, "      `+``+``--:-``           ");
		mvwaddstr(_win, i++, 1, "     `/`   /`    .---.``      ");
		mvwaddstr(_win, i++, 1, "    `/`     /.       .:://    ");
		mvwaddstr(_win, i++, 1, "    o-...----/-.-----...-+    ");
		mvwaddstr(_win, i++, 1, "    /::-`     .`::     `/`    ");
		mvwaddstr(_win, i++, 1, "      ``.--..    ./   `/`     ");
		mvwaddstr(_win, i++, 1, "           ``----``/ `+`      ");
		mvwaddstr(_win, i++, 1, "                `--:s+        ");
	}
	else {
		f = -1;
		i = 4;
		mvwaddstr(_win, i++, 3, "                        ");
		mvwaddstr(_win, i++, 3, "                        ");
		mvwaddstr(_win, i++, 3, "  yo+:-------------+oy  ");
		mvwaddstr(_win, i++, 3, "  + `::.        -::  +  ");
		mvwaddstr(_win, i++, 3, "  +    .::`  .::`    +  ");
		mvwaddstr(_win, i++, 3, "  +    `::::::::`    +  ");
		mvwaddstr(_win, i++, 3, "  + `::.        -::` +  ");
		mvwaddstr(_win, i++, 3, "  yo+--------------+oy  ");
		mvwaddstr(_win, i++, 3, "                        ");
		mvwaddstr(_win, i++, 3, "                        ");
	}
	f++;
}