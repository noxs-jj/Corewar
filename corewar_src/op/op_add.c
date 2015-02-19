/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/19 12:19:41 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** not tested
*/

int		op_add(t_data *d, t_header *player, int id)
{
	int ret;
	unsigned int reg;
	unsigned int value;
	
	if ((ret = getOpArgs(&d->prog[id], id)) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[0])) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[1])) < 0
		|| isValidRegister(ft_hex2Dec(player->opArgs[2])) < 0)
		return (ret);
	value = 0;
	reg = ft_hex2Dec(player->opArgs[2]);
	ft_bzero(player->opArgs[reg], REG_SIZE);
	value = player->reg[ft_hex2Dec(player->opArgs[0])];
	value += player->reg[ft_hex2Dec(player->opArgs[1])];
	ft_strcpy(player->opArgs[reg], ft_itoa(value));
	player->carry = true;
	pcAdvance(d, &d->prog[id], ret);
	return (0);
}