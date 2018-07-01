/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:08:47 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 21:50:42 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP

# include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Graph.hpp"

class RAM : public IMonitorModule, public IMonitorDisplay{
	int	_ramused;
	int _ramfree;
	TTF_Font *font;
	SDL_Surface* frame;
	SDL_Texture* frametext;
	SDL_Texture* frametext2;
	SDL_Color textColor;
	SDL_Renderer	*newrend;
	Graph			*graph[10];
	Graph 			*graph2[10];
	SDL_Rect		frame_s;
	SDL_Rect		frame_d;
	SDL_Surface* usedSurface;
	SDL_Texture* usedtext;
	SDL_Rect 		dayRect;
public:
	RAM(){};
	RAM(SDL_Renderer *rend);
	~RAM();
	virtual void getInfo();
	virtual void display();
	int getRamUsed();
	int getRamFree();
	void setUsed(int u);
	void setFree(int f);
	void creategraph(int y, int x, int data);
	void draw_graph(Graph **gr, int k);
	RAM(RAM const & cpy);
	RAM &operator=(RAM const & cpy);
};

#endif