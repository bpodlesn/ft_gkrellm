/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:09:36 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 21:54:51 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "RAM.hpp"

RAM::RAM(SDL_Renderer *rend){
	newrend = rend;
	_mode = 0;
	_width = 30;
	_height = 15;
	_win = newwin(_height, _width, 6, 0);
	font = TTF_OpenFont("test.ttf", 13);
	frame_s.w = 800;
	frame_s.h = 519;
	frame_d.w = 120;
	frame_d.h = 120;
	usedSurface = nullptr;
	textColor.r = 0; textColor.g =255; textColor.b = 255; textColor.a = 255;
	for (int i = 0; i < 10; i++) {
		this->graph[i] = new Graph(100, 290, 20);
		this->graph2[i] = new Graph(220, 290, 140);
	}
	frame = IMG_Load("img/frame.png");
	frametext = SDL_CreateTextureFromSurface(newrend, frame);
	frametext2 = SDL_CreateTextureFromSurface(newrend, frame);
}

RAM::~RAM(){
	delwin(_win);
}

void	RAM::creategraph(int y, int x, int data){
	int newy = y - data;
	if (data < 30){
		// CPUColor.r = 0; CPUColor.g =255; CPUColor.b = 0; CPUColor.a = 255;
		SDL_SetRenderDrawColor(newrend, 0, 0xff, 0, 0xFF);
	}
	else if (data < 60){
		// CPUColor.r = 255; CPUColor.g =255; CPUColor.b = 0; CPUColor.a = 255;
		SDL_SetRenderDrawColor(newrend, 0xff, 0xff, 0, 0xFF);
	}
	else if (data <= 100){
		// CPUColor.r = 255; CPUColor.g = 0; CPUColor.b = 0; CPUColor.a = 255;
		SDL_SetRenderDrawColor(newrend, 0xFF, 0, 0, 0xFF);
	}
	int yy = y;
	for (int newx = x; newx < x + 10; newx++){
		y = yy;
		for (; y > newy; y--){
				SDL_RenderDrawPoint(newrend, newx, y);
		}
	}
}

void	RAM::draw_graph(Graph **gr, int k){
	for (int i = 0; i < 10; i++){
		if (gr[i]->getVisible() == false){
			for (int i = 0; i < 10; i++){
				if (gr[i]->getVisible() == true){
					gr[i]->setposX(gr[i]->getposX() - 10);
					creategraph(gr[i]->getposY(), gr[i]->getposX(), gr[i]->getData());
				}
			}
			gr[i]->setVisible(true);
			if (k == 0)
				gr[i]->setData(this->_ramused / 100);
			else if(k == 1)
				gr[i]->setData(this->_ramfree / 100);
			creategraph(gr[i]->getposY(), gr[i]->getposX(), gr[i]->getData());
			break;
		}
	}
}

void RAM::getInfo(){
	std::string line;
	system("top -n 0 -l 1 | grep -E '^PhysMem:' &> newinfo");
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

void RAM::setUsed(int u){
	this->_ramused = u;
}

void RAM::setFree(int f){
	this->_ramfree = f;
}

void RAM::display() {
	SDL_QueryTexture(usedtext, NULL, NULL, &dayRect.w, &dayRect.h);
	SDL_FreeSurface(usedSurface);

	dayRect.x = 50;dayRect.y = 300;
	textColor.r = 0; textColor.g =255; textColor.b = 255; textColor.a = 255;
	std::string newstr = std::to_string(_ramused);
	usedSurface = TTF_RenderText_Solid(font, newstr.c_str(), textColor);
	usedtext = SDL_CreateTextureFromSurface(newrend, usedSurface);
	SDL_RenderCopy(newrend, usedtext, NULL, &dayRect);
	dayRect.x = 180;dayRect.y = 300;
	newstr = std::to_string(_ramfree);
	usedSurface = TTF_RenderText_Solid(font, newstr.c_str(), textColor);
	usedtext = SDL_CreateTextureFromSurface(newrend, usedSurface);
	SDL_RenderCopy(newrend, usedtext, NULL, &dayRect);
	dayRect.x = 50;dayRect.y = 180;
	newstr = std::to_string(_ramfree);
	std::stringstream s1;
	std::stringstream s2;
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
		}
	}
	draw_graph(this->graph, 0);
	draw_graph(this->graph2, 1);
	frame_d.x = 10;	frame_d.y = 180;
	SDL_RenderCopy(newrend, frametext, &frame_s, &frame_d);
	frame_d.x = 130;	frame_d.y = 180;
	SDL_RenderCopy(newrend, frametext2, &frame_s, &frame_d);
	dayRect.x = 60;dayRect.y = 180;
	textColor.r = 255; textColor.g =255; textColor.b = 255; textColor.a = 255;
	usedSurface = TTF_RenderText_Solid(font, "Used", textColor);
	usedtext = SDL_CreateTextureFromSurface(newrend, usedSurface);
	SDL_RenderCopy(newrend, usedtext, NULL, &dayRect);
	dayRect.x = 180;dayRect.y = 180;
	newstr = std::to_string(_ramfree);
	usedSurface = TTF_RenderText_Solid(font, "Free", textColor);
	usedtext = SDL_CreateTextureFromSurface(newrend, usedSurface);
	SDL_RenderCopy(newrend, usedtext, NULL, &dayRect);
	getInfo();
	wrefresh(_win);
	wattron(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 1, 2, "        RAM module");
	wattroff(_win, COLOR_PAIR(1));
	mvwaddstr(_win, 2, 1, "RAM Used: ");
	wattron(_win, COLOR_PAIR(2));
	s1 << _ramused << "MB";
	mvwaddstr(_win, 2, 11, s1.str().c_str());
	wattroff(_win, COLOR_PAIR(2));
	mvwaddstr(_win, 3, 1, "RAM Free: ");
	wattron(_win, COLOR_PAIR(3));
	s2 << _ramfree << "MB";
	mvwaddstr(_win, 3, 11, s2.str().c_str());
	wattroff(_win, COLOR_PAIR(3));
	for (int k = 4; k < 13; k++) {
		mvwaddstr(_win, k, 4, "                      ");
	}
	//--------------------------------------------------
	wattron(_win, COLOR_PAIR(4));
	for (int k = 0; k < (_ramused * 10 / 8192); k++) {
		mvwaddstr(_win, 13 - k, 4, "          ");
	}
	wattroff(_win, COLOR_PAIR(4));
	wattron(_win, COLOR_PAIR(5));
	for (int k = 0; k < (_ramfree * 10 / 8192); k++) {
		mvwaddstr(_win, 13 - k, 16, "          ");
	}
	mvwaddstr(_win, 13, 16, "          ");
	wattroff(_win, COLOR_PAIR(5));
}

RAM::RAM(RAM const &cpy) {
	*this = cpy;
}

RAM &RAM::operator=(RAM const &cpy) {
	_win = cpy._win;
	_height = cpy._height;
	_width = cpy._width;
	_mode = cpy._mode;
	this->font = cpy.font;
	this->textColor = cpy.textColor;
	this->frame = cpy.frame;
	this->frametext = cpy.frametext;
	this->frametext2 = cpy.frametext2;
	this->newrend = cpy.newrend;
	this->frame_s = cpy.frame_s;
	this->frame_d = cpy.frame_d;
	this->usedtext = cpy.usedtext;
	this->dayRect = cpy.dayRect;
	for (int i = 0; i < 10; ++i) {
		graph[i] = cpy.graph[i];
	}
	for (int i = 0; i < 10; ++i) {
		graph2[i] = cpy.graph2[i];
	}
	return *this;
}
