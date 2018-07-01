/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:35:24 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 20:18:43 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OS.hpp"

OS::OS() {
}

OS::OS(SDL_Renderer	*rend){
	newrend = rend;
	_mode = 0;
	_win = newwin(5, 20, 0, 38);
	_width = 20;
	_height = 5;
	textColor.r = 0; textColor.g =255; textColor.b = 255; textColor.a = 255;
	font = TTF_OpenFont("test.ttf", 20);
	textRect.x = 220;textRect.y = 460;
	versRect.x = 400;versRect.y = 460;
	textSurface = nullptr;
};
OS::~OS(){};

void OS::getInfo(){
	int i = 0;
	char line[256];
	FILE *sw_vers = popen("sw_vers", "r");
	fgets(line, sizeof(line), sw_vers);
	while (line[i] && line[i] != '\t')
		i++;
	this->_name = line + i + 1;
	i = 0;
	fgets(line, sizeof(line), sw_vers);
	while (line[i] && line[i] != '\t')
		i++;
	this->_version = line + i + 1;
	pclose(sw_vers);
}

std::string OS::getName(){
	return this->_name;
}

std::string OS::getVersion(){
	return this->_version;
}

void OS::display(){
	setlocale(LC_ALL, "");
	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
	SDL_FreeSurface(textSurface);
	SDL_QueryTexture(verstext, NULL, NULL, &versRect.w, &versRect.h);
	SDL_FreeSurface(versSurf);
	getInfo();
	textSurface = TTF_RenderText_Solid(font, _name.c_str(), textColor);
	versSurf = TTF_RenderText_Solid(font, _version.c_str(), textColor);
	text = SDL_CreateTextureFromSurface(newrend, textSurface);
	verstext = SDL_CreateTextureFromSurface(newrend, versSurf);
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
	wattron(_win, COLOR_PAIR(2));
	mvwaddstr(_win, 1, 2, "    OS module");
	wattroff(_win, COLOR_PAIR(2));
	mvwaddstr(_win, 2, 2, _name.c_str());
	mvwprintw(_win, 3, 2, "Version: %s", _version.c_str());
	SDL_RenderCopy(newrend, text, NULL, &textRect);
	SDL_RenderCopy(newrend, verstext, NULL, &versRect);
	getInfo();
}
