/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:41:10 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/06/30 20:41:00 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Hostname.hpp"
//#include "OS.hpp"
//#include "CPU.hpp"
//#include "RAM.hpp"
//#include "DateTime.hpp"

int	main(){
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	Hostname host;
//	OS os;
//	CPU cpu;
//	RAM ram;
//	DateTime time;
	while (getch() != 27) {
		host.display();
	}
	endwin();
//	os.getInfo();
//	cpu.getInfo();
//	ram.getInfo();
//	time.getInfo();

	//hostname and username

	//version
	// 


	// 


	// // current date/time based on current system
 //    CpuUsage a(0), b(1), c(2), d(3);
 //    sleep(1);
 //  std::cout << (a.get() +  b.get() + c.get() + d.get()) / 4 << std::endl;
 //  sleep(1);
 //  std::cout << (a.get() +  b.get() + c.get() + d.get()) / 4 << std::endl;
 //  sleep(1);
 //  std::cout << (a.get() +  b.get() + c.get() + d.get()) / 4<< std::endl;
 //  return 0;

}