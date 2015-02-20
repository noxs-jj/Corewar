/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/20 14:57:06 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** not tested
** T_REG, T_REG, T_REG
*/

int		op_sub(t_data *d, t_header *player, int id)
{
	int ret;
	unsigned int reg;
	unsigned int value;
	char		str[9];
	
	if ((ret = getOpArgs(d, id)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[2])) < 0)
		return (ret);
	value = 0;
	reg = ft_hex2Dec(player->opArgs[2]);
	ft_bzero(player->opArgs[reg], REG_SIZE);
	value = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[0])]);
	value -= ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[1])]);
	ft_bzero(str, 9);
	ft_putHexBNbr(value, str);
	ft_strcpy(player->opArgs[reg], str);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}