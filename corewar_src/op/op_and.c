/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 19:42:14 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

/*
** OK
** T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG
** change carry
*/

static int	op_and_3(t_data *d, t_header *player, unsigned int (*value)[])
{
	if (is_register(player, 0) >= 0)
		(*value)[0] = reg_to_int(d, player,
			get_int_from_dec((char *)player->op_args[0], T_LAB));
	else if (is_direct(player, 0) >= 0)
	{
		(*value)[0] = get_int_from_dec((char *)player->op_args[0], T_LAB);
		if (player->op_args[0][T_LAB - 2] >= 240)
			(*value)[0] = (*value)[0] - 65536;
	}
	else if (is_indirect(player, 0) >= 0)
	{
		(*value)[0] = get_int_from_dec((char *)player->op_args[0], T_LAB);
		if (player->op_args[0][T_LAB - 2] >= 240)
			(*value)[0] = (*value)[0] - 65536;
		(*value)[0] = get_arg_modulo((*value)[0], IDX_MOD);
	}
	else
		return (-1);
	return (0);
}

static int	op_and_2(t_data *d, t_header *player, unsigned int (*value)[])
{
	if (is_register(player, 1) >= 0)
		(*value)[1] = reg_to_int(d, player,
			get_int_from_dec((char *)player->op_args[1], T_LAB));
	else if (is_direct(player, 1) >= 0)
	{
		(*value)[1] = get_int_from_dec((char *)player->op_args[1], T_LAB);
		if (player->op_args[1][T_LAB - 2] >= 240)
			(*value)[1] = (*value)[1] - 65536;
	}
	else if (is_indirect(player, 1) >= 0)
	{
		(*value)[1] = get_int_from_dec((char *)player->op_args[1], T_LAB);
		if (player->op_args[1][T_LAB - 2] >= 240)
			(*value)[1] = (*value)[1] - 65536;
		(*value)[1] = get_arg_modulo((*value)[1], IDX_MOD);
	}
	else
		return (-1);
	return (0);
}

int			op_and(t_data *d, t_header *player)
{
	int				ret;
	unsigned int	reg;
	unsigned int	value[2];
	char			str[REG_SIZE + 1];

	player->carry = false;
	if ((ret = get_op_args(d, player)) < 0
		|| is_valid_register(get_int_from_dec((char *)player->op_args[2],
			T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec((char *)player->op_args[2], T_LAB);
	if (op_and_3(d, player, &value) < 0)
		return (-1);
	if (op_and_2(d, player, &value) < 0)
		return (-1);
	ft_bzero(player->reg[reg], REG_SIZE);
	ft_bzero(str, REG_SIZE + 1);
	int_to_reg(d, player, value[0] & value[1], reg);
	player->carry = true;
	pc_advance(d, player, ret);
	return (0);
}
