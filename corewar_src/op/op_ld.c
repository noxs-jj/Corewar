/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 19:31:26 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_DIR | T_IND, T_REG
** change carry
** has idx
*/
static int	op_ld_2(t_data *d, t_header *player, int *value, unsigned int *reg)
{
	if (is_direct(player, 0) >= 0)
	{
		(*value) = get_int_from_dec((char *)player->op_args[0], T_LAB);
		if (player->op_args[0][T_LAB - 2] >= 240)
			(*value) = (*value) - 65536;
		int_to_reg(d, player, (*value), (*reg));
	}
	else if (is_indirect(player, 0) >= 0)
	{
		(*value) = get_int_from_dec((char *)player->op_args[0], T_LAB);
		if (player->op_args[0][T_LAB - 2] >= 240)
			(*value) = (*value) - 65536;
		(*value) = get_arg_modulo((*value), IDX_MOD);
		(*value) = (player->index_pc + (*value) + MEM_SIZE) % MEM_SIZE;
		map_to_reg(d, player, (*reg), (*value));
	}
	else
		return (-1);
	return (0);
}

int			op_ld(t_data *d, t_header *player)
{
	int				ret;
	unsigned int	reg;
	int				value;

	player->carry = false;
	if ((ret = get_op_args(d, player)) < 0
		|| is_valid_register(get_int_from_dec((char *)player->op_args[1],
			T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec((char *)player->op_args[1], T_LAB);
	if (op_ld_2(d, player, &value, &reg) < 0)
		return (-1);
	player->carry = true;
	pc_advance(d, player, ret);
	return (0);
}
