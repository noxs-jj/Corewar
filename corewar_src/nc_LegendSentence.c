/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_LegendSentence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:47:48 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 17:47:49 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void	renderLegendSentence(t_data *d)
{
	// "** RUNNING **" || "** PAUSED **"
	mvwprintw(d->window, L_Y_STATUS, L_X_WRITE, S_RUNNING);
	// "Cycles/second limit :"
	mvwprintw(d->window, L_Y_SEC_CLE, L_X_WRITE, S_CYCLE_SECOND);
	// "Cycle :"
	mvwprintw(d->window, L_Y_CYCLE, L_X_WRITE, S_CYCLE);
	// "Processes :"
	mvwprintw(d->window, L_Y_PROCES, L_X_WRITE, S_PROCESS);
	// "Live breakdown for current period : " + "[---]"
	mvwprintw(d->window, L_Y_BR_CURR, L_X_WRITE, S_BREAK_CURR);
	mvwprintw(d->window, L_Y_BR_CURR_LINE, L_X_WRITE, S_DEFAULT_BAR);

	// "Live breakdown for last period :" + "[---]"
	mvwprintw(d->window, L_Y_BR_LAST, L_X_WRITE, S_BREAK_LAST);
	mvwprintw(d->window, L_Y_BR_LAST_LINE, L_X_WRITE, S_DEFAULT_BAR);

	// "CYCLE_TO_DIE :"
	mvwprintw(d->window, L_Y_DIE, L_X_WRITE, S_CYCLE_DIE);
	// "CYCLE_DELTA :"
	mvwprintw(d->window, L_Y_DELTA, L_X_WRITE, S_CYCLE_DELTA);
	// "NBR_LIVE :"
	mvwprintw(d->window, L_Y_N_LIVE, L_X_WRITE, S_NBR_LIVE);
	// "MAX_CHECKS :"
	mvwprintw(d->window, L_Y_N_CHECK, L_X_WRITE, S_MAX_CHECKS);
}
