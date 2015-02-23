/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/23 13:41:59 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_DIR
*/

int		op_live(t_data *d, t_header *player, int id)
{
	int ret;
	unsigned int value;
	
	writeL("--- op_live ---");
	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, id)) < 0)
		return (ret);

	value = ft_hex2Dec(player->opArgs[0]);
	// writeL("live for:");
	// writeL(player->opArgs[0]);
	// writeL(ft_itoa(value));
	// sleep(10);
	value--;
	if (value >= 0 && value < d->players)
	{
		d->prog[value].lastLive = d->cycle;
		d->prog[value].liveNbr++;
	}
	player->PC->live = 10;
	pcAdvance(d, player, ret);
	return (0);
}
