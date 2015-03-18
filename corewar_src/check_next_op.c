/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:13:56 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 11:24:22 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/corewar.h"
#include "../includes/corewarOpTab.h"

void	check_pc(t_header *h)
{
	unsigned int 	instruction;

	instruction = ft_hex_2_dec(h->PC->hex);
	if (instruction > 0 && instruction < 17)
		h->nextOp = instruction - 1;
	else
		h->nextOp = -1;
}

int		check_next_op(t_data *d)
{
	t_header *prog;

	prog = d->prog;
	while (prog != NULL)
	{
		if (prog->wait <= 0)
		{
			prog->PC->present = prog->number;
			check_pc(prog);
			write_l(ft_itoa(prog->nextOp));
			if (prog->nextOp != -1)
			{
				prog->wait = op_tab[prog->nextOp].nb_cycles;
				read_op_code(d, prog);
				write_l("find next op");
				write_l(op_tab[prog->nextOp].name);
			}
			else
				prog->wait = -1;
		}
		prog = prog->next;
	}
	return (0);
}
