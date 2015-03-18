/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_render_shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:11:45 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/20 14:11:45 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	render_shell(t_data *d)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = L_X_MAP_START;
	y = L_Y_MAP_START;
	write_l("render_shell Start");
	while (y < L_Y_MAP_END)
	{
		x = L_X_MAP_START;
		while (x < L_X_MAP_END && i < MEM_SIZE)
		{
			if (d->map[i].live == 10)
			{
				ft_putstr("\tun processus dit que le joueur | ");
				ft_putstr(d->prog[(d->map[i].champ - 1)].prog_name);
				ft_putstr(" | est en vie\n");
			}
			i++;
		}
		y++;
	}
}
