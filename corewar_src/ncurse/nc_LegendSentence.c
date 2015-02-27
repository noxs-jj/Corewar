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

#include "../../includes/corewar.h"
#include "../../includes/render.h"

/* "** RUNNING **" || "** PAUSED **" */
/* "Cycles/second limit :" */
/* "Cycle :" */
/* "Processes :" */
/* "Live breakdown for current period : " + "[---]" */
/* "Live breakdown for last period :" + "[---]" */
/* "CYCLE_TO_DIE :" */
/* "CYCLE_DELTA :" */
/* "NBR_LIVE :" */
/* "MAX_CHECKS :" */
/* PAUSE */
/* EXIT */

void	renderLegendSentence(t_data *d)
{
	mvwprintw(d->window, L_Y_STATUS, L_X_WRITE,
		((d->pause == false) ? S_RUNNING : S_PAUSE));
	mvwprintw(d->window, L_Y_SEC_CLE, L_X_WRITE, S_CYCLE_SECOND);
	mvwprintw(d->window, L_Y_CYCLE, L_X_WRITE, S_CYCLE);
	mvwprintw(d->window, L_Y_PROCES, L_X_WRITE, S_PROCESS);
	mvwprintw(d->window, L_Y_BR_CURR, L_X_WRITE, S_BREAK_CURR);
	mvwprintw(d->window, L_Y_BR_CURR_LINE, L_X_WRITE, S_DEFAULT_BAR);
	mvwprintw(d->window, L_Y_BR_LAST, L_X_WRITE, S_BREAK_LAST);
	mvwprintw(d->window, L_Y_BR_LAST_LINE, L_X_WRITE, S_DEFAULT_BAR);
	mvwprintw(d->window, L_Y_DIE, L_X_WRITE, S_CYCLE_DIE);
	mvwprintw(d->window, L_Y_DELTA, L_X_WRITE, S_CYCLE_DELTA);
	mvwprintw(d->window, L_Y_N_LIVE, L_X_WRITE, S_NBR_LIVE);
	mvwprintw(d->window, L_Y_N_CHECK, L_X_WRITE, S_MAX_CHECKS);
	mvwprintw(d->window, L_Y_PAUSE, L_X_WRITE, S_KEY_PAUSE);
	mvwprintw(d->window, L_Y_EXIT, L_X_WRITE, S_KEY_EXIT);
}
