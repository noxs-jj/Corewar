/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_renderLegendPlayerValue1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:47:56 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/13 11:47:56 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void	renderLegendPlayerValue1(t_data *d)
{
		// "Player 1 -> champName"
		wattron(d->window, COLOR_PAIR(1) | A_BOLD);
		mvwprintw(d->window, L_Y_PLAY_1, L_X_PLAY1_VALUE, S_DEFAULT_VALUE);
		wattroff(d->window, COLOR_PAIR(1) | A_BOLD);
		// "Player 1: Last live : value"
		mvwprintw(d->window, L_Y_P1_LAST, L_X_P1_LAST_VALUE, S_DEFAULT_VALUE);
		// "Player 1: Lives period : value"
		mvwprintw(d->window, L_Y_P1_LIVE, L_X_P1_LIVE_VALUE, S_DEFAULT_VALUE);
}
