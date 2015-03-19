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
** DEFAULT BACKGROUND BLACK  + WHITE WRITE
** VALUE BACKGROUND BLACK  + MAGENTA WRITE
** PLAYER 1 BACKGROUND BLACK + RED WRITE
** PLAYER 11 BACKGROUND BLACK + RED WRITE
** PLAYER 21 BACKGROUND RED + WHITE WRITE
** PLAYER 31 BACKGROUND WHITE WRITE + RED
** PLAYER 2 BACKGROUND BLACK + BLUE WRITE
** PLAYER 12 BACKGROUND BLACK + BLUE WRITE
** PLAYER 22 BACKGROUND BLUE + WHITE WRITE
** PLAYER 32 BACKGROUND WHITE + BLUE WRITE
** PLAYER 3 BACKGROUND BLACK + YELLOW WRITE
** PLAYER 43 BACKGROUND BLACK + YELLOW WRITE
** PLAYER 23 BACKGROUND YELLOW + WHITE WRITE
** PLAYER 33 BACKGROUND WHITE + YELLOW WRITE
** PLAYER 4 BACKGROUND BLACK + GREEN WRITE
** PLAYER 44 BACKGROUND BLACK + GREEN WRITE
** PLAYER 24 BACKGROUND GREEN + WHITE WRITE
** PLAYER 34 BACKGROUND WHITE + GREEN WRITE
*/

void	render_init_pair(void)
{
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, COLOR_RED);
	init_pair(21, COLOR_WHITE, COLOR_RED);
	init_pair(31, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(12, COLOR_BLACK, COLOR_BLUE);
	init_pair(22, COLOR_WHITE, COLOR_BLUE);
	init_pair(32, COLOR_BLUE, COLOR_WHITE);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(13, COLOR_BLACK, COLOR_YELLOW);
	init_pair(23, COLOR_WHITE, COLOR_YELLOW);
	init_pair(33, COLOR_YELLOW, COLOR_WHITE);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(14, COLOR_BLACK, COLOR_GREEN);
	init_pair(24, COLOR_WHITE, COLOR_GREEN);
	init_pair(34, COLOR_GREEN, COLOR_WHITE);
}

int		render_init(t_data *d)
{
	write_l("enter to render_init");
	initscr();
	start_color();
	render_init_pair();
	d->window = newwin(MAP_HEIGHT, MAP_WIDTH, 0, 0);
	wbkgd(d->window, COLOR_PAIR(0));
	cbreak();
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	wrefresh(d->window);
	d->ncurse_speed = TIME_USLEEP;
	return (0);
}
