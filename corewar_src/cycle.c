/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 15:51:02 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/26 15:46:38 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	check_cyles2(t_data *d)
{
	int			moreRecentLive;
	t_header	*prog;

	if (d->cycleDie <= 0)
	{
		d->run = false;
		d->iCheckCycles = 1;
		moreRecentLive = 0;
		while ((prog = searchProg(d, d->iCheckCycles)) != NULL)
		{
			if (prog->lastLive > moreRecentLive
				&& prog->alive == true)
			{
				moreRecentLive = prog->lastLive;
				d->nbrWinner = prog->number;
			}
			d->iCheckCycles++;
		}
	}
}

void	check_cyles(t_data *d)
{
	t_header	*prog;

	if (d->cycle % d->cycleDie == 0)
	{
		d->iCheckCycles = 1;
		while ((prog = searchProg(d, d->iCheckCycles)) != NULL)
		{
			if (prog->liveNbr == 0)
				prog->alive = false;
			if (prog->alive == true)
				prog->liveNbr = 0;
			d->iCheckCycles++;
		}
		d->iMaxCheck++;
		if (d->livesCurrent >= NBR_LIVE || d->iMaxCheck >= MAX_CHECKS)
		{
			d->cycleDie -= CYCLE_DELTA;
			d->iMaxCheck = 0;
		}
		d->livesCurrent = 0;
	}
	check_cyles2(d);
}
