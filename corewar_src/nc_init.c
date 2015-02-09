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

int 	renderInit(t_data *d)
{
	initscr();
	cbreak();
	noecho();
	refresh();
	nodelay(stdscr, true);
	curs_set(0);
	d->window = newwin(MAP_HEIGHT , MAP_WIDTH, 0, 0);
	wrefresh(d->window);
	return (0);
}
