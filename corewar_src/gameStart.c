/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameStart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:15:00 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/20 12:10:16 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
** run the game
** call renderDraw at each execOp ?
*/

int	gameStart(t_data *d)
{
	d->run = true;
	// renderDraw(d);
	if (d->graphActiv == true)
		renderDraw(d);
	else
		co_showInitPlayers(d);
	writeL(ft_itoa("DUMP following"));
	writeL(ft_itoa(d->dump));
	while (d->run == true)
	{
		if (d->pause == false)
		{
			// ft_hex2Dec("7de\0");
			// writeL("test");
			// sleep(10);
			checkNextOp(d); // check next champion's instruction (ptr by PC)
			execOp(d); // exec next op defined in d->prog[player].nextOp
			// ((d->prog[0].PC) + 1)->hex[0] = '7';//			REMOVE
			// ((d->prog[0].PC) + 1)->hex[1] = '8';//			REMOVE
			// d->prog[0].nextOp = 0;
			// op_live(d, &d->prog[0], 0);
			// readOpCode(d, 0);//								REMOVE
			// getOpArgs(d, 0);
			// writeL(d->prog[0].opArgs[0]);
			// writeL(&d->prog[0].opArgs[1][2]);
			// writeL(&d->prog[0].opArgs[2][2]);
			//sleep(1);
			checkCyles(d);
			if (true == d->graphActiv)
				renderDraw(d); // draw game with ncurses
			else
				renderShell(d); // draw game on shell
			if (d->dump != -1 && d->cycle == d->dump)
			{
				if (true == d->graphActiv)
					renderClose(d);
				d->run = false;
				arg_dump(d);
			}
			// sleep(1);
		}
		keyboard(&d);
		if (d->pause == true)
			sleep(1); 						// REMOVE
		// if (d->cycle % 10 == 0)
		//  	sleep(2);
	}

	if (d->graphActiv == false)
		drawResultConsole(d);
	return (0);
}