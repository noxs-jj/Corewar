/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 17:49:19 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_DIR | T_IND, T_REG
** change carry
** has idx
*/

int		op_ld(t_data *d, t_header *player)
{
	int 			ret;
	unsigned int 	reg;
	int 			value;
	int i;
	
	writeL("--- op_ld ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(get_int_from_dec(player->opArgs[1], T_LAB)) < 0)
		return (ret);		
	reg = get_int_from_dec(player->opArgs[1], T_LAB);
	if (is_direct(player, 0) >= 0)
	{
		value = get_int_from_dec(player->opArgs[0], T_LAB);
		value = get_arg_modulo(value, IDX_MOD);
		int_to_reg(d, player, value, reg);
	}
	else if (is_indirect(player, 0) >= 0)
	{
		value = get_int_from_dec(player->opArgs[0], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			value = value - 65536;
		value = get_arg_modulo(value, IDX_MOD);
		value = (player->indexPC + value + MEM_SIZE) % MEM_SIZE;
		map_to_reg(d, player, reg, value);
	}
	else
		return (-1);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}


/*
int		op_ld(t_data *d, t_header *player)
{
	int 			ret;
	unsigned int 	reg;
	int 			value;
	int i;
	
	writeL("--- op_ld ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0)
		return (ret);
	reg = ft_hex2Dec(player->opArgs[1]);

	value = get_arg_int(player->opArgs[0]);
	value = get_arg_modulo(value, IDX_MOD);
	ft_bzero(player->reg[reg], REG_SIZE);
	value = (player->indexPC + value + MEM_SIZE) % MEM_SIZE;
	map_to_reg(d, player, reg, value);
	// i = 0;
	// while (i < REG_SIZE)
	// {
	// 	ft_strncpy(&player->reg[reg][i * 2],
	// 		d->map[(player->indexPC + value + i + MEM_SIZE) % MEM_SIZE].hex, 2);
	// 	i++;
	// }
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}
*/