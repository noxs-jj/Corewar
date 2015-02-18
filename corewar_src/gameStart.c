/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameStart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:15:00 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/18 13:33:13 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	gameStart(t_data *d)
{
	d->run = true;
	renderDraw(d);
	while (d->run == true)
	{
		if (d->pause == false)
		{
			// ft_hex2Dec("7de\0");
			// writeL("test");
			// sleep(10);
			// checkNextOp(d); // check next champion's instruction (ptr by PC)
			// execOp(d); // exec next op defined in d->prog[player].nextOp

			// ((d->prog[0].PC) + 1)->hex[0] = '7';//			REMOVE
			// ((d->prog[0].PC) + 1)->hex[1] = '8';//			REMOVE
			d->prog[0].nextOp = 0;
			// op_live(d, &d->prog[0], 0);
			// readOpCode(d, 0);//								REMOVE
			// getOpArgs(d, 0);
			// writeL(d->prog[0].opArgs[0]);
			// writeL(&d->prog[0].opArgs[1][2]);
			// writeL(&d->prog[0].opArgs[2][2]);
			sleep(1);
			renderDraw(d); // draw game
		}
		keyboard(&d);
		if (d->pause == true)
			sleep(1); 						// REMOVE
	}

	return (0);
}