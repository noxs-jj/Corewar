/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 11:55:15 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 14:15:52 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int			init_start(t_data *d, int ac, char **av)
{
	if (ac < 3 || ac > MAX_ARGS_NUMBER)
		return (print_error(ERR_PARAM));
	d->fdDebugg = open(PATH_DEBUGG, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (d->fdDebugg < 0)
		return (print_error(ERR_FILE_DEBUGG));
	d->dump = -1;
	d->pause = false;
	d->players = -1;
	d->cycleDie = CYCLE_TO_DIE;
	d->cycle = 0;
	d->livesCurrent = 0;
	d->iMaxCheck = 0;
	d->nbrWinner = 999;
	d->graphActiv = false;
	d->prog = NULL;
	d->option_log = 0;
	if (checkparam(d, ac, av) < 0)
		return (-1);
	write_l("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nenter to init_start:: done");
	return (0);
}
