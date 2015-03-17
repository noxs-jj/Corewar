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
	char			str[REG_SIZE + 1];

	writeL("--- op_st ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(get_int_from_dec(player->opArgs[0], T_LAB)) < 0)
		return (ret);
	reg = get_int_from_dec(player->opArgs[0], T_LAB);
	if (is_register(player, 1) >= 0)
		value = reg_to_int(d, player, get_int_from_dec(player->opArgs[1], T_LAB));
	else if (is_indirect(player, 1) >= 0)
	{
		value = get_int_from_dec(player->opArgs[1], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			value = value - 65536;
		value = get_arg_modulo(value, IDX_MOD);
	}
	else
		return (-1);
	changeMemVal(d, player->number, (player->indexPC + value + MEM_SIZE) % MEM_SIZE, player->reg[reg]);
	player->carry = true;
	pcAdvance(d, player, ret);
}


/*
int		op_st(t_data *d, t_header *player)
{
	int 			ret;
	unsigned int 	reg;
	int 			value;
	char			str[REG_SIZE + 1];

	writeL("--- op_st ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0)
		return (ret);
	if (ft_strncmp(&player->codage[2], "01", 2) == 0
		&& isValidRegister(ft_hex2Dec(player->opArgs[1])) >= 0)
	{
		reg = ft_hex2Dec(player->opArgs[0]);
		value = reg_to_int(d, player, reg);
		// value = get_arg_int(player->reg[reg]);
		value = get_arg_modulo(value, IDX_MOD);
		reg = ft_hex2Dec(player->opArgs[1]);
		ft_bzero(str, REG_SIZE + 1);
		ft_putHexBNbr(value, str);
		ft_bzero(player->reg[reg], REG_SIZE);
		ft_strncpy(player->reg[reg], str, REG_SIZE);
	}
	else
	{
		value = get_arg_int(player->opArgs[1]);
		// writeL(ft_itoa(value));
		// sleep(5);
		value = get_arg_modulo(value, IDX_MOD);
		reg = ft_hex2Dec(player->opArgs[0]);
		changeMemVal(d, player->number,
			(player->indexPC + value + MEM_SIZE) % MEM_SIZE, player->reg[reg]);
	}
	player->carry = true;
	pcAdvance(d, player, ret);
}
*/













// int		op_st(t_data *d, t_header *player)
// {
// 	int 			ret;
// 	unsigned int 	reg;
// 	int 			value;
// 	char			str[REG_SIZE + 1];
// 	char			tmp[DIR + 1];

// 	writeL("--- op_st ---");
// 	ft_memset(tmp, 'f', DIR);
// 	tmp[DIR] = '\0';
// 	if ((ret = getOpArgs(d, player)) < 0
// 		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0)
// 		return (ret);
// 	reg = ft_hex2Dec(player->opArgs[0]);
// 	ft_bzero(str, REG_SIZE + 1);

// 	if (player->opArgs[1][0] == 'f')
// 		value = ((int)(ft_hex2Dec(player->reg[reg]) - ft_hex2Dec(tmp) - 1) % -IDX_MOD);
// 	else
// 		value = (ft_hex2Dec(player->reg[reg]) % IDX_MOD);

// 	writeL("player")
// 	writeL(ft_itoa(player->number))
// 	writeL("registreNbr");
// 	writeL(ft_itoa(reg));
// 	writeL("registre content");
// 	writeL(player->reg[reg]);
// 	writeL("value");
// 	writeL(ft_itoa(value));

// 	if (ft_strncmp(&player->codage[2], "01", 2) == 0
// 		&& isValidRegister(ft_hex2Dec(player->opArgs[1])) >= 0)
// 	{
// 		ft_putHexBNbr(value, str);
// 		reg = ft_hex2Dec(player->opArgs[1]);
// 		ft_bzero(player->reg[reg], REG_SIZE);
// 		ft_strcpy(player->reg[reg], str);
// 		writeL("registre1Nbr");
// 		writeL(ft_itoa(reg));
// 		writeL("registre1");
// 		writeL(player->reg[reg]);
// 		writeL("str");
// 		writeL(str);
// 	}	
// 	else
// 	{

// 		changeMemVal(d, player->number, player->indexPC + value, player->reg[reg]); // + 1?
// 	}
	
// 	sleep(10);
// 	player->carry = true;
// 	pcAdvance(d, player, ret);
// 	return (0);
// }


// int		op_st(t_data *d, t_header *player)
// {
// 	int 			ret;
// 	unsigned int 	reg;
// 	int 			value;

// 	// writeL("--- op_st ---");
// 	if ((ret = getOpArgs(d, player)) < 0
// 		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0)
// 		return (ret);
// 	reg = ft_hex2Dec(player->opArgs[0]);
// 	if (ft_strncmp(&player->codage[2], "11", 2) == 0)
// 		value = ft_hex2Dec(player->opArgs[1]);
// 	else
// 		value = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[1])]);
// 	if (value > 0)
// 		changeMemVal(d, player->number, player->indexPC + ((value % IDX_MOD)), player->reg[reg]); // + 1?
// 	else
// 		changeMemVal(d, player->number, player->indexPC + ((value % -IDX_MOD)), player->reg[reg]); // + 1?
// 	player->carry = true;
// 	pcAdvance(d, player, ret);
// 	return (0);
// }
