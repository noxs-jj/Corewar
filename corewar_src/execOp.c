/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execOp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:19:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 14:44:56 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		execOp(t_data *d)
{
	// int player;
	t_header *prog;

	// player = d->players - 1;
	prog = lastProg(d);
	while (prog != NULL)
	{
		// exec prog->nextOp for player if prog->wait == 0
		writeL("-----------");
		writeL("execOp");
		writeL(ft_itoa(prog->nextOp));
		writeL("wait");
		writeL(ft_itoa(prog->wait));
		writeL("codage");
		writeL(prog->codage);
		if (prog->wait == 1)
		{
			// exec func
			writeL("playerNbr");
			writeL(ft_itoa(prog->number));
			usleep(10000);
			g_opfunc[prog->nextOp].func(d, prog);
			prog->wait--;
		}
		else if (prog->wait > 0)
			prog->wait--;
		prog = prog->prev;
	}
	// sleep(1);
	d->cycle++;
	return (0);
}
