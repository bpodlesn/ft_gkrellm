/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 18:22:41 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 21:23:20 by bpodlesn         ###   ########.fr       */
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
	// SDL_QueryTexture(used, NULL, NULL, &dayRect.w, &dayRect.h);
	// SDL_FreeSurface(usedSurf);

	// dayRect.x = 450;dayRect.y = 200;
	// textColor.r = 0; textColor.g =255; textColor.b = 255; textColor.a = 255;
	// std::string Pockets = "VideoCard: " + _name;
	// usedSurf = TTF_RenderText_Solid(font, Pockets.c_str(), textColor);
	// used = SDL_CreateTextureFromSurface(newrend, usedSurf);
	// SDL_RenderCopy(newrend, used, NULL, &dayRect);
	// Pockets = "VRAM: " + _VRAM;
	// dayRect.x = 450; dayRect.y = 220;
	// usedSurf = TTF_RenderText_Solid(font, Pockets.c_str(), textColor);
	// used = SDL_CreateTextureFromSurface(newrend, usedSurf);
	// SDL_RenderCopy(newrend, used, NULL, &dayRect);
	// Pockets = "DRIVER: " + _driver;
	// dayRect.x = 450; dayRect.y = 240;
	// usedSurf = TTF_RenderText_Solid(font, Pockets.c_str(), textColor);
	// used = SDL_CreateTextureFromSurface(newrend, usedSurf);
	// SDL_RenderCopy(newrend, used, NULL, &dayRect);
}