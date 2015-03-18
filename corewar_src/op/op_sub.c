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

	writeL("--- op_sub ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(get_int_from_dec((char *)player->opArgs[0], T_LAB)) < 0
		|| isValidRegister(get_int_from_dec((char *)player->opArgs[1], T_LAB)) < 0
		|| isValidRegister(get_int_from_dec((char *)player->opArgs[2], T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec((char *)player->opArgs[2], T_LAB);
	ft_bzero(player->opArgs[reg], REG_SIZE);
	value = reg_to_int(d, player, get_int_from_dec((char *)player->opArgs[0], T_LAB));
	// writeL("first value");
	// writeL(ft_itoa(value));
	value -= reg_to_int(d, player, get_int_from_dec((char *)player->opArgs[1], T_LAB));
	// writeL("2nd value");
	// writeL(ft_itoa(reg_to_int(d, player, get_int_from_dec((char *)player->opArgs[1], T_LAB))));
	// writeL("result");
	// writeL(ft_itoa(value));
	int_to_reg(d, player, value, reg);
	// writeL("register");
	// writeL(ft_itoa(player->reg[reg][0]));
	// writeL(ft_itoa(player->reg[reg][1]));
	// writeL(ft_itoa(player->reg[reg][2]));
	// writeL(ft_itoa(player->reg[reg][3]));
	player->carry = true;
	// sleep(5);
	pcAdvance(d, player, ret);
	return (0);
}

/*
int		op_sub(t_data *d, t_header *player)
{
	int ret;
	unsigned int reg;
	int			value;
	char		str[REG_SIZE + 1];
	
	writeL("--- op_add ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec((char *)player->opArgs[0])) < 0
		|| isValidRegister(ft_hex2Dec((char *)player->opArgs[1])) < 0
		|| isValidRegister(ft_hex2Dec((char *)player->opArgs[2])) < 0)
		return (ret);
	value = 0;
	reg = ft_hex2Dec((char *)player->opArgs[2]);
	ft_bzero(player->opArgs[reg], REG_SIZE);
	value = reg_to_int(d, player, ft_hex2Dec((char *)player->opArgs[0]));
	value -= reg_to_int(d, player, ft_hex2Dec((char *)player->opArgs[1]));
	// value = get_arg_int(player->reg[ft_hex2Dec((char *)player->opArgs[0])]);
	// value -= get_arg_int(player->reg[ft_hex2Dec((char *)player->opArgs[1])]);
	ft_bzero(str, REG_SIZE + 1);
	ft_putHexBNbr(value, str); // conversion int to unsigned int
	str_to_reg(d, player, reg, str);
	// ft_strcpy(player->reg[reg], str);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}
*/
