/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:04:58 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 11:58:28 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "CPU.hpp"

CPU::CPU(){
	_mode = NCURSES;
	_width = 30;
	_height = 15;
	_win = newwin(_height, _width, 6, _width + 3);
}

CPU::~CPU(){
	delwin(_win);
}


void CPU::getInfo(){
	char strcpu[256];
	size_t size = sizeof(strcpu);
	int ret = sysctlbyname("machdep.cpu.brand_string", strcpu, &size, NULL, 0);
	this->_cpuName = strcpu;
	int core_count;
	ret = sysctlbyname("machdep.cpu.core_count", &core_count, &size, NULL, 0);
	this->_cores = std::to_string(core_count);
	system("top -l 1 | grep -E '^CPU' &> newinfo");
	std::ifstream cpu_usage ("newinfo");
	std::string line;
	getline(cpu_usage, line, ' ');
	getline(cpu_usage, line, ' ');
	getline(cpu_usage, line, ' ');
	this->_usercpu = std::strtod(line.data(), NULL);
	getline(cpu_usage, line, ' ');
	getline(cpu_usage, line, ' ');
	this->_syscpu = std::strtod(line.data(), NULL);
	getline(cpu_usage, line, ' ');
	getline(cpu_usage, line, ' ');
	this->_idle = std::strtod(line.data(), NULL);
	cpu_usage.close();
	system("rm newinfo");
}

std::string CPU::getCpuName(){
	return this->_cpuName;
}

std::string CPU::getCores(){
	return this->_cores;
}

double CPU::getUserCpu(){
	return this->_usercpu;
}

double CPU::getSysCpu(){
	return this->_syscpu;
}

double CPU::getIdle(){
	return this->_idle;
}

void CPU::display() {
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
	_cpuName.resize(26);
	wattron(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 1, 2, "        CPU module");
	wattroff(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 2, 1, _cpuName.c_str());
	ss.str("");
	ss << "Number of cores: " << _cores << " ";
	mvwaddstr(_win, 3, 1, ss.str().c_str());
	ss.str("");
	mvwaddstr(_win, 4, 1, "User CPU usade:   ");
	wattron(_win, COLOR_PAIR(2));
	ss << _usercpu << "%     ";
	mvwaddstr(_win, 4, 19, ss.str().c_str());
	wattroff(_win, COLOR_PAIR(2));
	ss.str("");
	mvwaddstr(_win, 5, 1, "System CPU usade: ");
	wattron(_win, COLOR_PAIR(6));
	ss << _syscpu << "%     ";
	mvwaddstr(_win, 5, 19, ss.str().c_str());
	wattroff(_win, COLOR_PAIR(6));
	ss.str("");
	mvwaddstr(_win, 6, 1, "Idle:             ");
	wattron(_win, COLOR_PAIR(3));
	ss << _idle << "%     ";
	mvwaddstr(_win, 6, 19, ss.str().c_str());
	wattroff(_win, COLOR_PAIR(3));
	//---------------------------------------------
	wattron(_win, COLOR_PAIR(4));
	for (int k = 0; k < (_usercpu * 8 / 100); k++) {
		mvwaddstr(_win, 13 - k, 2, "        ");
	}
	wattroff(_win, COLOR_PAIR(4));
	for (int k = 7; k < 14 - (_usercpu * 8 / 100); k++) {
		mvwaddstr(_win, k, 2, "        ");
	}
	wattron(_win, COLOR_PAIR(7));
	for (int k = 0; k < (_syscpu * 8 / 100); k++) {
		mvwaddstr(_win, 13 - k, 11, "        ");
	}
	wattroff(_win, COLOR_PAIR(7));
	for (int k = 7; k < 14 - (_syscpu * 8 / 100); k++) {
		mvwaddstr(_win, k, 11, "        ");
	}
	wattron(_win, COLOR_PAIR(5));
	for (int k = 0; k < (_idle * 8 / 100); k++) {
		mvwaddstr(_win, 13 - k, 20, "        ");
	}
	wattroff(_win, COLOR_PAIR(5));
	for (int k = 7; k < 14 - (_idle * 8 / 100); k++) {
		mvwaddstr(_win, k, 20, "        ");
	}
}
