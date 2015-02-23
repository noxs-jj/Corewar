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

#include "../../includes/render.h"
/*
**	COLOR_BLACK   0
**	COLOR_RED     1
**	COLOR_GREEN   2
**	COLOR_YELLOW  3
**	COLOR_BLUE    4
**	COLOR_MAGENTA 5
**	COLOR_CYAN    6
**	COLOR_WHITE   7
*/

void	renderInitPair(void)
{
	/* DEFAULT BACKGROUND BLACK  + WHITE WRITE */
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	/* VALUE BACKGROUND BLACK  + MAGENTA WRITE */
	init_pair(10, COLOR_MAGENTA, COLOR_BLACK);

	/* PLAYER 1 BACKGROUND BLACK + RED WRITE */
	init_pair(1, COLOR_RED, COLOR_BLACK);
	/* PLAYER 11 BACKGROUND BLACK + RED WRITE */
	init_pair(11, COLOR_BLACK, COLOR_RED);
	/* PLAYER 21 BACKGROUND RED + WHITE WRITE */
	init_pair(21, COLOR_WHITE, COLOR_RED);
	/* PLAYER 31 BACKGROUND WHITE WRITE + RED */
	init_pair(31, COLOR_RED, COLOR_WHITE);

	/* PLAYER 2 BACKGROUND BLACK + BLUE WRITE */
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	/* PLAYER 12 BACKGROUND BLACK + BLUE WRITE */
	init_pair(12, COLOR_BLACK, COLOR_BLUE);
	/* PLAYER 22 BACKGROUND BLUE + WHITE WRITE */
	init_pair(22, COLOR_WHITE, COLOR_BLUE);
	/* PLAYER 32 BACKGROUND WHITE + BLUE WRITE */
	init_pair(32, COLOR_BLUE, COLOR_WHITE);

	/* PLAYER 3 BACKGROUND BLACK + YELLOW WRITE */
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	/* PLAYER 43 BACKGROUND BLACK + YELLOW WRITE */
	init_pair(13, COLOR_BLACK, COLOR_YELLOW);
	/* PLAYER 23 BACKGROUND YELLOW + WHITE WRITE */
	init_pair(23, COLOR_WHITE, COLOR_YELLOW);
	/* PLAYER 33 BACKGROUND WHITE + YELLOW WRITE */
	init_pair(33, COLOR_YELLOW, COLOR_WHITE);

	/* PLAYER 4 BACKGROUND BLACK + GREEN WRITE */
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	/* PLAYER 44 BACKGROUND BLACK + GREEN WRITE */
	init_pair(14, COLOR_BLACK, COLOR_GREEN);
	/* PLAYER 24 BACKGROUND GREEN + WHITE WRITE */
	init_pair(24, COLOR_WHITE, COLOR_GREEN);
	/* PLAYER 34 BACKGROUND WHITE + GREEN WRITE */
	init_pair(34, COLOR_GREEN, COLOR_WHITE);
}

int 	renderInit(t_data *d)
{
	initscr();
	start_color();
	renderInitPair();
	d->window = newwin(MAP_HEIGHT , MAP_WIDTH, 0, 0);
	wbkgd(d->window, COLOR_PAIR(0));
	cbreak();
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	wrefresh(d->window);
	return (0);
}
