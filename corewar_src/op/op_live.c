/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/19 15:16:49 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** not tested
** T_DIR
*/

int		op_live(t_data *d, t_header *player, int id)
{
	int ret;
	unsigned int value;
	
	if ((ret = getOpArgs(d, id)) < 0)
		return (ret);

	value = PLAYER_NBR - ft_hex2Dec(player->opArgs[0]);
	if (value >= 0 && value < d->players)
	{
		d->prog[value].lastLive = d->cycle;
		d->prog[value].liveNbr++;
	}
	player->PC->live = 10;
	pcAdvance(&d->prog[id], d, ret);
	return (0);
}
