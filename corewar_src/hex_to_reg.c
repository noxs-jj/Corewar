/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:01:27 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/16 15:10:37 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

// conv map hex str to reg dec str
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

// OK
// convert reg to int (conv dec str to int)
int		reg_to_int(t_data *d, t_header *player, int reg)
{
	char 			str[(REG_SIZE * 2) + 1];
	char 			tmp[3];
	int 			i;
	int 			j;
	unsigned char 	value;

	(void)d;
	ft_bzero(str, (REG_SIZE * 2) + 1);
	i = 0;
	j = 0;
	while (player->reg[reg][i] == 0)
		i++;
	while (i < REG_SIZE)
	{
		ft_bzero(tmp, 3);
		value = player->reg[reg][i];
		ft_putHexNbr(value, (unsigned char (*)[])&tmp);
		ft_strncpy(&str[j * 2], tmp, 2);		
		i++;
		j++;
	}
	return (ft_hex2intdec((unsigned char *)str));
}

// OK
// copy str in reg (conv hex str to dec str)
void	str_to_reg(t_data *d, t_header *player, int reg, char *str)
{
	int		i;
	char	tmp[3];
	int		index;	// size_t

	(void)d;
	index = 0;
	i = REG_SIZE - str_hex_len((unsigned char *)str);
	if (i < 0)
		i = 0;
	writeL(ft_itoa(i));
	ft_bzero(player->reg[reg], REG_SIZE);
	while (i < REG_SIZE && index < (int)ft_strlen(str))
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
		player->reg[reg][i] = ft_hex2intdec((unsigned char *)tmp);
		i++;
	}
}

void	int_to_reg(t_data *d, t_header *player, int n, int reg)
{
	char	str[(REG_SIZE * 2) + 1];

	ft_bzero(str, (REG_SIZE * 2) + 1);
	nbr2hex((unsigned int)n, (unsigned char (*)[])&str);
	str_to_reg(d, player, reg, str);
}
