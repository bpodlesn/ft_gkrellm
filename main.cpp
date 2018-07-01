/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:47:11 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/07/01 16:38:59 by bpodlesn         ###   ########.fr       */
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

bool	key(SDL_Event event){
	const Uint8	*keykey;

	keykey = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		return (false);
	if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		return (false);
	return true;
}

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

	//SDL


	Uint32		render_flags;
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Event		event;
	SDL_Surface		*hud;
	// SDL_Rect		shud;
	// SDL_Rect		dhud;
	SDL_Texture		*texhud;
	bool done = true;

	win = SDL_CreateWindow("Hello, MY SEMPAI!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800, 600, 0);
	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	rend = SDL_CreateRenderer(win, -1, render_flags);
	hud = IMG_Load("img/hud.png");
	texhud = SDL_CreateTextureFromSurface(rend, hud);
	//text
	// int w = 0, h = 0;

TTF_Init();
	// if (font == NULL)
	// 	return (0);
	// // if (TTF_Init() == 0)
	// // 	done = false;
	// // 	exit(0);
	// 
	
// SDL_Rect renderQuad = { 20, 30, 0, 0 };
	// SDL

	Hostname host(rend);
	OS os(rend);
	CPU cpu(rend);
	RAM ram;
	DateTime time(rend);
	SDL_SetRenderDrawColor(rend, 0xff, 0, 0, 0xFF);
	while (done != false && getch() != 27) {
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, texhud, NULL, NULL);
		host.display();
		ram.display();
		cpu.display();
		os.display();
		time.display();
		// 
		SDL_RenderPresent(rend);
		done = key(event);
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