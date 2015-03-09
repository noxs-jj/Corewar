/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 13:47:04 by vjacquie         ###   ########.fr       */
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
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0)
		return (ret);
	reg = ft_hex2Dec(player->opArgs[1]);

	value = get_arg_int(player->opArgs[0]);
	value = get_arg_modulo(value, IDX_MOD);
	ft_bzero(player->reg[reg], REG_SIZE);
	i = 0;
	while (i < REG_SIZE)
	{
		ft_strncpy(&player->reg[reg][i * 2],
			d->map[(player->indexPC + value + i + MEM_SIZE) % MEM_SIZE].hex, 2);
		i++;
	}
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}
