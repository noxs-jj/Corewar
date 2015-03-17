/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_key_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:42:47 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/17 12:42:48 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	key_plus(t_data *d)
{
	if (d->ncurseSpeed + 5000 < 250000)
	{
		d->ncurseSpeed += 5000;
		wattron(d->window, COLOR_PAIR(10) | A_BOLD);
		mvwprintw(d->window, L_Y_SEC_CLE, L_X_SEC_CLE_VALUE, "      ");
		mvwprintw(d->window, L_Y_SEC_CLE, L_X_SEC_CLE_VALUE, ft_itoa(d->ncurseSpeed));
		wattroff(d->window, COLOR_PAIR(10) | A_BOLD);
		refresh();
		wrefresh(d->window);
	}
}
