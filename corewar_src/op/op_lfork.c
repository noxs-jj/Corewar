/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 16:25:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** need test
** T_DIR
*/

int		op_lfork(t_data *d, t_header *player)
{
	int				ret;
	unsigned int	result;
	t_header		*prog;

	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, player)) < 0) // check reg valid registre
		return (ret);
	result = ft_hex2Dec(player->opArgs[0]);
	addProg(d, newProg(prog->number));
	prog = lastProg(d);
	copyProg(d, player, prog);
	pcAdvance(d, prog, result);
	pcAdvance(d, player, ret);
	return (0);
}