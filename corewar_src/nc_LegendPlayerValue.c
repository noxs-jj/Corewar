/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_LegendPlayerValue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:46:34 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/11 11:46:35 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void	renderLegendPlayerValue(t_data *d)
{
	if (d->players > 0)
	{
		// "Player 1 -> champName"
		wattron(d->window, COLOR_PAIR(1));
		mvwprintw(d->window, L_Y_PLAY_1, L_X_PLAY1_VALUE, S_DEFAULT_VALUE);
		wattroff(d->window, COLOR_PAIR(1));
		// "Player 1: Last live : value"
		mvwprintw(d->window, L_Y_P1_LAST, L_X_P1_LAST_VALUE, S_DEFAULT_VALUE);
		// "Player 1: Lives period : value"
		mvwprintw(d->window, L_Y_P1_LIVE, L_X_P1_LIVE_VALUE, S_DEFAULT_VALUE);
	}
	if (d->players > 1)
	{
		// "Player 2 -> champName"
		wattron(d->window, COLOR_PAIR(2));
		mvwprintw(d->window, L_Y_PLAY_2, L_X_PLAY2_VALUE, S_DEFAULT_VALUE);
		wattroff(d->window, COLOR_PAIR(2));
		// "Player 2: Last live : value"
		mvwprintw(d->window, L_Y_P2_LAST, L_X_P2_LAST_VALUE, S_DEFAULT_VALUE);
		// "Player 2: Lives period : value"
		mvwprintw(d->window, L_Y_P2_LIVE, L_X_P2_LIVE_VALUE, S_DEFAULT_VALUE);
	}
	if (d->players > 2)
	{
		// "Player 3 -> champName"
		wattron(d->window, COLOR_PAIR(3));
		mvwprintw(d->window, L_Y_PLAY_3, L_X_PLAY3_VALUE, S_DEFAULT_VALUE);
		wattroff(d->window, COLOR_PAIR(3));
		// "Player 3: Last live : value"
		mvwprintw(d->window, L_Y_P3_LAST, L_X_P3_LAST_VALUE, S_DEFAULT_VALUE);
		// "Player 3: Lives period : value"
		mvwprintw(d->window, L_Y_P3_LIVE, L_X_P3_LIVE_VALUE, S_DEFAULT_VALUE);
	}
	if (d->players > 3)
	{
		// "Player 4 -> champName"
		wattron(d->window, COLOR_PAIR(4));
		mvwprintw(d->window, L_Y_PLAY_4, L_X_PLAY4_VALUE, S_DEFAULT_VALUE);
		wattroff(d->window, COLOR_PAIR(4));
		// "Player 4: Last live : value"
		mvwprintw(d->window, L_Y_P4_LAST, L_X_P4_LAST_VALUE, S_DEFAULT_VALUE);
		// "Player 4: Lives period : value"
		mvwprintw(d->window, L_Y_P4_LIVE, L_X_P4_LIVE_VALUE, S_DEFAULT_VALUE);
	}	
}
