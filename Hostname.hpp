/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 15:48:27 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 17:07:28 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

# include "IMonitorModule.hpp"

class Hostname : public IMonitorModule{
	std::string _host;
	std::string _user;
public:
	Hostname();
	~Hostname();
	virtual void getInfo();
	std::string getHost();
	std::string getUser();
};

#endif
