/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:04:35 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 19:43:39 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Graph.hpp"

class CPU : public IMonitorModule, public IMonitorDisplay {
	std::string _cpuName;
	std::string _cores;
	int _usercpu;
	int _syscpu;
	int _idle;
	TTF_Font *font;
	SDL_Color textColor;
	SDL_Color CPUColor;
	SDL_Rect  CPURect;
	SDL_Surface* userSurface;
	SDL_Surface* sysSurface;
	SDL_Surface* idleSurface;
	SDL_Texture* usertext;
	SDL_Texture* systext;
	SDL_Texture* idletext;
	SDL_Surface* textSurface;
	SDL_Texture* text;
	SDL_Surface* coreSurface;
	SDL_Surface* frame;
	SDL_Texture* coretext;
	SDL_Surface* names;
	SDL_Texture* namestext;
	SDL_Texture* frametext;
	SDL_Texture* frametext2;
	SDL_Texture* frametext3;
	SDL_Renderer	*newrend;
	SDL_Rect 		textRect;
	SDL_Rect 		coreRect;
	SDL_Rect		frame_s;
	SDL_Rect		frame_d;
	Graph			*graph[10];
	Graph 			*graph2[10];
	Graph 			*graph3[10];
public:
	CPU(){};
	CPU(SDL_Renderer *rend);
	~CPU();
	virtual void getInfo();
	virtual void display();
	std::string getCpuName();
	std::string getCores();
	double getUserCpu();
	double getSysCpu();
	double getIdle();
	void draw_graph(Graph **gr, int k);
	void creategraph(int y, int x, int data);
	void scale();
};

#endif