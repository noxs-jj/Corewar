/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/16 15:11:02 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

/*
** OK
** T_REG, T_REG, T_REG
** change carry
*/

int		op_add(t_data *d, t_header *player)
{
	int		ret;
	int		reg;
	int		value;

	player->carry = false;
	if ((ret = get_op_args(d, player)) < 0
		|| is_valid_register(get_int_from_dec(
			(char *)player->op_args[0], T_LAB)) < 0
		|| is_valid_register(get_int_from_dec(
			(char *)player->op_args[1], T_LAB)) < 0
		|| is_valid_register(get_int_from_dec(
			(char *)player->op_args[2], T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec((char *)player->op_args[2], T_LAB);
	ft_bzero((char *)player->op_args[reg], REG_SIZE);
	value = reg_to_int(d, player, get_int_from_dec(
		(char *)player->op_args[0], T_LAB));
	value += reg_to_int(d, player, get_int_from_dec(
		(char *)player->op_args[1], T_LAB));
	int_to_reg(d, player, value, reg);
	player->carry = true;
	pc_advance(d, player, ret);
	return (0);
}
