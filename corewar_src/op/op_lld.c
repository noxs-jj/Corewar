/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/25 17:09:39 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** not tested
** T_DIR | T_IND, T_REG
** change carry
*/

int		op_lld(t_data *d, t_header *player, int id)
{
	int ret;
	unsigned int reg;
	int value;
	
	writeL("--- op_ld ---");
	if ((ret = getOpArgs(d, id)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0)
		return (ret);
	reg = ft_hex2Dec(player->opArgs[1]);
	value = ft_hex2intdec(player->opArgs[0]);
	ft_bzero(player->reg[reg], REG_SIZE);
	ft_strcpy(player->reg[reg], player->opArgs[0]);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}