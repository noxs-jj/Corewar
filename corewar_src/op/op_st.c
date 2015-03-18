/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 19:33:25 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_REG, T_IND | T_REG
** has idx (op_tab incorrect)
*/

int		op_st(t_data *d, t_header *player)
{
	int 			ret;
	unsigned int 	reg;
	int 			value;

	player->carry = false;
	if ((ret = get_op_args(d, player)) < 0
		|| is_valid_register(get_int_from_dec((char *)player->opArgs[0], T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec((char *)player->opArgs[0], T_LAB);
	if (is_register(player, 1) >= 0)
		value = reg_to_int(d, player, get_int_from_dec((char *)player->opArgs[1], T_LAB));
	else if (is_indirect(player, 1) >= 0)
	{
		value = get_int_from_dec((char *)player->opArgs[1], T_LAB);
		if (player->opArgs[1][T_LAB - 2] >= 240)
			value = value - 65536;
		value = get_arg_modulo(value, IDX_MOD);
	}
	else
		return (-1);
	value = get_arg_modulo(value, IDX_MOD);
	change_mem_val(d, player->number, (player->indexPC + value + MEM_SIZE)
		% MEM_SIZE, (char *)player->reg[reg]);
	player->carry = true;
	pc_advance(d, player, ret);
	return (0);
}
