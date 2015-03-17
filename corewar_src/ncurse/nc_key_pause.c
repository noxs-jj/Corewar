/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_key_pause.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:42:25 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/17 12:42:26 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

void	key_pause(t_data *d)
{
	if (d->pause == true)
	{
		d->pause = false;
		writeL("keyboard\tRUNNING");
	}
	else
	{
		d->pause = true;
		writeL("keyboard\tPAUSE");
		render_draw(d);
	}
}
