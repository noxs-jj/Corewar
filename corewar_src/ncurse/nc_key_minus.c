/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_key_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:42:42 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/17 12:42:42 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	key_minux(t_data *d)
{
	if ((int)d->ncurse_speed - 5000 >= 0)
	{
		write_l("KEYBOARD\t\t-");
		d->ncurse_speed -= 5000;
		wattron(d->window, COLOR_PAIR(10) | A_BOLD);
		mvwprintw(d->window, L_Y_SEC_CLE, L_X_SEC_CLE_VALUE, "      ");
		mvwprintw(d->window, L_Y_SEC_CLE, L_X_SEC_CLE_VALUE,
			ft_itoa(d->ncurse_speed));
		wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
		refresh();
		wrefresh(d->window);
	}
}
