/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_showInitPlayers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:55:32 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/26 15:07:48 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	co_showInitPlayers(t_data *d)
{
	t_header	*prog;

	if (d->players > 0 && (prog = searchProg(d, d->nbrWinner)) != NULL)
		co_infoPlayer1(d, prog);
	if (d->players > 1 && (prog = searchProg(d, d->nbrWinner)) != NULL)
		co_infoPlayer2(d, prog);
	if (d->players > 2 && (prog = searchProg(d, d->nbrWinner)) != NULL)
		co_infoPlayer3(d, prog);
	if (d->players > 3 && (prog = searchProg(d, d->nbrWinner)) != NULL)
		co_infoPlayer4(d, prog);
}
