/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 12:42:28 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 12:42:29 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"
	//		 COLOR_BLACK   0
	//       COLOR_RED     1
	//       COLOR_GREEN   2
	//       COLOR_YELLOW  3
	//       COLOR_BLUE    4
	//       COLOR_MAGENTA 5
	//       COLOR_CYAN    6
	//       COLOR_WHITE   7

void	renderInitPair(void)
{
	// DEFAULT BACKGROUND BLACK  + WHITE WRITE
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	// VALUE BACKGROUND BLACK  + MAGENTA WRITE
	init_pair(10, COLOR_MAGENTA, COLOR_BLACK);

	// VALUE

	// PLAYER 1 BACKGROUND BLACK + RED WRITE
	init_pair(1, COLOR_RED, COLOR_BLACK);
	// PLAYER 1 BACKGROUND BLACK + RED WRITE
	init_pair(11, COLOR_BLACK, COLOR_RED);

	// PLAYER 2 BACKGROUND BLACK + BLUE WRITE
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	// PLAYER 2 BACKGROUND BLACK + BLUE WRITE
	init_pair(12, COLOR_BLACK, COLOR_BLUE);

	// PLAYER 3 BACKGROUND BLACK + YELLOW WRITE
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	// PLAYER 3 BACKGROUND BLACK + YELLOW WRITE
	init_pair(13, COLOR_BLACK, COLOR_YELLOW);

	// PLAYER 4 BACKGROUND BLACK + GREEN WRITE
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	// PLAYER 4 BACKGROUND BLACK + GREEN WRITE
	init_pair(14, COLOR_BLACK, COLOR_GREEN);
}

int 	renderInit(t_data *d)
{
	initscr();
	start_color();
	renderInitPair();
	wbkgd(d->window, COLOR_PAIR(0));
	cbreak();
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	d->window = newwin(MAP_HEIGHT , MAP_WIDTH, 0, 0);
	wrefresh(d->window);
	return (0);
}
