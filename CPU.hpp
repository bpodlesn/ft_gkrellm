/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:04:35 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 16:12:56 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class CPU : public IMonitorModule, public IMonitorDisplay {
	std::string _cpuName;
	std::string _cores;
	double _usercpu;
	double _syscpu;
	double _idle;
	TTF_Font *font;
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Texture* text;
	SDL_Surface* coreSurface;
	SDL_Texture* coretext;
	SDL_Renderer	*newrend;
	SDL_Rect 		textRect;
	SDL_Rect 		coreRect;
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
};

#endif