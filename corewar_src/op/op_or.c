/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 14:36:23 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** not tested
** T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG
** change carry
*/

int		op_or(t_data *d, t_header *player)
{
	int ret;
	unsigned int reg;
	unsigned int value[2];
	char		str[9];
	
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[2])) < 0)
		return (ret);
	reg = ft_hex2Dec(player->opArgs[2]);
	if (ft_strncmp(player->codage, "01", 2) == 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0)
		value[0] = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[0])]);
	else
		value[0] = ft_hex2Dec(player->opArgs[0]);
	if (ft_strncmp(&player->codage[2], "01", 2) == 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0)
		value[1] = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[1])]);
	else
		value[1] = ft_hex2Dec(player->opArgs[1]);
	ft_bzero(player->reg[reg], REG_SIZE);
	ft_bzero(str, 9);
	ft_putHexBNbr(value[0] | value[1], str);
	ft_strcpy(player->reg[reg], str);
	if (value[0] | value[1])
		player->carry = true;
	else
		player->carry = false;
	pcAdvance(d, player, ret);
	return (0);
}