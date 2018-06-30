/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTime.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:12:11 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 17:26:36 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIME_HPP
# define DATETIME_HPP

# include "IMonitorModule.hpp"

class DateTime : public IMonitorModule{
	std::string _year;
	std::string _month;
	std::string _day;
	std::string _time;
public:
	DateTime();
	~DateTime();
	virtual void getInfo();
	std::string getYear();
	std::string getMonth();
	std::string getDay();
	std::string getTime();
};

#endif