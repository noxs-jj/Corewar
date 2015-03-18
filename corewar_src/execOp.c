/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execOp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:19:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 12:15:16 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		execOp(t_data *d)
{
	t_header *prog;

	prog = lastProg(d);
	while (prog != NULL)
	{
		if (prog->wait == 1)
		{
			g_opfunc[prog->nextOp].func(d, prog);
			prog->wait--;
		}
		else if (prog->wait > 0)
			prog->wait--;
		prog = prog->prev;
	}
	d->cycle++;
	return (0);
}
