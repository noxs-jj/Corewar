/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_drawResultConsole.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:00:49 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/26 15:11:30 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	draw_result_console(t_data *d)
{
	t_header *prog;

	if (true == d->graphActiv)
	{
		render_close(d);
		sleep(1);
	}
	if (999 != d->nbrWinner && -1 == d->dump)
	{
		co_troll_all();
		ft_putstr("#######################################################\n");
		ft_putstr("\t\tle joueur ");
		if ((prog = searchProg(d, d->nbrWinner)) == NULL)
		{
			writeL("Error in drawResultConsole");
			return ;
		}
		ft_putstr(prog->prog_name);
		ft_putstr(" a gagne\n");
	}
	else if (-1 == d->dump)
	{
		co_troll_all();
		ft_putstr("No Winner\n");
	}
}