/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:35:10 by vmazurok          #+#    #+#             */
/*   Updated: 2018/07/01 21:23:03 by bpodlesn         ###   ########.fr       */
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
#include "GPU.hpp"
#include "Bluetooth.hpp"
#include "Audio.hpp"
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

TTF_Init();

	Hostname host(rend);
	OS os(rend);
	CPU cpu(rend);
	RAM ram(rend);
	Network n(rend);
	DateTime time(rend);
	GPU gpu(rend);
	Bluetooth bl;
	Audio audio(rend);
	SDL_SetRenderDrawColor(rend, 0xff, 0, 0, 0xFF);
	while (done != false && getch() != 27) {
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, texhud, NULL, NULL);
		host.display();
		ram.display();
		cpu.display();
		os.display();
		time.display();
		n.display();
		bl.display();
		audio.display();
		gpu.display();
		SDL_RenderPresent(rend);
		done = key(event);
	}
	endwin();
	return 0;

}
