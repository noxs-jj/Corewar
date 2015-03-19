/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_key_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:42:47 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/19 16:10:29 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	key_plus(t_data *d)
{
	if (d->ncurse_speed + 5000 < 250000)
	{
		write_l("KEYBOARD\t\t+");
		d->ncurse_speed += 5000;
		wattron(d->window, COLOR_PAIR(10) | A_BOLD);
		mvwprintw(d->window, L_Y_SEC_CLE, L_X_SEC_CLE_VALUE, "      ");
		mvwprintw(d->window, L_Y_SEC_CLE, L_X_SEC_CLE_VALUE, "%d",
			d->ncurse_speed);
		wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
		refresh();
		wrefresh(d->window);
	}
}
