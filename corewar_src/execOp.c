/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execOp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:19:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/25 13:13:40 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		execOp(t_data *d)
{
	int player;

	player = d->players - 1;
	while (player >= 0)
	{
		// exec d->prog[player].nextOp for player if d->prog[player].wait == 0
		writeL("-----------");
		writeL("execOp");
		writeL(ft_itoa(d->prog[player].nextOp));
		writeL("wait");
		writeL(ft_itoa(d->prog[player].wait));
		writeL("codage");
		writeL(d->prog[player].codage);
		if ( d->prog[player].wait == 1)
		{
			// exec func
			writeL("playerNbr");
			writeL(ft_itoa(player));
			usleep(10000);
			g_opfunc[d->prog[player].nextOp].func(d, &d->prog[player], player);
			d->prog[player].wait--;
		}
		else if (d->prog[player].wait > 0)
			d->prog[player].wait--;
		player--;
	}
	// sleep(1);
	d->cycle++;
	return (0);
}