/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_color_champ4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 16:20:07 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/23 16:20:08 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	color_champ4(t_data *d, int i)
{
	if (d->map[i].present == true)
		d->caseColor = COLOR_PAIR(14);
	else if (d->map[i].live > 0)
	{
		d->caseColor = COLOR_PAIR(24);
		d->map[i].live--;
	}
	else if (d->map[i].recent > 0)
	{
		d->caseColor = COLOR_PAIR(34);
		d->map[i].recent--;
	}
	else
		d->caseColor = COLOR_PAIR(4);
}
