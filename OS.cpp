/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:02:20 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 21:39:13 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OS.hpp"

OS::OS(){
	_mode = 0;
	_win = newwin(5, 20, 0, 35);
	_width = 20;
	_height = 5;
	getInfo();
};
OS::~OS(){};

void OS::getInfo(){
	char str[256];
	size_t size = sizeof(str);
	int ret;
	ret = sysctlbyname("kern.osproductversion", str, &size, NULL, 0);
	if (str[4] == '3'){
		this->_name = "macOS High Siera";
	} else if (str[4] == '2'){
		this->_name = "macOS Siera";
	} else if (str[4] == '1'){
		this->_name = "OS X El Capitan";
	}
	this->_version = str;
}

std::string OS::getName(){
	return this->_name;
}

std::string OS::getVersion(){
	return this->_version;
}

void OS::display(){
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
	mvwaddstr(_win, 1, 2, "    OS module");
	wattroff(_win, COLOR_PAIR(2));
	mvwaddstr(_win, 2, 2, _name.c_str());
	mvwprintw(_win, 3, 2, "Version: %s", _version.c_str());
	getInfo();
}
