/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:26:52 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 20:55:30 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_HPP
# define NETWORK_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Network : public IMonitorModule, public IMonitorDisplay  {
	std::string _pocketsIn;
	std::string _pocketsOut;
public:
	Network();
	Network(Network const & cpy);
	virtual ~Network();
	virtual void getInfo();
	virtual void display();
	Network &operator=(Network const & cpy);
};


#endif
