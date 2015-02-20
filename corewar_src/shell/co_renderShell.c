/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_renderShell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:11:45 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/20 14:11:45 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

//"un processus dit que le joueur x(nom_champion) est en vie"

void	renderShell(t_data *d)
{
	int			i = 0;
	int			x = L_X_MAP_START;
	int 		y = L_Y_MAP_START;

	while (y < L_Y_MAP_END)
	{
		x = L_X_MAP_START;
		while (x < L_X_MAP_END && i < MEM_SIZE)
		{
			if (d->map[i].live == 10)
			{
				ft_putstr("un processus dit que le joueur ");
				ft_putstr(d->prog[d->map[i].champ].prog_name);
				ft_putstr(" est en vie");
			}
			i++; // case mem jump
		}
		y++;
	}
}
