/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTime.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:12:40 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 21:43:52 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTime.hpp"

DateTime::DateTime(){
	_mode = 0;
	_win = newwin(5, 23, 0, 60);
	_width = 23;
	_height = 5;
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
	getInfo();
}