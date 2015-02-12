/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_draw_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 12:42:44 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 12:42:45 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void	renderDraw(t_data *d)
{
	int	i = 0;
	int	x = L_X_MAP_START;
	int y = L_Y_MAP_START;

	werase(d->window);
	wborder(d->window, '|', '|', '-', '-', '+', '+', '+', '+');
	
	renderLegendColumn(d);
	renderLegendSentence(d);
	renderLegendPlayerSentence(d);
	renderLegendPlayerValue(d);
	renderLegendInfoValue(d);
	

	while (y < L_Y_MAP_END)
	{
		x = L_X_MAP_START;
		while (x < L_X_MAP_END && i < MEM_SIZE)
		{
			mvwaddch(d->window, y, x, 'E' | COLOR_PAIR(2));
			mvwaddch(d->window, y, x + 1, '3' | COLOR_PAIR(1));
			x += 3;
			i++;
		}
		y++;
	}

	refresh();
	wrefresh(d->window);
}
