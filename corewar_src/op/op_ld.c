/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/25 16:50:21 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_DIR | T_IND, T_REG
*/

int		op_ld(t_data *d, t_header *player, int id)
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
	ft_bzero(player->opArgs[reg], REG_SIZE);
	ft_strcpy(player->opArgs[reg], player->opArgs[0]);
	player->carry = true;
	pcAdvance(d, player, ret);
	return (0);
}