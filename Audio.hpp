/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Audio.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 20:03:15 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 21:28:57 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUDIO_HPP
#define AUDIO_HPP


#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Audio : public IMonitorModule, public IMonitorDisplay  {
	std::string _man;
	std::string _microSample;
	std::string _audioSample;
	TTF_Font *font;
	SDL_Surface* usedSurface;
	SDL_Texture* usedtext;
	SDL_Rect 	dayRect;
	SDL_Color textColor;
	SDL_Renderer	*newrend;
public:
	Audio(){};
	Audio(SDL_Renderer	*rend);
	void getInfo();
	void display();
	virtual ~Audio();
	Audio(Audio const & cpy);
	Audio &operator=(Audio const & cpy);
};


#endif
