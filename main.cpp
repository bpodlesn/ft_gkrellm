/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 21:52:58 by vmazurok          #+#    #+#             */
/*   Updated: 2018/06/30 21:56:54 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Hostname.hpp"
#include "OS.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "DateTime.hpp"
#include <locale>

int	main(){
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	Hostname host;
	OS os;
	CPU cpu;
	RAM ram;
	DateTime time;
	while (getch() != 27) {
		host.display();
		ram.display();
		cpu.display();
		os.display();
		time.display();
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