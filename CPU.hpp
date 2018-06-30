/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:04:35 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 21:23:45 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class CPU : public IMonitorModule, public IMonitorDisplay {
	std::string _cpuName;
	std::string _cores;
	double _usercpu;
	double _syscpu;
	double _idle;
public:
	CPU();
	~CPU();
	virtual void getInfo();
	virtual void display();
	std::string getCpuName();
	std::string getCores();
	double getUserCpu();
	double getSysCpu();
	double getIdle();
};

#endif