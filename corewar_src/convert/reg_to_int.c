/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:27:15 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 15:27:16 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

int		reg_to_int(t_data *d, t_header *player, int reg)
{
	char			str[REG_SIZE_2];
	char			tmp[3];
	int				i;
	int				j;
	unsigned char	value;

	(void)d;
	ft_bzero(str, REG_SIZE_2);
	i = 0;
	j = 0;
	while (player->reg[reg][i] == 0)
		i++;
	while (i < REG_SIZE)
	{
		ft_bzero(tmp, 3);
		value = player->reg[reg][i];
		ft_put_hex_nbr(value, (unsigned char (*)[])&tmp);
		ft_strncpy(&str[j * 2], tmp, 2);
		i++;
		j++;
	}
	return (ft_hex2intdec((unsigned char *)str));
}
