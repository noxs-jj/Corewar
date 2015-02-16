/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_renderLegendPlayerValue2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:48:02 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/16 16:15:05 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	renderLegendPlayerValue2(t_data *d)
{
		/* "Player 2 -> champName" */
		wattron(d->window, COLOR_PAIR(2) | A_BOLD);
		mvwprintw(d->window, L_Y_PLAY_2, L_X_PLAY2_VALUE,
					d->prog[1].prog_name);
		wattroff(d->window, COLOR_PAIR(2) | A_BOLD);

		/* "Player 2: Last live : value" */
		wattron(d->window, COLOR_PAIR(10) | A_BOLD);
		mvwprintw(d->window, L_Y_P2_LAST, L_X_P2_LAST_VALUE,
					ft_itoa(d->prog[1].lastLive));

		/* "Player 2: Lives period : value" */
		mvwprintw(d->window, L_Y_P2_LIVE, L_X_P2_LIVE_VALUE,
					ft_itoa(d->prog[1].liveNbr));
		wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
}
