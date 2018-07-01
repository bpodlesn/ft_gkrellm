/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 18:22:41 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 21:42:30 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GPU.hpp"

GPU::GPU(SDL_Renderer *rend) {
	newrend = rend;
	_mode = NCURSES;
	_width = 30;
	_height = 6;
	_win = newwin(_height, _width, 22, _width + 3);
	font = TTF_OpenFont("test.ttf", 13);
	dayRect.w = 0; dayRect.h = 0;
	getInfo();
}

GPU::~GPU() {
	delwin(_win);
}

void GPU::getInfo() {
	std::string line("");
	system("system_profiler SPDisplaysDataType &> newinfo");
	std::ifstream in ("newinfo");
	while (line.find("Chipset Model:") == line.npos)
		getline(in, line);
	_name = line.substr(line.find(": ") + 2);
	while (line.find("VRAM") == line.npos)
		getline(in, line);
	_VRAM = line.substr(line.find(": ") + 2);
	while (line.find("Driver Version:") == line.npos)
		getline(in, line);
	_driver = line.substr(line.find(": ") + 2);
	in.close();
	system("rm newinfo");
}

void GPU::display() {
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
			wrefresh(_win);
		}
	}
	wattron(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 1, 2, "       GPU Module");
	wattroff(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 2, 2, _name.c_str());
	mvwaddstr(_win, 3, 2, "Total VRAM: ");
	mvwaddstr(_win, 3, 15, _VRAM.c_str());
	mvwaddstr(_win, 4, 2, "Driver version: ");
	mvwaddstr(_win, 4, 19, _driver.c_str());
}

GPU::GPU(GPU const &cpy) {
	*this = cpy;
}

GPU& GPU::operator=(GPU const &cpy) {
	_win = cpy._win;
	_height = cpy._height;
	_width = cpy._width;
	_mode = cpy._mode;
	_name = cpy._name;
	_driver = cpy._driver;
	_VRAM = cpy._VRAM;
	return *this;
}