/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 12:39:48 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/14 13:13:48 by vjacquie         ###   ########.fr       */
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
//"00000kik"
int		arg_to_dec(char (*src)[])
{
	char str[(T_LAB * 2) + 1];
	char tmp[3];
	int i;

	ft_bzero(str, (T_LAB * 2) + 1);
	i = 0;
	while (str[i] == 0)
		i++;
	while (i < T_LAB)
	{
		ft_bzero(tmp, 3);
		ft_putHexNbr(src[i], &tmp); // conv char to unsigned char
		ft_strncpy(&str[i * 2], tmp, 2);
		i++;
	}
	return (ft_hex2intdec(str));
}
