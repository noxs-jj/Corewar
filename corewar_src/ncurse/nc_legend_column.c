/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_legend_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:48:03 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 17:48:04 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	render_legend_column(t_data *d)
{
	int y;

	y = 1;
	while (y < MAP_HEIGHT - 1)
	{
		mvwaddch(d->window, y, L_X_START, '|');
		y++;
	}
}
