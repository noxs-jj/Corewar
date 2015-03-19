/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_show_init_players.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:55:32 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/26 15:07:48 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	co_show_init_players(t_data *d)
{
	t_header	*prog;

	if (d->players > 0 && (prog = search_prog(d, d->nbr_winner)) != NULL)
		co_info_player1(d, prog);
	if (d->players > 1 && (prog = search_prog(d, d->nbr_winner)) != NULL)
		co_info_player2(d, prog);
	if (d->players > 2 && (prog = search_prog(d, d->nbr_winner)) != NULL)
		co_info_player3(d, prog);
	if (d->players > 3 && (prog = search_prog(d, d->nbr_winner)) != NULL)
		co_info_player4(d, prog);
}
