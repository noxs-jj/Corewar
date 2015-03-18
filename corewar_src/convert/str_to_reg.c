/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:27:23 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 15:27:24 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

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
	write_l(ft_itoa(i));
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
