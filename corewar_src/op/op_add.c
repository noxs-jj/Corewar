/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/27 17:47:33 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** need test
** T_REG, T_REG, T_REG
** change carry
*/

int		op_add(t_data *d, t_header *player)
{
	int ret;
	unsigned int reg;
	int			value;
	char		str[REG_SIZE + 1];
	
	writeL("--- op_add ---");
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[2])) < 0)
		return (ret);
	value = 0;
	reg = ft_hex2Dec(player->opArgs[2]);
	ft_bzero(player->opArgs[reg], REG_SIZE);
	value = get_arg_int(player->reg[ft_hex2Dec(player->opArgs[0])]);
	value += get_arg_int(player->reg[ft_hex2Dec(player->opArgs[1])]);
	ft_bzero(str, REG_SIZE + 1);
	ft_putHexBNbr(value, str); // conversion int to unsigned int
	ft_strcpy(player->reg[reg], str);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}