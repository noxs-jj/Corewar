/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:39:53 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 13:39:54 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	render_keyboard(t_data *d)
{
	int				key_input;

	timeout(1);
	key_input = getch();
	if (key_input == 113 || key_input == 101 || key_input == 27)
		exit_free();
	else if (key_input == 112 || key_input == 32)
		key_pause(d);
	else if (key_input == 43 && d->ncurseSpeed != 250000)
		key_plus(d);
	else if (key_input == 45 && d->ncurseSpeed != 0)
		key_minux(d);
}
