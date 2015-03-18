/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 19:28:17 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_DIR
** has idx_mod
*/

int		op_fork(t_data *d, t_header *player)
{
	int				ret;
	int				result;
	t_header		*prog;

	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, player)) < 0)
		return (ret);
	result = get_int_from_dec((char *)player->opArgs[0], T_LAB);
	if (player->opArgs[0][T_LAB - 2] >= 240)
			result = result - 65536;
	if (addProg(d, newProg(player->number)) < 0)
		return (-1);
	d->players++;
	prog = lastProg(d);
	copyProg(d, player, prog);
	result = get_arg_modulo(result - 1, IDX_MOD);
	pcAdvance(d, prog, result);
	pcAdvance(d, player, ret);
	return (0);
}
