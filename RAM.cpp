/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:09:36 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 18:22:21 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAM.hpp"

RAM::RAM(){}

RAM::~RAM(){}

void RAM::getInfo(){
	std::string line;
	system("top -l 1 | grep -E '^PhysMem:' &> newinfo");
	std::ifstream ram_usage ("newinfo");
	getline(ram_usage, line, ' ');
	getline(ram_usage, line, 'M');
	this->_ramused = std::strtod(line.data(), NULL);
	std::cout << this->_ramused << std::endl;
	this->_ramfree = 8192 - this->_ramused;
	ram_usage.close();
	system("rm newinfo");
}

int	RAM::getRamUsed(){
	return this->_ramused;
}

int	RAM::getRamFree(){
	return this->_ramfree;
}
