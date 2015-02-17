/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/17 14:33:21 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

int		op_live(t_data *d, t_header *player, int id)
{
	t_case *arg;
	int ret;
	
	if ((ret = getOpArgs(d, id)) < 0)
		return (ret);

	if (player->PC > 0 && player->PC < d->players)
	{
		player->wait = op_tab[player->nextOp][4];
		d->prog[ft_hex2Dec(player->opArgs[0])].lastLive = d->cycle;
		d->prog[player->PC].liveNbr++;
	}
	player->PC = ((player->PC) + ret);
	return (0);
}
