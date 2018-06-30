/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:08:47 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 18:21:36 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP

# include "IMonitorModule.hpp"

class RAM : public IMonitorModule{
	int	_ramused;
	int _ramfree;
public:
	RAM();
	~RAM();
	virtual void getInfo();
	int getRamUsed(){};
	int getRamFree(){};
};

#endif