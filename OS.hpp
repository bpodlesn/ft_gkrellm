/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:01:43 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 21:45:55 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_HPP
# define OS_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class OS : public IMonitorModule, public IMonitorDisplay
{
	std::string _name;
	std::string _version;
	TTF_Font *font;
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Surface* versSurf;
	SDL_Texture* text;
	SDL_Texture* verstext;
	SDL_Renderer	*newrend;
	SDL_Rect 		textRect;
	SDL_Rect		versRect;
public:
	OS();
	OS(SDL_Renderer	*rend);
	~OS();
	virtual void getInfo();
	virtual void display();
	std::string getName();
	std::string getVersion();
	OS(OS const & cpy);
	OS &operator=(OS const & cpy);
};

#endif
