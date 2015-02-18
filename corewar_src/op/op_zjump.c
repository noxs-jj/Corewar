/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/18 18:36:54 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

int		op_zjump(t_data *d, t_header *player, int id)
{
	int		ret;
	
	if ((ret = getOpArgs(d, id)) < 0)
		return (ret);
	if (player->carry == 0)
		pcAdvance(d, player, ret);
	else
		pcAdvance(d, player, ft_hex2intdec(player->opArgs[0]));
	return (0);
}