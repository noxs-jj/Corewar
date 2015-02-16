/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_renderLegendPlayerValue4.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:48:20 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/16 16:15:06 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	renderLegendPlayerValue4(t_data *d)
{
		/* "Player 4 -> champName" */
		wattron(d->window, COLOR_PAIR(4) | A_BOLD);
		mvwprintw(d->window, L_Y_PLAY_4, L_X_PLAY4_VALUE,
					d->prog[3].prog_name);
		wattroff(d->window, COLOR_PAIR(4) | A_BOLD);

		/* "Player 4: Last live : value" */
		wattron(d->window, COLOR_PAIR(10) | A_BOLD);
		mvwprintw(d->window, L_Y_P4_LAST, L_X_P4_LAST_VALUE,
					ft_itoa(d->prog[3].lastLive));

		/* "Player 4: Lives period : value" */
		mvwprintw(d->window, L_Y_P4_LIVE, L_X_P4_LIVE_VALUE,
					ft_itoa(d->prog[3].liveNbr));
		wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
}
