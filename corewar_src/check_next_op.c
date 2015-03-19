/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:13:56 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 11:24:22 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_op_tab.h"

void	check_pc(t_header *h)
{
	unsigned int	instruction;

	instruction = ft_hex_2_dec(h->pc->hex);
	if (instruction > 0 && instruction < 17)
		h->next_op = instruction - 1;
	else
		h->next_op = -1;
}

int		check_next_op(t_data *d)
{
	t_header *prog;

	prog = d->prog;
	while (prog != NULL)
	{
		if (prog->wait <= 0)
		{
			prog->pc->present = prog->number;
			check_pc(prog);
			if (prog->next_op != -1)
			{
				prog->wait = g_op_tab[prog->next_op].nb_cycles;
				read_op_code(d, prog);
			}
			else
				prog->wait = -1;
		}
		prog = prog->next;
	}
	return (0);
}
