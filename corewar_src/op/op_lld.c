/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/09 14:31:34 by vjacquie         ###   ########.fr       */
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
	int				ret;
	unsigned int 	reg;
	int				value;
	int				i;
	
	writeL("--- op_lld ---");
	player->carry = false;
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0)
		return (ret);
	reg = ft_hex2Dec(player->opArgs[1]);
	value = get_arg_int(player->opArgs[0]);
	ft_bzero(player->reg[reg], REG_SIZE);
	i = REG_SIZE / 2;
	value = get_arg_modulo(value, MEM_SIZE);
	while (i < REG_SIZE)
	{
		ft_strncpy(&player->reg[reg][(i - REG_SIZE / 2) * 2],
			d->map[(player->indexPC + value + (i - REG_SIZE / 2) + MEM_SIZE) % MEM_SIZE].hex, 2);
		i++;
	}
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}
