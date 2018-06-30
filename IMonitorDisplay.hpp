/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:39:16 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 20:35:18 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP
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
