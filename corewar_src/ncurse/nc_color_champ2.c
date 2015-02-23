/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_color_champ2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 16:19:59 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/23 16:20:00 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	color_champ2(t_data *d, int i)
{
	if (d->map[i].present == true)
		d->caseColor = COLOR_PAIR(12);
	else if (d->map[i].live > 0)
	{
		d->caseColor = COLOR_PAIR(22);
		d->map[i].live--;
	}
	else if (d->map[i].recent > 0)
	{
		d->caseColor = COLOR_PAIR(32);
		d->map[i].recent--;
	}
	else
		d->caseColor = COLOR_PAIR(2);
}
