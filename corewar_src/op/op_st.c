/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/25 17:13:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_REG, T_IND | T_REG
** has idx (op_tab incorrect)
*/

int		op_st(t_data *d, t_header *player, int id)
{
	int 			ret;
	unsigned int 	reg;
	int 			value;

	// writeL("--- op_st ---");
	if ((ret = getOpArgs(d, id)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0)
		return (ret);
	reg = ft_hex2Dec(player->opArgs[0]);
	if (ft_strncmp(&player->codage[2], "11", 2) == 0)
		value = ft_hex2Dec(player->opArgs[1]);
	else
		value = ft_hex2Dec(player->reg[ft_hex2Dec(player->opArgs[1])]);
	if (value > 0)
		changeMemVal(d, id, player->indexPC + ((value % IDX_MOD)), player->reg[reg]); // + 1?
	else
		changeMemVal(d, id, player->indexPC + ((value % -IDX_MOD)), player->reg[reg]); // + 1?
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}
