/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/18 18:43:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

int		op_add(t_data *d, t_header *player, int id)
{
	int ret;
	unsigned int value;
	
	if ((ret = getOpArgs(&d->prog[id], id)) < 0
		|| (value = ft_hex2Dec(player->opArgs[2])) < 0
		|| value > REG_NUMBER)
		return (ret);
	ft_bzero(player->opArgs[value], REG_SIZE);
	ft_strcpy(player->opArgs[value], ft_itoa(ft_hex2Dec(player->opArgs[0]) & ft_hex2Dec(player->opArgs[1])));
	pcAdvance(d, &d->prog[id], ret);
	return (0);
}