/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 18:22:24 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 18:31:37 by vmazurok         ###   ########.fr       */
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
public:
	GPU();
	virtual ~GPU();
	void display();
	void getInfo();

};


#endif

