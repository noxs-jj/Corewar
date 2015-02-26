/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 14:38:13 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_REG, T_REG, T_REG
*/

int		op_sub(t_data *d, t_header *player)
{
	int ret;
	unsigned int reg;
	unsigned int value;
	char		str[9];
	
	writeL("--- op_sub ---");
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[2])) < 0)
		return (ret);
	value = 0;
	reg = ft_hex2Dec(player->opArgs[2]);
	ft_bzero(player->reg[reg], REG_SIZE);
	value = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[0])]);
	value -= ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[1])]);
	ft_bzero(str, 9);
	ft_putHexBNbr(value, str);
	ft_strcpy(player->reg[reg], str);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}