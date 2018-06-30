/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:02:20 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 17:11:49 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OS.hpp"

OS::OS(){};
OS::~OS(){};

void OS::getInfo(){
	char str[256];
	size_t size = sizeof(str);
	int ret = sysctlbyname("kern.osproductversion", str, &size, NULL, 0);
	if (str[4] == '3'){
		this->_name = "macOS High Siera";
	} else if (str[4] == '2'){
		this->_name = "macOS Siera";
	} else if (str[4] == '1'){
		this->_name = "OS X El Capitan";
	}
	this->_version = str;
}

std::string OS::getName(){
	return this->_name;
}

std::string OS::getVersion(){
	return this->_version;
}
