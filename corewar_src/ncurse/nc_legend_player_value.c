/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_legend_player_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:46:34 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/11 11:46:35 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	render_legend_player_value(t_data *d)
{
	if (d->real_players > 0)
		render_legend_player_value1(d);
	if (d->real_players > 1)
		render_legend_player_value2(d);
	if (d->real_players > 2)
		render_legend_player_value3(d);
	if (d->real_players > 3)
		render_legend_player_value4(d);
}
