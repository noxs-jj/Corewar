/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_legendPlayerSentence.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:47:34 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 17:47:35 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void renderLegendPlayerSentence(t_data *d)
{
	// Player 1 + "Last live :" + "Lives in current period :"
	mvwprintw(d->window, L_Y_PLAY_1, L_X_WRITE, S_PLAYER_1);
	mvwprintw(d->window, L_Y_P1_LAST, L_X_WRITE, S_LAST_LIVE);
	mvwprintw(d->window, L_Y_P1_LIVE, L_X_WRITE, S_LIVE_CURR);

	// Player 2 + "Last live :" + "Lives in current period :"
	mvwprintw(d->window, L_Y_PLAY_2, L_X_WRITE, S_PLAYER_2);
	mvwprintw(d->window, L_Y_P2_LAST, L_X_WRITE, S_LAST_LIVE);
	mvwprintw(d->window, L_Y_P2_LIVE, L_X_WRITE, S_LIVE_CURR);

	// Player 3 + "Last live :" + "Lives in current period :"
	mvwprintw(d->window, L_Y_PLAY_3, L_X_WRITE, S_PLAYER_3);
	mvwprintw(d->window, L_Y_P3_LAST, L_X_WRITE, S_LAST_LIVE);
	mvwprintw(d->window, L_Y_P3_LIVE, L_X_WRITE, S_LIVE_CURR);

	// Player 4 + "Last live :" + "Lives in current period :"
	mvwprintw(d->window, L_Y_PLAY_4, L_X_WRITE, S_PLAYER_4);
	mvwprintw(d->window, L_Y_P4_LAST, L_X_WRITE, S_LAST_LIVE);
	mvwprintw(d->window, L_Y_P4_LIVE, L_X_WRITE, S_LIVE_CURR);
}
