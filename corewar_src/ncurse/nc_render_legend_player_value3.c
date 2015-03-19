/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_render_legend_player_value3.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:48:16 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/19 16:08:15 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

/*
** "Player 3 -> champName"
** "Player 3: Last live : value"
** "Player 3: Lives period : value"
*/

void	render_legend_player_value3(t_data *d)
{
	t_header *prog;

	if ((prog = search_prog(d, 3)) == NULL)
		return ;
	wattron(d->window, COLOR_PAIR(3) | A_BOLD);
	mvwprintw(d->window, L_Y_PLAY_3, L_X_PLAY3_VALUE,
				prog->prog_name);
	wattroff(d->window, COLOR_PAIR(3) | A_BOLD);
	wattron(d->window, COLOR_PAIR(10) | A_BOLD);
	mvwprintw(d->window, L_Y_P3_LAST, L_X_P3_LAST_VALUE, "%d",
				prog->last_live);
	mvwprintw(d->window, L_Y_P3_LIVE, L_X_P3_LIVE_VALUE, "%d",
				prog->live_nbr);
	wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
}
