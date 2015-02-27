/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_draw_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 12:42:44 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/18 16:32:11 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	render_draw1(t_data *d)
{
	werase(d->window);
	wborder(d->window, '|', '|', '-', '-', '+', '+', '+', '+');
	render_legend_column(d);
	render_legend_sentence(d);
	render_legend_player_sentence(d);
	render_legend_player_value(d);
	render_legend_info_value(d);
}

void	render_draw2(t_data *d, int i)
{
	if (d->map[i].champ == 0)
		d->caseColor = COLOR_PAIR(0);
	else if (d->map[i].champ == 1)
		color_champ1(d, i);
	else if (d->map[i].champ == 2)
		color_champ2(d, i);
	else if (d->map[i].champ == 3)
		color_champ3(d, i);
	else if (d->map[i].champ == 4)
		color_champ4(d, i);
}

void	render_draw(t_data *d)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = L_X_MAP_START;
	y = L_Y_MAP_START;
	render_draw1(d);
	while (y < L_Y_MAP_END)
	{
		x = L_X_MAP_START;
		while (x < L_X_MAP_END && i < MEM_SIZE)
		{
			render_draw2(d, i);
			mvwaddch(d->window, y, x, d->map[i].hex[0] | d->caseColor);
			mvwaddch(d->window, y, x + 1, d->map[i].hex[1] | d->caseColor);
			x += 3;
			i++;
		}
		y++;
	}
	refresh();
	wrefresh(d->window);
}
