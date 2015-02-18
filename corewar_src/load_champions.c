/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:23:20 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/18 13:31:04 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		load_champions(t_data *d)
{
	int player;
	int start;
	int	index;
	int i;

	player = 0;
	start = 0;
	index = 0;
	while (player < d->players)
	{
		i = 0;
		while (i < d->prog[player].prog_size * 2)
		{
			d->map[index].champ = player + 1;
			d->map[index].hex[0] = d->prog[player].prog[i];
			d->map[index].hex[1] = d->prog[player].prog[i + 1];
			if (d->prog[player].PC == NULL)
				d->prog[player].PC = &d->map[index];
			index++;
			i += 2;
		}
		player++;
		index = (MEM_SIZE / d->players) * player;
	}
	return (0);
}