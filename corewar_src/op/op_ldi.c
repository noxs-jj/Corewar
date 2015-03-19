/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 19:39:24 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** need test
** T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG
** has idx
*/
static int	op_ldi_3(t_data *d, t_header *player, int (*result)[])
{
	if (is_register(player, 0) >= 0)
		(*result)[0] = reg_to_int(d, player,
			get_int_from_dec((char *)player->opArgs[0], T_LAB));
	else if (is_direct(player, 0) >= 0)
	{
		(*result)[0] = get_int_from_dec((char *)player->opArgs[0], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			(*result)[0] = (*result)[0] - 65536;
	}
	else if (is_indirect(player, 0) >= 0)
	{
		(*result)[0] = get_int_from_dec((char *)player->opArgs[0], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			(*result)[0] = (*result)[0] - 65536;
		(*result)[0] = get_arg_modulo((*result)[0], IDX_MOD);
	}
	else
		return (-1);
	return (0);
}

static int	op_ldi_2(t_data *d, t_header *player, int (*result)[])
{
	if (is_register(player, 1) >= 0)
		(*result)[0] += reg_to_int(d, player,
			get_int_from_dec((char *)player->opArgs[1], T_LAB));
	else if (is_direct(player, 1) >= 0)
	{
		(*result)[1] = get_int_from_dec((char *)player->opArgs[1], T_LAB);
		if (player->opArgs[1][T_LAB - 2] >= 240)
			(*result)[1] = (*result)[1] - 65536;
		(*result)[0] += (*result)[1];
	}
	else
		return (-1);
	return (0);
}

int			op_ldi(t_data *d, t_header *player)
{
	int	ret;
	int	result[2];
	int	reg;

	if ((ret = get_op_args(d, player)) < 0
		|| is_valid_register(get_int_from_dec((char *)player->opArgs[2],
			T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec((char *)player->opArgs[2], T_LAB);
	if (op_ldi_3(d, player, &result) < 0)
		return (-1);
	if (op_ldi_2(d, player, &result) < 0)
		return (-1);
	result[0] = get_arg_modulo(result[0], IDX_MOD);
	result[0] = (player->indexPC + result[0] + MEM_SIZE) % MEM_SIZE;
	ft_bzero(player->reg[reg], REG_SIZE);
	map_to_reg(d, player, reg, result[0]);
	pc_advance(d, player, ret);
	return (0);
}
