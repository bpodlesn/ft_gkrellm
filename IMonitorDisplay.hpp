/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:39:16 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 15:48:54 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP
# include "SDL.h"
# include "SDL_opengl.h"
# include "frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "frameworks/SDL2_image.framework/Headers/SDL_image.h"
# include <ncurses.h>
# define NCURSES 0
# define SDL 1

class IMonitorDisplay
{
protected:
	bool _mode;
	int _width;
	int _height;
	WINDOW * _win;
public:
	virtual ~IMonitorDisplay(){};
	virtual void display() = 0;
};

#endif
