/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:53:11 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 20:46:11 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hostname.hpp"

Hostname::Hostname(){
	_mode = 0;
	_win = newwin(5, 30, 0, 0);
	_width = 30;
	_height = 5;
	getInfo();
}

Hostname::~Hostname(){
	delwin(_win);
}

void	Hostname::getInfo(){
	char hostname[_SC_HOST_NAME_MAX];
	char username[_SC_LOGIN_NAME_MAX];
	gethostname(hostname, _SC_HOST_NAME_MAX);
	getlogin_r(username, _SC_LOGIN_NAME_MAX);
	this->_host = hostname;
	_host = " Hostname: " + _host;
	this->_user = username;
	_user = " Username: " + _user;
//	std::cout << "hostname: " << getHost() << std::endl;
//	std::cout << "username: " << getUser() << std::endl;
}

std::string Hostname::getHost(){
	return this->_host;
}

std::string Hostname::getUser(){
	return this->_user;
}

//Hostname::Hostname(bool mode): _mode(mode){
//	if (_mode == NCURSES) {
//		_win = newwin(0, 0, 5, 20);
//	}
//}

void Hostname::display() {
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
	mvwaddstr(_win, 1, 2, "   Host/user module");
	mvwaddstr(_win, 2, 1, _host.c_str());
	mvwaddstr(_win, 3, 1, _user.c_str());
}
