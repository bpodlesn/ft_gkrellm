/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:39:16 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 18:03:56 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP
# include "frameworks/SDL2.framework/Headers/SDL.h"
# include "frameworks/SDL2.framework/Headers/SDL_opengl.h"
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
