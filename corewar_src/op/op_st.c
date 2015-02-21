/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/21 12:43:52 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** not done
** T_REG, T_IND | T_REG
*/

int		op_st(t_data *d, t_header *player, int id)
{
	int ret;
	unsigned int reg;
	int value;

	if ((ret = getOpArgs(d, id)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0)
		return (ret);
	reg = ft_hex2Dec(player->opArgs[0]);
	ft_bzero(player->opArgs[reg], REG_SIZE);
	if (ft_strncmp(&player->codage[2], "11", 2) == 0)
		value = ft_hex2Dec(player->opArgs[1]);
	else
		value = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[1])]);
	changeMemVal(d, id, player->indexPC + (value / 2), player->reg[reg]); // + 1?
	// ft_strcpy(player->opArgs[reg], player->opArgs[0]);
	player->carry = true;
	pcAdvance(d, player, ret);
	writeL("--- op_st ---");
	writeL(ft_itoa(ret));
	sleep(10);
	return (0);
}