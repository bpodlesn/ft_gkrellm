/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:52:01 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 19:52:01 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPU.hpp"

CPU::CPU(SDL_Renderer *rend){
	newrend = rend;
	_mode = NCURSES;
	_width = 30;
	_height = 15;
	_win = newwin(_height, _width, 6, _width + 3);
	textColor.r = 0; textColor.g =255; textColor.b = 255; textColor.a = 255;
	font = TTF_OpenFont("test.ttf", 13);
	textRect.x = 210;textRect.y = 440;
	coreRect.x = 510;coreRect.y = 465;
	textSurface = nullptr;
	coreSurface = nullptr;
	frame_s.w = 800;
	frame_s.h = 519;
	frame_d.w = 120;
	frame_d.h = 120;
	for (int i = 0; i < 10; i++) {
		this->graph[i] = new Graph(100, 120, 20);
		this->graph2[i] = new Graph(220, 120, 140);
		this->graph3[i] = new Graph(340, 120, 260);
	}
	frame = IMG_Load("img/frame.png");
	frametext = SDL_CreateTextureFromSurface(newrend, frame);
	frametext2 = SDL_CreateTextureFromSurface(newrend, frame);
	frametext3 = SDL_CreateTextureFromSurface(newrend, frame);
	getInfo();
}

CPU::~CPU(){
	delwin(_win);
}

void	CPU::creategraph(int y, int x, int data){
	int newy = y - data;
	if (data < 30){
		CPUColor.r = 0; CPUColor.g =255; CPUColor.b = 0; CPUColor.a = 255;
		SDL_SetRenderDrawColor(newrend, 0, 0xff, 0, 0xFF);
	}
	else if (data < 60){
		CPUColor.r = 255; CPUColor.g =255; CPUColor.b = 0; CPUColor.a = 255;
		SDL_SetRenderDrawColor(newrend, 0xff, 0xff, 0, 0xFF);
	}
	else if (data <= 100){
		CPUColor.r = 255; CPUColor.g = 0; CPUColor.b = 0; CPUColor.a = 255;
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

void	CPU::draw_graph(Graph **gr, int k){
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
				gr[i]->setData(this->_usercpu);
			else if(k == 1)
				gr[i]->setData(this->_syscpu);
			else if(k == 2)
				gr[i]->setData(this->_idle);
			creategraph(gr[i]->getposY(), gr[i]->getposX(), gr[i]->getData());
			break;
		}
	}
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

void CPU::scale(){
}

void CPU::display() {
	std::stringstream ss;
	setlocale(LC_ALL, "");
	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
	SDL_QueryTexture(coretext, NULL, NULL, &coreRect.w, &coreRect.h);
	SDL_QueryTexture(usertext, NULL, NULL, &CPURect.w, &CPURect.h);
	SDL_QueryTexture(systext, NULL, NULL, &CPURect.w, &CPURect.h);
	SDL_QueryTexture(idletext, NULL, NULL, &CPURect.w, &CPURect.h);
	SDL_QueryTexture(namestext, NULL, NULL, &CPURect.w, &CPURect.h);
	SDL_FreeSurface(textSurface);
	SDL_FreeSurface(coreSurface);
	SDL_FreeSurface(userSurface);
	SDL_FreeSurface(sysSurface);
	SDL_FreeSurface(idleSurface);
	SDL_FreeSurface(names);
	std::string newcores = "Cores: " + _cores;
	
	textSurface = TTF_RenderText_Solid(font, _cpuName.c_str(), textColor);
	coreSurface = TTF_RenderText_Solid(font, newcores.c_str(), textColor);

	
	text = SDL_CreateTextureFromSurface(newrend, textSurface);
	coretext = SDL_CreateTextureFromSurface(newrend, coreSurface);
	

	draw_graph(this->graph, 0);
	std::string newstr = std::to_string(_usercpu) + "%";
	userSurface = TTF_RenderText_Solid(font, newstr.c_str(), CPUColor);
	usertext = SDL_CreateTextureFromSurface(newrend, userSurface);
	draw_graph(this->graph2, 1);
	newstr = std::to_string(_syscpu) + "%";
	sysSurface = TTF_RenderText_Solid(font, newstr.c_str(), CPUColor);
	systext = SDL_CreateTextureFromSurface(newrend, sysSurface);
	draw_graph(this->graph3, 2);
	newstr = std::to_string(_idle) + "%";
	idleSurface = TTF_RenderText_Solid(font, newstr.c_str(), CPUColor);
	idletext = SDL_CreateTextureFromSurface(newrend, idleSurface);
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
	wrefresh(_win);
	SDL_RenderCopy(newrend, text, NULL, &textRect);
	SDL_RenderCopy(newrend, coretext, NULL, &coreRect);
	CPURect.x = 60; CPURect.y = 130;
	SDL_RenderCopy(newrend, usertext, NULL, &CPURect);
	CPURect.x = 180; CPURect.y = 130;
	SDL_RenderCopy(newrend, systext, NULL, &CPURect);
	CPURect.x = 300; CPURect.y = 130;
	SDL_RenderCopy(newrend, idletext, NULL, &CPURect);
	frame_d.x = 10;	frame_d.y = 10;
	SDL_RenderCopy(newrend, frametext, &frame_s, &frame_d);
	frame_d.x = 130; frame_d.y = 10;
	SDL_RenderCopy(newrend, frametext2, &frame_s, &frame_d);
	frame_d.x = 250; frame_d.y = 10;
	SDL_RenderCopy(newrend, frametext3, &frame_s, &frame_d);
		CPUColor.r = 255; CPUColor.g = 255; CPUColor.b = 255; CPUColor.a = 255;
	names = TTF_RenderText_Solid(font, "User", CPUColor);
	namestext = SDL_CreateTextureFromSurface(newrend, names);
	CPURect.x = 70; CPURect.y = 10;
	SDL_RenderCopy(newrend, namestext, NULL, &CPURect);
	names = TTF_RenderText_Solid(font, "System", CPUColor);
	namestext = SDL_CreateTextureFromSurface(newrend, names);
	CPURect.x = 190; CPURect.y = 10;
	SDL_RenderCopy(newrend, namestext, NULL, &CPURect);
	names = TTF_RenderText_Solid(font, "Idle", CPUColor);
	namestext = SDL_CreateTextureFromSurface(newrend, names);
	CPURect.x = 310; CPURect.y = 10;
	SDL_RenderCopy(newrend, namestext, NULL, &CPURect);
	_cpuName.resize(26);
	scale();
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
	getInfo();
}
