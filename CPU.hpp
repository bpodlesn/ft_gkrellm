/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:04:35 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 18:23:21 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP

#include "IMonitorModule.hpp"

class CPU
{
	std::string _cpuName;
	std::string _cores;
	double _usercpu;
	double _syscpu;
	double _idle;
public:
	CPU();
	~CPU();
	virtual void getInfo();
	std::string getCpuName();
	std::string getCores();
	double getUserCpu();
	double getSysCpu();
	double getIdle();
};

#endif