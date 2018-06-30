/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:48:27 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 20:35:15 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"

class Hostname : public IMonitorModule, public IMonitorDisplay{
	std::string _host;
	std::string _user;
public:
	Hostname();
	virtual ~Hostname();
	void getInfo();
	void display();
	std::string getHost();
	std::string getUser();
};

#endif
