/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_color_champ3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 16:20:03 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/23 16:20:04 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	color_champ3(t_data *d, int i)
{
	if (d->map[i].present == true)
		d->caseColor = COLOR_PAIR(13);
	else if (d->map[i].live > 0)
	{
		d->caseColor = COLOR_PAIR(23);
		d->map[i].live--;
	}
	else if (d->map[i].recent > 0)
	{
		d->caseColor = COLOR_PAIR(33);
		d->map[i].recent--;
	}
	else
		d->caseColor = COLOR_PAIR(3);	
}
