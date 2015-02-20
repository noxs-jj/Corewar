/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_showInitPlayers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:55:32 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/20 13:55:33 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	co_showInitPlayers(t_data *d)
{
	if (d->players > 0)
		co_infoPlayer1(d);
	if (d->players > 1)
		co_infoPlayer2(d);
	if (d->players > 2)
		co_infoPlayer3(d);
	if (d->players > 3)
		co_infoPlayer4(d);
}
