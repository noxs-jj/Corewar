/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 15:51:02 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/23 15:51:02 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
check liveNbr;  Lives in current period :   if > 0

CYCLE_TO_DIE : 1536

CYCLE_DELTA : 50

NBR_LIVE : 21

MAX_CHECKS : 10
*/

void	checkCyles(t_data *d)
{
	int	moreRecentLive;

	if (d->cycle % d->cycleDie == 0)
	{
		d->iCheckCycles = 0;
		while (d->iCheckCycles < d->players) // check lives all players
		{
			if (d->prog[d->iCheckCycles].liveNbr == 0) // if players wasn't live set it to DIE
				d->prog[d->iCheckCycles].alive = false;
			d->iCheckCycles++;
		}
		d->iCheckCycles = 0;
		while (d->iCheckCycles < d->players) // reset live current session all players
		{
			d->prog[d->iCheckCycles].liveNbr = 0;
			d->iCheckCycles++;
		}
		d->iMaxCheck++; // incr maxcheck
		if (d->livesCurrent >= NBR_LIVE || d->iMaxCheck >= MAX_CHECKS)
		{
			d->cycleDie -= CYCLE_DELTA;
			if (d->cycleDie <= 0) // Game done
			{
				d->run = false; // Stop the game
				i = 0;
				moreRecentLive = 0;
				while (i < d->players) // search the winner
				{
					if (d->prog[i].lastlive > moreRecentLive
						&& d->prog[i].alive == true)
						d->nbrWinner = i;
					i++;
				}
			}
			d->iMaxCheck = 0; // reset maxcheck
		}		
		d->livesCurrent = 0; // reset livescurrents
	}
}
