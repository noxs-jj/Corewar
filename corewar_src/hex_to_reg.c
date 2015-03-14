/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:01:27 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/14 16:07:43 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

// copy map in register
void	map_to_reg(t_data *d, t_header *player, int reg, int index)
{
	int i;

	i = 0;
	// i = REG_SIZE - str_hex_len(str);
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
	unsigned char value;

	ft_bzero(str, (REG_SIZE * 2) + 1);
	i = 0;
	while (player->reg[reg][i] == 0)
		i++;
	while (i < REG_SIZE)
	{
		ft_bzero(tmp, 3);
		value = player->reg[reg][i];
		ft_putHexNbr(value, &tmp);
		writeL("reg_to_int");
		writeL(tmp);
		ft_strncpy(&str[i * 2], tmp, 2);		
		i++;
	}
	writeL("----");
	ft_putnbr_fd(player->reg[reg][0], d->fdDebugg);
	ft_putchar_fd('\n', d->fdDebugg);
	ft_putnbr_fd(player->reg[reg][1], d->fdDebugg);
	ft_putchar_fd('\n', d->fdDebugg);
	ft_putnbr_fd(player->reg[reg][2], d->fdDebugg);
	ft_putchar_fd('\n', d->fdDebugg);
	ft_putnbr_fd(player->reg[reg][3], d->fdDebugg);
	ft_putchar_fd('\n', d->fdDebugg);
	// writeL("reg_to_int");
	// writeL(str);
	return (ft_hex2intdec(str));
}

// copy str in reg
void	str_to_reg(t_data *d, t_header *player, int reg, char *str)
{
	int i;
	char tmp[3];
	int index;	// size_t
	// int len;

	// i = 0;
	index = 0;
	i = REG_SIZE - str_hex_len(str);
	writeL("/==== len ====/");
	writeL(ft_itoa(i));
	ft_bzero(player->reg[reg], REG_SIZE);
	while (i < REG_SIZE && index < ft_strlen(str))// convert 100(hex) to 256(dec) !
	{
		ft_bzero(tmp, 3);
		if (i == 0 && ft_strlen(str) % 2 > 0)
		{
			tmp[0] = '0';
			tmp[1] = str[index * 2];
			index++;
		}
		else
		{
			ft_strncpy(tmp, &str[index], 2);
			index += 2;
		}
		player->reg[reg][i] = ft_hex2intdec(tmp);
		// writeL("str_to_reg");
		// writeL(tmp);
		
		i++;
	}
	// writeL(ft_itoa(player->reg[reg][0]));
	// writeL(ft_itoa(player->reg[reg][1]));
	// writeL(ft_itoa(player->reg[reg][2]));
	// writeL(ft_itoa(player->reg[reg][3]));
}
