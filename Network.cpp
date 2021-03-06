/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:42:23 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 20:56:41 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Network.hpp"

Network::Network(SDL_Renderer	*rend) {
	newrend = rend;
	_mode = NCURSES;
	_width = 30;
	_height = 15;
	font = TTF_OpenFont("test.ttf", 13);
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
	SDL_QueryTexture(usedtext, NULL, NULL, &dayRect.w, &dayRect.h);
	SDL_FreeSurface(usedSurface);

	dayRect.x = 450;dayRect.y = 60;
	textColor.r = 0; textColor.g =255; textColor.b = 255; textColor.a = 255;
	std::string Pockets = "Pockets In: " + _pocketsIn;
	usedSurface = TTF_RenderText_Solid(font, Pockets.c_str(), textColor);
	usedtext = SDL_CreateTextureFromSurface(newrend, usedSurface);
	SDL_RenderCopy(newrend, usedtext, NULL, &dayRect);
	Pockets = "Pockets Out: " + _pocketsOut;
	dayRect.x = 450; dayRect.y = 80;
	usedSurface = TTF_RenderText_Solid(font, Pockets.c_str(), textColor);
	usedtext = SDL_CreateTextureFromSurface(newrend, usedSurface);
	SDL_RenderCopy(newrend, usedtext, NULL, &dayRect);
	static int f;
	std::stringstream ss;
	setlocale(LC_ALL, "");
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			if ((i == 0 && j == 0) || (i == _height - 1 && j == _width - 1))
			mvwaddstr(_win, i, j, "+");
			else if ((i == _height - 1 && j == 0) || (i == 0 && j == _width - 1))
				mvwaddstr(_win, i, j, "+");
			else if (i == 0 || i == _height - 1)
				mvwaddstr(_win, i, j, "-");
			else if (j == 0 || j == _width - 1)
				mvwaddstr(_win, i, j, "|");
		}
	}
	wrefresh(_win);
	getInfo();
	wattron(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 1, 2, "✉️     Network module   ✉️");
	wattroff(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 2, 2, "Pockets In: ");
	mvwaddstr(_win, 2, 15, _pocketsIn.c_str());
	mvwaddstr(_win, 3, 2, "Pockets Out: ");
	mvwaddstr(_win, 3, 15, _pocketsOut.c_str());
	int i;
	if (f < 2 || (f > 4 && f < 6)) {
		i = 6;
		mvwaddstr(_win, i++, 7, "   |\\_._/|  ");
		mvwaddstr(_win, i++, 7, "   | o o |   ");
		mvwaddstr(_win, i++, 7, "   (  T  )   ");
		mvwaddstr(_win, i++, 7, "  .^`-^-'^.  ");
		mvwaddstr(_win, i++, 7, "  `.  ;  .'  ");
		mvwaddstr(_win, i++, 7, "  | | | | |  ");
		mvwaddstr(_win, i++, 7, " ((_((|))_)) ");
	}
	else if (f < 4) {
		i = 6;
		mvwaddstr(_win, i++, 7, "   |,\\__/|   ");
		mvwaddstr(_win, i++, 7, "   |  o o|    ");
		mvwaddstr(_win, i++, 7, "   (   T )    ");
		mvwaddstr(_win, i++, 7, "  .^`--^'^.   ");
		mvwaddstr(_win, i++, 7, "  `.  ;  .'   ");
		mvwaddstr(_win, i++, 7, "  | | | | |   ");
		mvwaddstr(_win, i++, 7, " ((_((|))_))  ");
	}
	else if (f < 8) {
		i = 6;
		mvwaddstr(_win, i++, 7, "   |\\__/,|  ");
		mvwaddstr(_win, i++, 7, "   |o o  |   ");
		mvwaddstr(_win, i++, 7, "   ( T   )   ");
		mvwaddstr(_win, i++, 7, "  .^`--^'^.   ");
		mvwaddstr(_win, i++, 7, "  `.  ;  .'   ");
		mvwaddstr(_win, i++, 7, "  | | | | |   ");
		mvwaddstr(_win, i++, 7, " ((_((|))_))  ");
	}
	else {
		f = -1;
		i = 6;
		mvwaddstr(_win, i++, 7, "   |\\_._/|  ");
		mvwaddstr(_win, i++, 7, "   | 0 0 |   ");
		mvwaddstr(_win, i++, 7, "   (  T  )   ");
		mvwaddstr(_win, i++, 7, "  .^`-^-'^.  ");
		mvwaddstr(_win, i++, 7, "  `.  ;  .'  ");
		mvwaddstr(_win, i++, 7, "  | | | | |  ");
		mvwaddstr(_win, i++, 7, " ((_((|))_)) ");
	}
	f++;
}

Network::Network(Network const &cpy) {
	*this = cpy;
}

Network &Network::operator=(Network const &cpy) {
	this->_win = cpy._win;
	this->_pocketsOut = cpy._pocketsOut;
	this->_pocketsIn = cpy._pocketsIn;
	this->_mode = cpy._mode;
	this->_width = cpy._width;
	this->_height = cpy._height;
	//----------------------------------------
	return *this;
}
