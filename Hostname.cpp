/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:53:11 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 17:08:11 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hostname.hpp"

Hostname::Hostname(){};
Hostname::~Hostname(){};

void	Hostname::getInfo(){
	char hostname[_SC_HOST_NAME_MAX];
	char username[_SC_LOGIN_NAME_MAX];
	gethostname(hostname, _SC_HOST_NAME_MAX);
	getlogin_r(username, _SC_LOGIN_NAME_MAX);
	this->_host = hostname;
	this->_user = username;
	std::cout << "hostname: " << getHost() << std::endl;
	std::cout << "username: " << getUser() << std::endl;
}

std::string Hostname::getHost(){
	return this->_host;
}

std::string Hostname::getUser(){
	return this->_user;
}