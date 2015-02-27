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
	t_header *prog;

	if (d->cycle % d->cycleDie == 0)
	{
		writeL("checkCyles boucle 1");


		d->iCheckCycles = 1; // set index to 0
		// prog = d->prog;
		while ((prog = searchProg(d, d->iCheckCycles)) != NULL) // check lives all players
		{
			if (prog->liveNbr == 0) // if players wasn't live set it to DIE
			{
				prog->alive = false;
				writeL("player die");
				writeL(ft_itoa(prog->number));
				//sleep(6);
			}
			if (prog->alive == true)
				prog->liveNbr = 0;
			d->iCheckCycles++;
		}

		d->iMaxCheck++; // incr maxcheck

		if (d->livesCurrent >= NBR_LIVE || d->iMaxCheck >= MAX_CHECKS)
		{
			d->cycleDie -= CYCLE_DELTA;
			
			d->iMaxCheck = 0; // reset maxcheck
		}		
		d->livesCurrent = 0; // reset livescurrents
	}


	if (d->cycleDie <= 0) // Game done
	{
		writeL("checkCyles Game Done");
		d->run = false; // Stop the game
		d->iCheckCycles = 1; // index i
		moreRecentLive = 0;
		// prog = d->prog;
		while ((prog = searchProg(d, d->iCheckCycles)) != NULL) // search the winner
		{
			// writeL("last live");
			// writeL(ft_itoa(prog->lastLive));
			// writeL("moreRecentLive");
			// writeL(ft_itoa(moreRecentLive));
			// writeL("player number");
			// writeL(ft_itoa(prog->number));
			// sleep(5);
			if (prog->lastLive > moreRecentLive
				&& prog->alive == true)
			{
				moreRecentLive = prog->lastLive;
				d->nbrWinner = prog->number;
				// writeL("i'm here !");
				// sleep(10);
			}
			d->iCheckCycles++;
		}

		// writeL(d->prog[d->nbrWinner - 1].prog_name);
		writeL(ft_itoa(d->nbrWinner));
		writeL("^^^  is the winner !!!");
	}
}
