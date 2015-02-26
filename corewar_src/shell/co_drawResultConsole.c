/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_drawResultConsole.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:00:49 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/13 15:00:50 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

//le joueur x(nom_champion) a gagne

void	drawResultConsole(t_data *d)
{
	if (true == d->graphActiv)
	{
		renderClose(d);
		sleep(1);
	}
	if (999 != d->nbrWinner && -1 == d->dump)
	{
		co_troll_all();
		ft_putstr("#######################################################\n");
		ft_putstr("\t\tle joueur ");
		ft_putstr(d->prog[d->nbrWinner - 1].prog_name); // player number
		ft_putstr(" a gagne\n");
		ft_putstr("#######################################################\n");
	}
	else if (-1 == d->dump)
	{
		co_troll_all();
		ft_putstr("No Winner\n");
	}
}
