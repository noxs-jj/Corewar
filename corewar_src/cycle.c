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

static void	check_cyles2(t_data *d)
{
	int			more_recent_live;
	t_header	*prog;

	if (d->cycleDie <= 0)
	{
		d->run = false;
		d->iCheckCycles = 1;
		more_recent_live = 0;
		while ((prog = search_prog(d, d->iCheckCycles)) != NULL)
		{
			if (prog->lastLive > more_recent_live
				&& prog->alive == true)
			{
				more_recent_live = prog->lastLive;
				d->nbrWinner = prog->number;
			}
			d->iCheckCycles++;
		}
	}
}

void		check_cyles(t_data *d)
{
	t_header	*prog;

	if (d->cycle % d->cycleDie == 0)
	{
		write_l("enter to check_cyles:: check_cyles");
		d->iCheckCycles = 1;
		while ((prog = search_prog(d, d->iCheckCycles)) != NULL)
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
