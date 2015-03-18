/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkNextOp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:13:56 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 11:24:22 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/corewar.h"
#include "../includes/corewarOpTab.h"

void	checkPC(t_header *h)
{
	unsigned int 	instruction;

	instruction = ft_hex2Dec(h->PC->hex);
	if (instruction > 0 && instruction < 17)
		h->nextOp = instruction - 1;
	else
		h->nextOp = -1;
}

int		checkNextOp(t_data *d)
{
	t_header *prog;

	prog = d->prog;
	while (prog != NULL)
	{
		if (prog->wait <= 0)
		{
			prog->PC->present = prog->number;
			checkPC(prog);
			writeL(ft_itoa(prog->nextOp));
			if (prog->nextOp != -1)
			{
				prog->wait = op_tab[prog->nextOp].nb_cycles;
				readOpCode(d, prog);
				writeL("find next op");
				writeL(op_tab[prog->nextOp].name);
			}
			else
				prog->wait = -1;
		}
		prog = prog->next;
	}
	return (0);
}
