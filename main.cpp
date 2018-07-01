/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 21:52:58 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 14:20:07 by vmazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Hostname.hpp"
#include "OS.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "DateTime.hpp"
#include "Network.hpp"
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
	init_pair(4, COLOR_GREEN, COLOR_GREEN);
	init_pair(5, COLOR_RED, COLOR_RED);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_BLUE, COLOR_BLUE);
	Hostname host;
	OS os;
	CPU cpu;
	RAM ram;
	DateTime time;
	Network n;
	while (getch() != 27) {
		host.display();
		ram.display();
		cpu.display();
		os.display();
		time.display();
		n.display();
	}
	endwin();
	return 0;

}