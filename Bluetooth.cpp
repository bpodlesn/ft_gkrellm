//
// Created by Valentine MAZUROK on 7/1/18.
//

#include "Bluetooth.hpp"

Bluetooth::Bluetooth() {
	_mode = NCURSES;
	_width = 30;
	_height = 6;
	_win = newwin(_height, _width, 22, 0);
	getInfo();
}

Bluetooth::~Bluetooth() {
	delwin(_win);
}

void Bluetooth::display() {
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
	mvwaddstr(_win, 1, 2, "   Bluetooth Module");
	wattroff(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 2, 2, "Software Version:");
	mvwaddstr(_win, 2, 20, _version.c_str());
	mvwaddstr(_win, 3, 2, "Address:");
	mvwaddstr(_win, 3, 11, _addr.c_str());
	mvwaddstr(_win, 4, 2, "Chipset:");
	mvwaddstr(_win, 4, 11, _chip.c_str());
}

void Bluetooth::getInfo() {
	std::string line("");
	system("system_profiler SPBluetoothDataType &> newinfo");
	std::ifstream in ("newinfo");
	while (line.find("Version:") == line.npos)
		getline(in, line);
	_version = line.substr(line.find(": ") + 2);
	while (line.find("Address:") == line.npos)
		getline(in, line);
	_addr = line.substr(line.find(": ") + 2);
	while (line.find("Chipset:") == line.npos)
		getline(in, line);
	_chip = line.substr(line.find(": ") + 2);
	in.close();
	system("rm newinfo");
}

Bluetooth::Bluetooth(Bluetooth const &cpy) {
	*this = cpy;
}

Bluetooth &Bluetooth::operator=(Bluetooth const &cpy) {
	_win = cpy._win;
	_chip = cpy._chip;
	_addr = cpy._addr;
	_version = cpy._version;
	_height = cpy._height;
	_width = cpy._width;
	_mode = cpy._mode;
	return *this;
}
