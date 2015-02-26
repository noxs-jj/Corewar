/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_renderLegendPlayerValue4.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:48:20 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/26 15:42:47 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	renderLegendPlayerValue4(t_data *d)
{
	t_header *prog;
		/* "Player 4 -> champName" */
	if ((prog = searchProg(d, 4)) == NULL)
		return ;
		wattron(d->window, COLOR_PAIR(4) | A_BOLD);
		mvwprintw(d->window, L_Y_PLAY_4, L_X_PLAY4_VALUE,
					prog->prog_name);
		wattroff(d->window, COLOR_PAIR(4) | A_BOLD);

		/* "Player 4: Last live : value" */
		wattron(d->window, COLOR_PAIR(10) | A_BOLD);
		mvwprintw(d->window, L_Y_P4_LAST, L_X_P4_LAST_VALUE,
					ft_itoa(prog->lastLive));

		/* "Player 4: Lives period : value" */
		mvwprintw(d->window, L_Y_P4_LIVE, L_X_P4_LIVE_VALUE,
					ft_itoa(prog->liveNbr));
		wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
}
