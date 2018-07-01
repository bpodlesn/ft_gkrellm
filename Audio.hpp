/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Audio.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 20:03:15 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 20:13:33 by vmazurok         ###   ########.fr       */
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
public:
	Audio();
	void getInfo();
	void display();
	virtual ~Audio();
};


#endif
