/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTime.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:12:40 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 17:27:19 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateTime.hpp"

DateTime::DateTime(){};
DateTime::~DateTime(){};

void DateTime::getInfo(){
	time_t now = time(0);
	tm *ltm = localtime(&now);

	this->_year = std::to_string(ltm->tm_year + 1900);
	this->_month = std::to_string(1 + ltm->tm_mon);
	this->_day = std::to_string(ltm->tm_mday);
	this->_time = std::to_string(1 + ltm->tm_hour) + ":" 
	+ std::to_string(1 + ltm->tm_min) + ":"
	+ std::to_string(1 + ltm->tm_sec);
	std::cout << "Year: " << this->_year << std::endl;
   std::cout << "Month: "<< this->_month<< std::endl;
   std::cout << "Day: "<< this->_day << std::endl;
   std::cout << "Time: "<< this->_time << std::endl;
}

std::string DateTime::getYear(){
	return this->_year;
}

std::string DateTime::getMonth(){
	return this->_month;
}

std::string DateTime::getDay(){
	return this->_day;
}

std::string DateTime::getTime(){
	return this->_time;
}
