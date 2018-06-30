/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:04:58 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 18:24:01 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPU.hpp"

CPU::CPU(){};

CPU::~CPU(){};


void CPU::getInfo(){
	char strcpu[256];
	size_t size = sizeof(strcpu);
	int ret = sysctlbyname("machdep.cpu.brand_string", strcpu, &size, NULL, 0);
	this->_cpuName = strcpu;
	int core_count;
	ret = sysctlbyname("machdep.cpu.core_count", &core_count, &size, NULL, 0);
	this->_cores = std::to_string(core_count);
	system("top -l 1 | grep -E '^CPU' &> newinfo");
	std::ifstream cpu_usage ("newinfo");
	std::string line;
	getline(cpu_usage, line, ' ');
	getline(cpu_usage, line, ' ');
	getline(cpu_usage, line, ' ');
	this->_usercpu = std::strtod(line.data(), NULL);
	getline(cpu_usage, line, ' ');
	getline(cpu_usage, line, ' ');
	this->_syscpu = std::strtod(line.data(), NULL);
	getline(cpu_usage, line, ' ');
	getline(cpu_usage, line, ' ');
	this->_idle = std::strtod(line.data(), NULL);
	cpu_usage.close();
	system("rm newinfo");
}

std::string getCpuName(){
	return this->_cpuName;
}

std::string getCores(){
	return this->_cores;
}

double getUserCpu(){
	return this->_usercpu;
}

double getSysCpu(){
	return this->_syscpu;
}

double getIdle(){
	return this->_idle;
}
