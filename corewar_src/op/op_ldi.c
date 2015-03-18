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

int		op_ldi(t_data *d, t_header *player)
{
	int				ret;
	int				result[2];
	int 			reg;

	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(get_int_from_dec((char *)player->opArgs[2], T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec((char *)player->opArgs[2], T_LAB);
	if (is_register(player, 0) >= 0)
		result[0] = reg_to_int(d, player, get_int_from_dec((char *)player->opArgs[0], T_LAB));
	else if (is_direct(player, 0) >= 0)
	{
		result[0] = get_int_from_dec((char *)player->opArgs[0], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			result[0] = result[0] - 65536;
	}
	else if (is_indirect(player, 0) >= 0)
	{
		result[0] = get_int_from_dec((char *)player->opArgs[0], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			result[0] = result[0] - 65536;
		result[0] = get_arg_modulo(result[0], IDX_MOD);		
	}
	else
		return (-1);
	if (is_register(player, 1) >= 0)
		result[0] += reg_to_int(d, player, get_int_from_dec((char *)player->opArgs[1], T_LAB));
	else if (is_direct(player, 1) >= 0)
	{
		result[1] = get_int_from_dec((char *)player->opArgs[1], T_LAB);
		if (player->opArgs[1][T_LAB - 2] >= 240)
			result[1] = result[1] - 65536;
		result[0] += result[1];
	}
	else
		return (-1);
	result[0] = get_arg_modulo(result[0], IDX_MOD);
	result[0] = (player->indexPC + result[0] + MEM_SIZE) % MEM_SIZE;
	ft_bzero(player->reg[reg], REG_SIZE);
	map_to_reg(d, player, reg, result[0]);
	pcAdvance(d, player, ret);
	return (0);
}


/*
int		op_ldi(t_data *d, t_header *player)
{
	int				ret;
	int				result;
	char			str[REG_SIZE + 1];

	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec((char *)player->opArgs[2])) < 0) // check reg valid registre
		return (ret);
	if (ft_strncmp(player->codage, "01", 2) == 0
		&& isValidRegister(ft_hex2Dec((char *)player->opArgs[0])) >= 0)
		result = reg_to_int(d, player, ft_hex2Dec((char *)player->opArgs[0]));
		// result = get_arg_int(player->reg[ft_hex2Dec((char *)player->opArgs[0])]);
	else
		result = get_arg_int((char *)player->opArgs[0]);

	if (ft_strncmp(&player->codage[2], "01", 2) == 0
		&& isValidRegister(ft_hex2Dec((char *)player->opArgs[1])) >= 0)
		result += reg_to_int(d, player, ft_hex2Dec((char *)player->opArgs[1]));
		// result += get_arg_int(player->reg[ft_hex2Dec((char *)player->opArgs[1])]);
	else
		result += get_arg_int((char *)player->opArgs[1]);
	result = get_arg_modulo(result, IDX_MOD);
	result = get_arg_int(d->map[(player->indexPC + result + MEM_SIZE) % MEM_SIZE].hex);
	ft_bzero(player->reg[ft_hex2Dec((char *)player->opArgs[2])], REG_SIZE);
	ft_bzero(str, REG_SIZE + 1);
	ft_putHexBNbr(result, str);
	str_to_reg(d, player, ft_hex2Dec((char *)player->opArgs[2]), str);
	// ft_strcpy(player->reg[ft_hex2Dec((char *)player->opArgs[2])], str);
	pcAdvance(d, player, ret);
	return (0);
}
*/
