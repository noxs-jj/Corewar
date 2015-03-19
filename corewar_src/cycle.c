/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 15:51:02 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/19 15:30:12 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	check_cyles2(t_data *d)
{
	int			more_recent_live;
	t_header	*prog;

	if (d->cycle_die <= 0 || d->alive_players <= 1)
	{
		d->run = false;
		d->i_check_cycles = 1;
		more_recent_live = 0;
		while ((prog = search_prog(d, d->i_check_cycles)) != NULL)
		{
			if (prog->last_live > more_recent_live
				&& prog->alive == true)
			{
				more_recent_live = prog->last_live;
				d->nbr_winner = prog->number;
			}
			d->i_check_cycles++;
		}
	}
}

static void	kill_them_all(t_data *d)
{
	t_header	*prog;

	prog = d->prog;
	while (prog != NULL)
	{
		if (prog->number == d->i_check_cycles)
			prog->alive = false;
		prog = prog->next;
	}
}

void		check_cyles(t_data *d)
{
	t_header	*prog;

	if (d->cycle % d->cycle_die == 0)
	{
		write_l("enter to check_cyles:: check_cyles");
		d->alive_players = 0;
		d->i_check_cycles = 1;
		while ((prog = search_prog(d, d->i_check_cycles)) != NULL)
		{
			if (prog->live_nbr == 0 && prog->alive == true)
				kill_them_all(d);
			else if (prog->alive == true)
				d->alive_players++;
			prog->live_nbr = 0;
			d->i_check_cycles++;
		}
		d->i_max_check++;
		if (d->lives_current >= NBR_LIVE || d->i_max_check >= MAX_CHECKS)
		{
			d->cycle_die -= CYCLE_DELTA;
			d->i_max_check = 0;
		}
		d->lives_current = 0;
	}
	check_cyles2(d);
}
