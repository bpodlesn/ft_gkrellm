/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Audio.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 20:09:22 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 20:38:41 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Audio.hpp"

Audio::Audio() {
	_mode = NCURSES;
	_width = 30;
	_height = 6;
	_win = newwin(_height, _width , 22, _width * 2 + 5);
	getInfo();
}

Audio::~Audio() {
	delwin(_win);
}

void Audio::getInfo() {
	std::string line("");
	system("system_profiler SPAudioDataType &> newinfo");
	std::ifstream in ("newinfo");
	while (line.find("Manufacturer:") == line.npos)
		getline(in, line);
	_man = line.substr(line.find(": ") + 2);
	while (line.find("SampleRate:") == line.npos)
		getline(in, line);
	_microSample = line.substr(line.find(": ") + 2);
	_microSample += " Hz";;
	line.clear();
	while (line.find("SampleRate:") == line.npos)
		getline(in, line);
	_audioSample = line.substr(line.find(": ") + 2);
	_audioSample  += " Hz";
	in.close();
	system("rm newinfo");
}

void Audio::display() {
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
	mvwaddstr(_win, 1, 2, "     Audio Module");
	wattroff(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 2, 2, "Manufacturer:");
	mvwaddstr(_win, 2, 15, _man.c_str());
	mvwaddstr(_win, 3, 2, "Micro SampleRate:");
	mvwaddstr(_win, 3, 19, _microSample.c_str());
	mvwaddstr(_win, 4, 2, "Speak SampleRate:");
	mvwaddstr(_win, 4, 29, _audioSample.c_str());
}
