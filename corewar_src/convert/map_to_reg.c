/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:27:04 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 15:27:05 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

void	map_to_reg(t_data *d, t_header *player, int reg, int index)
{
	int i;

	i = 0;
	ft_bzero(player->reg[reg], REG_SIZE);
	while (i < REG_SIZE)
	{
		player->reg[reg][i] = ft_hex2intdec(d->map[index].hex);
		index = (index + 1) % MEM_SIZE;
		i++;
	}
}
