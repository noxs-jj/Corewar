/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/18 13:05:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

int		op_live(t_data *d, t_header *player, int id)
{
	t_case *arg;
	int ret;
	
	if ((ret = getOpArgs(d, id)) < 0 || ft_hex2Dec(player->opArgs[0]) < 0
		|| ft_hex2Dec(player->opArgs[0]) > d->players)
		return (-1);
	player->wait = op_tab[player->nextOp].nb_cycles;
	d->prog[ft_hex2Dec(player->opArgs[0])].lastLive = d->cycle;
	d->prog[ft_hex2Dec(player->opArgs[0])].liveNbr++;
	// player->PC = ((player->PC) + ret);
	writeL("live for ");
	writeL(ft_itoa(ft_hex2Dec(player->opArgs[0])));
	writeL("done");
	return (0);
}
