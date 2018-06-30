/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OS.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:01:43 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 17:09:13 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_HPP
# define OS_HPP

#include "IMonitorModule.hpp"

class OS
{
	std::string _name;
	std::string _version;
public:
	OS();
	~OS();
	virtual void getInfo();
	std::string getName();
	std::string getVersion();
};

#endif
