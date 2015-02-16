/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_renderLegendPlayerValue3.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:48:16 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/13 11:48:17 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	renderLegendPlayerValue3(t_data *d)
{
		/* "Player 3 -> champName" */
		wattron(d->window, COLOR_PAIR(3) | A_BOLD);
		mvwprintw(d->window, L_Y_PLAY_3, L_X_PLAY3_VALUE, d->prog[2].prog_name);
		wattroff(d->window, COLOR_PAIR(3) | A_BOLD);
		/* "Player 3: Last live : value" */
		wattron(d->window, COLOR_PAIR(10) | A_BOLD);
		mvwprintw(d->window, L_Y_P3_LAST, L_X_P3_LAST_VALUE, S_DEFAULT_VALUE);
		/* "Player 3: Lives period : value" */
		mvwprintw(d->window, L_Y_P3_LIVE, L_X_P3_LIVE_VALUE, S_DEFAULT_VALUE);
		wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
}
