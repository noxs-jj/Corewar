/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/16 15:13:56 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** OK
** T_REG, T_REG, T_REG
** change carry
*/

int		op_sub(t_data *d, t_header *player)
{
	int		ret;
	int		reg;
	int		value;

	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(get_int_from_dec((char *)player->opArgs[0], T_LAB)) < 0
		|| isValidRegister(get_int_from_dec((char *)player->opArgs[1], T_LAB)) < 0
		|| isValidRegister(get_int_from_dec((char *)player->opArgs[2], T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec((char *)player->opArgs[2], T_LAB);
	ft_bzero(player->opArgs[reg], REG_SIZE);
	value = reg_to_int(d, player, get_int_from_dec((char *)player->opArgs[0], T_LAB));
	value -= reg_to_int(d, player, get_int_from_dec((char *)player->opArgs[1], T_LAB));
	int_to_reg(d, player, value, reg);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}
