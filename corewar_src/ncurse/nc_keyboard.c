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

void	keyboard(void)
{
	static t_data	*d = NULL;
	int				key_input;

	if (d == NULL)
		d = getData();
	timeout(1);
	key_input = getch();
	if (key_input == 113 || key_input == 101 || key_input == 27)
		exitFree();
	else if (key_input == 112 || key_input == 32)
	{
		if (d->pause == true)
		{
			d->pause = false;
			writeL("keyboard\tRUNNING");
		}
		else
		{
			d->pause = true;
			writeL("keyboard\tPAUSE");
			render_draw(d);
		}
	}
	else if (key_input == 43 && d->ncurseSpeed != 250000) // + == 43
	{
		if (d->ncurseSpeed + 5000 < 250000)
			d->ncurseSpeed += 5000;
	}
	else if (key_input == 45 && d->ncurseSpeed != 0) // - == 45
	{
		if (d->ncurseSpeed - 5000 >= 0)
			d->ncurseSpeed -= 5000;
	}
	// else
	// {
	// 	writeL("Key _ Input");
	// 	writeL(ft_itoa(key_input));
	// 	sleep(2);
	// }
}
