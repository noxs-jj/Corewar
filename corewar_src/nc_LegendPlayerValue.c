/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_LegendPlayerValue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:46:34 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/11 11:46:35 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void	renderLegendPlayerValue(t_data *d)
{
	if (d->players > 0)
		renderLegendPlayerValue1(d);
	if (d->players > 1)
		renderLegendPlayerValue2(d);
	if (d->players > 2)
		renderLegendPlayerValue3(d);
	if (d->players > 3)
		renderLegendPlayerValue4(d);
}
