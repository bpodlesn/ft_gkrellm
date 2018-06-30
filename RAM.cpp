/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:09:36 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 21:21:47 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "RAM.hpp"

RAM::RAM(){
	_mode = 0;
	_width = 30;
	_height = 15;
	_win = newwin(_height, _width, 6, 0);
}

RAM::~RAM(){
	delwin(_win);
}

void RAM::getInfo(){
	std::string line;
	system("top -l 1 | grep -E '^PhysMem:' &> newinfo");
	std::ifstream ram_usage ("newinfo");
	getline(ram_usage, line, ' ');
	getline(ram_usage, line, 'M');
	this->_ramused = static_cast<int>(std::strtod(line.data(), NULL));
 	this->_ramfree = 8192 - this->_ramused;
	ram_usage.close();
	system("rm newinfo");
}

int	RAM::getRamUsed(){
	return this->_ramused;
}

int	RAM::getRamFree(){
	return this->_ramfree;
}

void RAM::display() {
	std::stringstream s1;
	std::stringstream s2;
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
	getInfo();
	s1 << "RAM Used: " << _ramused << "MB";
	mvwaddstr(_win, 1, 2, "        RAM module");
	mvwaddstr(_win, 2, 1, s1.str().c_str());
	s2 << "RAM Free: " << _ramfree << "MB";
	mvwaddstr(_win, 3, 1, s2.str().c_str());
}