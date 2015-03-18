/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 19:42:41 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_DIR | T_IND, T_REG
** change carry
*/


int		op_lld(t_data *d, t_header *player)
{
	int 			ret;
	unsigned int 	reg;
	int 			value;
	
	writeL("--- op_lld ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(get_int_from_dec((char *)player->opArgs[1], T_LAB)) < 0)
		return (ret);		
	reg = get_int_from_dec((char *)player->opArgs[1], T_LAB);
	if (is_direct(player, 0) >= 0)
	{
		value = get_int_from_dec((char *)player->opArgs[0], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			value = value - 65536;
		// value = get_arg_modulo(value, IDX_MOD);
		int_to_reg(d, player, value, reg);
	}
	else if (is_indirect(player, 0) >= 0)
	{
		value = get_int_from_dec((char *)player->opArgs[0], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			value = value - 65536;
		value = get_arg_modulo(value, IDX_MOD);
		value = (player->indexPC + value + MEM_SIZE) % MEM_SIZE;
		map_to_reg(d, player, reg, value);
		player->reg[reg][0] = 0;
		player->reg[reg][1] = 0;
	}
	else
		return (-1);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}


/*
int		op_lld(t_data *d, t_header *player)
{
	int				ret;
	unsigned int 	reg;
	int				value;
	int				i;
	
	writeL("--- op_lld ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec((char *)player->opArgs[1])) < 0)
		return (ret);
	reg = ft_hex2Dec((char *)player->opArgs[1]);
	value = get_arg_int(player->opArgs[0]);
	ft_bzero(player->reg[reg], REG_SIZE);
	i = REG_SIZE / 2;
	value = get_arg_modulo(value, MEM_SIZE);
	value = (player->indexPC + value + MEM_SIZE) % MEM_SIZE;
	map_to_reg(d, player, reg, value);
	// while (i < REG_SIZE)
	// {
	// 	ft_strncpy(&player->reg[reg][(i - REG_SIZE / 2) * 2],
	// 		d->map[(player->indexPC + value + (i - REG_SIZE / 2) + MEM_SIZE) % MEM_SIZE].hex, 2);
	// 	i++;
	// }
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}

*/
