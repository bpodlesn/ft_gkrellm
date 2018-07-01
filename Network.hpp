/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:26:52 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 20:57:04 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_HPP
# define NETWORK_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Network : public IMonitorModule, public IMonitorDisplay  {
	std::string _pocketsIn;
	std::string _pocketsOut;
	TTF_Font *font;
	SDL_Surface* usedSurface;
	SDL_Texture* usedtext;
	SDL_Rect 	dayRect;
	SDL_Color textColor;
	SDL_Renderer	*newrend;
public:
	Network(){};
	Network(SDL_Renderer	*newrend);
	Network(Network const & cpy);
	virtual ~Network();
	virtual void getInfo();
	virtual void display();
	Network &operator=(Network const & cpy);
};


#endif
