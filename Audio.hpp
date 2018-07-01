/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Audio.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 20:03:15 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 21:24:08 by bpodlesn         ###   ########.fr       */
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
};


#endif
