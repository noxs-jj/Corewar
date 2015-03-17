/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 19:41:18 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** OK
** T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG
** change carry ?
** has idx
*/
	
int		op_sti(t_data *d, t_header *player)
{
	int				ret;
	unsigned int	reg;
	int				value[2];

	writeL("--- op_sti ---");
	if ((ret = getOpArgs(d, player)) < 0
		&& isValidRegister(get_int_from_dec(player->opArgs[0], T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec(player->opArgs[0], T_LAB);
	if (is_register(player, 1) >= 0)
		value[0] = reg_to_int(d, player, get_int_from_dec(player->opArgs[1], T_LAB));
	else if (is_direct(player, 1) >= 0)
	{
		value[0] = get_int_from_dec(player->opArgs[1], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			value[0] = value[0] - 65536;
	}
	else if (is_indirect(player, 1) >= 0)
	{
		value[0] = get_int_from_dec(player->opArgs[1], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			value[0] = value[0] - 65536;
		value[0] = get_arg_modulo(value[0], IDX_MOD);
	}
	else
		return (-1);
	if (is_register(player, 2) >= 0)
		value[0] += reg_to_int(d, player, get_int_from_dec(player->opArgs[2], T_LAB));
	else if (is_direct(player, 2) >= 0)
	{
		value[1] = get_int_from_dec(player->opArgs[2], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			value[1] = value[1] - 65536;
		value[0] += value[1];
	}
	else
		return (-1);
	value[0] = get_arg_modulo(value[0] - 1, IDX_MOD); // why -1 ?
	changeMemVal(d, player->number, (player->indexPC + 1 + value[0] + MEM_SIZE) % MEM_SIZE, player->reg[reg]);
	pcAdvance(d, player, ret);
	return (0);
}

/*
int		op_sti(t_data *d, t_header *player)
{
	int ret;
	unsigned int reg;
	int value;

	writeL("--- op_sti ---");
	if ((ret = getOpArgs(d, player)) < 0
		&& isValidRegister(get_int_from_dec(player->opArgs[0], T_LAB)) < 0)
	{
		writeL("error in op_sti arg");
		// sleep(5);
		return (ret);
	}
	reg = isValidRegister(get_int_from_dec(player->opArgs[0], T_LAB));

	if (ft_strncmp(&player->codage[2], "01", 2) == 0
		&& isValidRegister(isValidRegister(get_int_from_dec(player->opArgs[1], T_LAB))) >= 0)
		value = reg_to_int(d, player, get_int_from_dec(player->opArgs[1], T_LAB));
		// value = get_arg_int(player->reg[ft_hex2Dec(player->opArgs[1])]);
	else
		value = get_int_from_dec(player->opArgs[1], T_LAB);
	writeL("first = ");
	writeL(ft_itoa(value));

	if (ft_strncmp(&player->codage[4], "01", 2) == 0
		&& isValidRegister(isValidRegister(get_int_from_dec(player->opArgs[2], T_LAB))) >= 0)
		value += reg_to_int(d, player, get_int_from_dec(player->opArgs[2], T_LAB));
		// value += get_arg_int(player->reg[ft_hex2Dec(player->opArgs[2])]);
	else
		value += get_int_from_dec(player->opArgs[2], T_LAB);
	writeL("value =");
	writeL(ft_itoa(value));
	value = get_arg_modulo(value - 1, IDX_MOD); // why -1 ?
	
	// writeL("value 2");
	// writeL(ft_itoa(reg_to_int(d, player, ft_hex2Dec(player->opArgs[2]))));
	sleep(5);
	changeMemVal(d, player->number, (player->indexPC + 1 + value + MEM_SIZE) % MEM_SIZE, player->reg[reg]);
	pcAdvance(d, player, ret);
	return (0);
}
*/