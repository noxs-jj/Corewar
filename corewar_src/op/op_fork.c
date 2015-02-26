/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 14:35:35 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** need test
** T_DIR
** has idx_mod
*/

int		op_fork(t_data *d, t_header *player)
{
	int				ret;
	unsigned int	result;

	if ((ret = getOpArgs(d, player)) < 0) // check reg valid registre
		return (ret);
	result = ft_hex2Dec(player->opArgs[0]);

	

	pcAdvance(d, player, ret);
	return (0);
}