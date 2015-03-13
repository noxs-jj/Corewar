/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:01:27 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/12 17:40:53 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

// copy map in register
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

// convert reg to int
int		reg_to_int(t_data *d, t_header *player, int reg)
{
	char str[(REG_SIZE * 2) + 1];
	char tmp[3];
	int i;

	ft_bzero(str, (REG_SIZE * 2) + 1);
	i = 0;
	while (i < REG_SIZE)
	{
		ft_bzero(tmp, 3);
		ft_putHexNbr(player->reg[reg], &tmp);
		ft_strncpy(&str[i * 2], tmp, 2);
		i++;
	}
	return (ft_hex2intdec(str));
}

// copy str in reg
void	str_to_reg(t_data *d, t_header *player, int reg, char *str)
{
	int i;

	i = 0;
	ft_bzero(player->reg[reg], REG_SIZE);
	while (i < REG_SIZE)
	{
		player->reg[reg][i] = ft_hex2intdec(&str[i]);
		i++;
	}
}