/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameStart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:15:00 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/16 15:59:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	gameStart(t_data *d)
{
	d->run = true;
	while (d->run == true)
	{
		if (d->pause == false)
		{
			// checkNextOp(d); // check next champion's instruction (ptr by PC)
			// execOp(d); // exec next op defined in d->prog[player].nextOp

			((d->prog[0].PC) + 1)->hex[0] = '7';
			((d->prog[0].PC) + 1)->hex[1] = '8';
			readOpCode(d, 0);
			sleep(10);
			renderDraw(d); // draw game
		}
		keyboard(&d);
		if (d->pause == true)
			sleep(2); 						// REMOVE
	}

	return (0);
}