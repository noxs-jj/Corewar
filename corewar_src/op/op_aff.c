/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 16:42:04 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_REG
*/

int		op_aff(t_data *d, t_header *player)
{
	int ret;
	char value;
	
	writeL("--- op_aff ---");
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(get_int_from_dec(player->opArgs[0], T_LAB)) < 0)
		return (ret);
	value = reg_to_int(d, player, get_int_from_dec(player->opArgs[0], T_LAB));
	value = value % 256;
	// ##############################
	ft_putchar(value);	// print this on screen
	// ##############################
	pcAdvance(d, player, ret);
	return (0);
}




/*
int		op_aff(t_data *d, t_header *player)
{
	int ret;
	unsigned int reg;
	char value;
	
	writeL("--- op_aff ---");
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0)
		return (ret);
	reg = ft_hex2Dec(player->opArgs[0]);
	value = reg_to_int(d, player, reg);
	// value = ft_hex2Dec(player->reg[reg]);
	value = value % 256;
	ft_putchar(value);
	pcAdvance(d, player, ret);
	return (0);
}
*/