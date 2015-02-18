/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkNextOp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:13:56 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/16 16:01:30 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
// #include "../includes/corewarOpTab.h"

void	checkPC(t_header *h)
{
	unsigned int 	instruction;

	instruction = ft_hex2Dec(h->PC->hex);
	if (instruction > 0 && instruction < 17)
		h->nextOp = instruction;
	else
		h->nextOp = -1;
}

int		checkNextOp(t_data *d)
{
	int player;

	player = 0;
	while (player < d->players)
	{
		if (d->prog[player].wait <= 0)
		{
			checkPC(&(d->prog[player]));
			if (d->prog[player].nextOp != -1)
				d->prog[player].wait = op_tab[d->prog[player].nextOp].nb_cycles;
			else
				d->prog[player].wait = -1;
			// check PC for player d->prog[player]
		}
		player++;
	}
	return (0);
}