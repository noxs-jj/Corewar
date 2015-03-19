/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:23:20 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 14:21:03 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	load_champions_2(t_data *d, t_header *prog, int *index, int *i)
{
	d->map[(*index)].champ = prog->number;
	d->map[(*index)].hex[0] = prog->prog[(*i)];
	d->map[(*index)].hex[1] = prog->prog[(*i) + 1];
	if (prog->PC == NULL)
		prog->PC = &d->map[(*index)];
	(*index)++;
	(*i) += 2;
}

int			load_champions(t_data *d)
{
	t_header	*prog;
	int			index;
	int			i;
	int			sum_champions;

	write_l("enter to load_champions");
	index = 0;
	sum_champions = 0;
	prog = d->prog;
	while (prog != NULL)
	{
		i = 0;
		d->map[index].present = true;
		prog->indexPC = index;
		sum_champions += prog->prog_size;
		if (sum_champions > MEM_SIZE)
			return (print_error("Not enough space in Map for all champions"));
		while (i < (int)(prog->prog_size * 2))
			load_champions_2(d, prog, &index, &i);
		index = (MEM_SIZE / d->players) * prog->number;
		prog = prog->next;
	}
	return (0);
}
