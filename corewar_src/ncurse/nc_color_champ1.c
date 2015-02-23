/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_color_champ1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 16:19:55 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/23 16:19:56 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	color_champ1(t_data *d, int i)
{
	if (d->map[i].present == true)
		d->caseColor = COLOR_PAIR(11);
	else if (d->map[i].live > 0)
	{
		d->caseColor = COLOR_PAIR(21);
		d->map[i].live--;
	}
	else if (d->map[i].recent > 0)
	{
		d->caseColor = COLOR_PAIR(31);
		d->map[i].recent--;
	}
	else
		d->caseColor = COLOR_PAIR(1);
}
