/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:34:26 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 19:28:10 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/sysctl.h>
#include <ctime>
#include <mach/mach_host.h>
#include <mach/processor_info.h>
#include <fstream>

class IMonitorModule
{
private:

public:
	virtual ~IMonitorModule(){};
	virtual void getInfo() = 0;
};

#endif
