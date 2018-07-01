/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTime.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:36:11 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 18:13:51 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTime.hpp"

DateTime::DateTime(SDL_Renderer *rend){
	newrend = rend;
	_mode = 0;
	_win = newwin(5, 23, 0, 68);
	_width = 23;
	_height = 5;
	textColor.r = 0; textColor.g =255; textColor.b = 255; textColor.a = 255;
	font = TTF_OpenFont("test.ttf", 15);
	dayRect.x = 270;dayRect.y = 520;
	timeRect.x = 525;timeRect.y = 520;
	daySurface = nullptr;
	timeSurface = nullptr;
	getInfo();
};
DateTime::~DateTime(){};

void DateTime::getInfo(){
	time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%x",timeinfo);
  _day = buffer;
  strftime (buffer,80,"%X",timeinfo);
  _time = buffer;
}

std::string DateTime::getDay(){
	return this->_day;
}

std::string DateTime::getTime(){
	return this->_time;
}


void DateTime::display(){
	setlocale(LC_ALL, "");
	box(_win, '|', '-');
	wrefresh(_win);
	SDL_QueryTexture(daytext, NULL, NULL, &dayRect.w, &dayRect.h);
	SDL_FreeSurface(daySurface);
	SDL_QueryTexture(timetext, NULL, NULL, &timeRect.w, &timeRect.h);
	SDL_FreeSurface(timeSurface);

	daySurface = TTF_RenderText_Solid(font, _day.c_str(), textColor);
	timeSurface = TTF_RenderText_Solid(font, _time.c_str(), textColor);
	daytext = SDL_CreateTextureFromSurface(newrend, daySurface);
	timetext = SDL_CreateTextureFromSurface(newrend, timeSurface);
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
	mvwaddstr(_win, 1, 10, "Time");
	mvwaddstr(_win, 1, 1, "🕚");
	mvwaddstr(_win, 1, 20, "🕐");
	wattroff(_win, COLOR_PAIR(2));
	mvwprintw(_win, 2, 8, "%s", _day.c_str());// _year.c_str(), _month.c_str(), _day.c_str());
	mvwprintw(_win, 3, 8, "%s",  _time.c_str());
	mvwaddstr(_win, 3, 1, "🕢");
	mvwaddstr(_win, 3, 20, "🕠");
	SDL_RenderCopy(newrend, daytext, NULL, &dayRect);
	SDL_RenderCopy(newrend, timetext, NULL, &timeRect);
	getInfo();
}