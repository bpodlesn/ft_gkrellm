/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:48:27 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 21:43:29 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class Hostname : public IMonitorModule, public IMonitorDisplay{
	std::string _host;
	std::string _user;
	TTF_Font *font;
	SDL_Color textColor;
	SDL_Surface* hostSurface;
	SDL_Texture* host;
	SDL_Surface* userSurface;
	SDL_Texture* usertext;
	SDL_Renderer	*newrend;
	SDL_Rect 		hostRect;
	SDL_Rect 		userRect;
public:
	Hostname(){};
	Hostname(SDL_Renderer *rend);
	virtual ~Hostname();
	void getInfo();
	void display();
	std::string getHost();
	std::string getUser();
	Hostname(Hostname const & cpy);
	Hostname &operator=(Hostname const & cpy);
};

#endif
