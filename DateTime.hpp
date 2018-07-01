/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTime.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:12:11 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 16:10:16 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIME_HPP
# define DATETIME_HPP

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class DateTime : public IMonitorModule, public IMonitorDisplay{
	std::string _day;
	std::string _time;
	TTF_Font *font;
	SDL_Color textColor;
	SDL_Surface* daySurface;
	SDL_Texture* daytext;
	SDL_Surface* timeSurface;
	SDL_Texture* timetext;
	SDL_Renderer	*newrend;
	SDL_Rect 		dayRect;
	SDL_Rect 		timeRect;
public:
	DateTime(){};
	DateTime(SDL_Renderer *rend);
	~DateTime();
	virtual void getInfo();
	virtual void display();
	std::string getYear();
	std::string getMonth();
	std::string getDay();
	std::string getTime();
};

#endif