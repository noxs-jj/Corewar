/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_renderLegendPlayerValue1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:47:56 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/26 15:41:45 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

/* "Player 1 -> champName" */
/* "Player 1: Last live : value" */
/* "Player 1: Lives period : value" */

void	renderLegendPlayerValue1(t_data *d)
{
	t_header *prog;
	
	if ((prog = searchProg(d, 1)) == NULL)
		return ;
	wattron(d->window, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(d->window, L_Y_PLAY_1, L_X_PLAY1_VALUE,
				prog->prog_name);
	wattroff(d->window, COLOR_PAIR(1) | A_BOLD);
	wattron(d->window, COLOR_PAIR(10) | A_BOLD);
	mvwprintw(d->window, L_Y_P1_LAST, L_X_P1_LAST_VALUE,
				ft_itoa(prog->lastLive));
	mvwprintw(d->window, L_Y_P1_LIVE, L_X_P1_LIVE_VALUE,
				ft_itoa(prog->liveNbr));
	wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
}
