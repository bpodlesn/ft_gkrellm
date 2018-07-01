/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bluetooth.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 19:35:11 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 21:14:37 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLUETOOTH_HPP
#define BLUETOOTH_HPP


#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Bluetooth : public IMonitorModule, public IMonitorDisplay  {
	std::string _version;
	std::string _addr;
	std::string _chip;
public:
	Bluetooth();
	Bluetooth(Bluetooth const & cpy);
	virtual ~Bluetooth();
	void display();
	void getInfo();
	Bluetooth &operator=(Bluetooth const & cpy);

};


#endif
