/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_legend_info_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:46:21 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/11 11:46:22 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

/*
** "value Cycle/second limit : 0"
** "value of Cycle: 0"
** "value of processes : 0"
** "CYCLE_TO_DIE : value"
** "CYCLE_DELTA : value"
** "NBR_LIVE : value"
** "MAX_CHECKS : value"
*/

void	render_legend_info_value(t_data *d)
{
	wattron(d->window, COLOR_PAIR(10) | A_BOLD);
	mvwprintw(d->window, L_Y_SEC_CLE, L_X_SEC_CLE_VALUE,
		ft_itoa(d->ncurseSpeed));
	mvwprintw(d->window, L_Y_CYCLE, L_X_CYCLE_VALUE, ft_itoa(d->cycle));
	mvwprintw(d->window, L_Y_PROCES, L_X_PROCES_VALUE, ft_itoa(d->players));
	mvwprintw(d->window, L_Y_DIE, L_X_DIE_VALUE, ft_itoa(d->cycleDie));
	mvwprintw(d->window, L_Y_DELTA, L_X_DELTA_VALUE, ft_itoa(CYCLE_DELTA));
	mvwprintw(d->window, L_Y_N_LIVE, L_X_N_LIVE_VALUE, ft_itoa(NBR_LIVE));
	mvwprintw(d->window, L_Y_N_CHECK, L_X_N_CHECK_VALUE, ft_itoa(MAX_CHECKS));
	wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
}
