/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:53:11 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 18:48:11 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hostname.hpp"

Hostname::Hostname(SDL_Renderer *rend){
	newrend = rend;
	_mode = 0;
	_win = newwin(5, 30, 0, 0);
	_width = 30;
	_height = 5;
	textColor.r = 0; textColor.g =255; textColor.b = 255; textColor.a = 255;
	font = TTF_OpenFont("test.ttf", 11);
	hostRect.x = 200;hostRect.y = 495;
	userRect.x = 445;userRect.y = 495;
	hostSurface = nullptr;
	userSurface = nullptr;
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
}

std::string Hostname::getHost(){
	return this->_host;
}

std::string Hostname::getUser(){
	return this->_user;
}

void Hostname::display() {
	setlocale(LC_ALL, "");
	SDL_QueryTexture(host, NULL, NULL, &hostRect.w, &hostRect.h);
	SDL_QueryTexture(usertext, NULL, NULL, &userRect.w, &userRect.h);
	SDL_FreeSurface(hostSurface);
	SDL_FreeSurface(userSurface);
	hostSurface = TTF_RenderText_Solid(font, _host.c_str(), textColor);
	userSurface = TTF_RenderText_Solid(font, _user.c_str(), textColor);
	host = SDL_CreateTextureFromSurface(newrend, hostSurface);
	usertext = SDL_CreateTextureFromSurface(newrend, userSurface);
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
	SDL_RenderCopy(newrend, host, NULL, &hostRect);
	SDL_RenderCopy(newrend, usertext, NULL, &userRect);
	wattron(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 1, 2, "     Host/user module");
	wattroff(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 2, 1, _host.c_str());
	mvwaddstr(_win, 3, 1, _user.c_str());
}
