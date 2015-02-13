/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_LegendInfoValue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:46:21 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/11 11:46:22 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void	renderLegendInfoValue(t_data *d)
{
	wattron(d->window, COLOR_PAIR(10) | A_BOLD);
	// "value Cycle/second limit : 0"	
	mvwprintw(d->window, L_Y_SEC_CLE, L_X_SEC_CLE_VALUE, S_DEFAULT_VALUE);
	// "value of Cycle: 0"
	mvwprintw(d->window, L_Y_CYCLE, L_X_CYCLE_VALUE, S_DEFAULT_VALUE);
	// "value of processes : 0"
	mvwprintw(d->window, L_Y_PROCES, L_X_PROCES_VALUE, S_DEFAULT_VALUE);
	// "CYCLE_TO_DIE : value"
	mvwprintw(d->window, L_Y_DIE, L_X_DIE_VALUE, ft_itoa(d->cycleDie));
	// "CYCLE_DELTA : value"
	mvwprintw(d->window, L_Y_DELTA, L_X_DELTA_VALUE, ft_itoa(CYCLE_DELTA));
	// "NBR_LIVE : value"
	mvwprintw(d->window, L_Y_N_LIVE, L_X_N_LIVE_VALUE, ft_itoa(NBR_LIVE));
	// "MAX_CHECKS : value"
	mvwprintw(d->window, L_Y_N_CHECK, L_X_N_CHECK_VALUE, ft_itoa(MAX_CHECKS));
	wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
}
