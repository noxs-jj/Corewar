/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_draw_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 12:42:44 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 12:42:45 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/render.h"

void	renderDraw(t_data *d)
{
	werase(d->window);
	wborder(d->window, '|', '|', '-', '-', '+', '+', '+', '+');

	renderLegendColumn(d);
	renderLegendSentence(d);
	renderLegendPlayerSentence(d);
	renderLegendPlayerValue(d);
	renderLegendInfoValue(d);

	refresh();
	wrefresh(d->window);
}
