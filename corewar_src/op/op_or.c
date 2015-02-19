/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/19 12:44:55 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** not tested
** arg 1 & 2 type : T_REG | T_DIR | T_IND
*/

int		op_or(t_data *d, t_header *player, int id)
{
	int ret;
	unsigned int reg;
	unsigned int value[2];
	
	if ((ret = getOpArgs(&d->prog[id], id)) < 0
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
	ft_bzero(player->opArgs[reg], REG_SIZE);
	ft_strcpy(player->opArgs[reg], ft_itoa(value[0] | value[1]));
	if (value[0] | value[1])
		player->carry = true;
	else
		player->carry = false;
	pcAdvance(d, &d->prog[id], ret);
	return (0);
}