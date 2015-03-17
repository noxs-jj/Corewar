/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 12:53:46 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** OK
** T_DIR
*/


int		op_live(t_data *d, t_header *player)
{
	int				ret;
	unsigned int	value;
	t_header		*prog;
	
	writeL("--- op_live ---");
	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, player)) < 0)
		return (ret);
	value = get_int_from_dec(player->opArgs[0], T_LAB);
	if ((prog = searchProg(d, value)) != NULL)
	{
		prog->lastLive = d->cycle;
		prog->liveNbr++;
		d->livesCurrent++; //checkCycles
	}
	player->PC->live = 10;
	pcAdvance(d, player, ret);
	return (0);
}




/*
int		op_live(t_data *d, t_header *player)
{
	int				ret;
	unsigned int	value;
	t_header		*prog;
	
	writeL("--- op_live ---");
	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, player)) < 0)
		return (ret);
	value = ft_hex2Dec(player->opArgs[0]);
	if ((prog = searchProg(d, value)) != NULL)
	{
		prog->lastLive = d->cycle;
		prog->liveNbr++;
		d->livesCurrent++; //checkCycles
	}
	player->PC->live = 10;
	pcAdvance(d, player, ret);
	return (0);
}

*/