/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:08:47 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 21:01:00 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP

# include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class RAM : public IMonitorModule, public IMonitorDisplay{
	int	_ramused;
	int _ramfree;
public:
	RAM();
	~RAM();
	virtual void getInfo();
	virtual void display();
	int getRamUsed();
	int getRamFree();
};

#endif