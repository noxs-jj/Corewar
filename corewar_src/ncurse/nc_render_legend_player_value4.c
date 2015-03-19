/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_render_legend_player_value4.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:48:20 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/26 15:42:47 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

/*
** "Player 4 -> champName"
** "Player 4: Last live : value"
** "Player 4: Lives period : value"
*/

void	render_legend_player_value4(t_data *d)
{
	t_header *prog;

	if ((prog = search_prog(d, 4)) == NULL)
		return ;
	wattron(d->window, COLOR_PAIR(4) | A_BOLD);
	mvwprintw(d->window, L_Y_PLAY_4, L_X_PLAY4_VALUE,
				prog->prog_name);
	wattroff(d->window, COLOR_PAIR(4) | A_BOLD);
	wattron(d->window, COLOR_PAIR(10) | A_BOLD);
	mvwprintw(d->window, L_Y_P4_LAST, L_X_P4_LAST_VALUE,
				ft_itoa(prog->last_live));
	mvwprintw(d->window, L_Y_P4_LIVE, L_X_P4_LIVE_VALUE,
				ft_itoa(prog->live_nbr));
	wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
}
