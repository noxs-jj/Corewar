/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/16 13:19:47 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

int		op_live(t_data *d, int player)
{
	// avancer PC
	if (d->prog[player].PC > 0 && d->prog[player].PC < d->players)
	{
		d->prog[player].wait = op_tab[d->prog[player].nextOp][4];
		d->prog[d->prog[player].PC].lastLive = d->cycle;
		d->prog[d->prog[player].PC].liveNbr++;
	}
	return (0);
}