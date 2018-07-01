/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 18:22:24 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 21:40:05 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GPU_HPP
#define GPU_HPP
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class GPU : public IMonitorModule, public IMonitorDisplay {
	std::string _name;
	std::string _VRAM;
	std::string _driver;
	TTF_Font *font;
	SDL_Rect 	dayRect;
	SDL_Renderer	*newrend;
public:
	GPU(){};
	GPU(SDL_Renderer *rend);
	virtual ~GPU();
	void display();
	void getInfo();
	GPU(GPU const & cpy);
	GPU &operator=(GPU const & cpy);

};


#endif

