/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 16:24:50 by vjacquie         ###   ########.fr       */
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

	writeL("--- op_fork ---");
	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, player)) < 0)
		return (ret);

	result = get_int_from_dec(player->opArgs[0], T_LAB);
	if (addProg(d, newProg(player->number)) < 0) // while
		return (-1);
	d->players++;
	prog = lastProg(d);
	copyProg(d, player, prog); // add new prog before 1st elem
	result = get_arg_modulo(result - 1, IDX_MOD);
	pcAdvance(d, prog, result);
	pcAdvance(d, player, ret);
	return (0);
}

/*
int		op_fork(t_data *d, t_header *player)
{
	int				ret;
	int				result;
	t_header		*prog;

	writeL("--- op_fork ---");
	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, player)) < 0)
	{
		writeL("arg wrong");
		return (ret);
	}
	result = get_arg_int(player->opArgs[0]);
	if (addProg(d, newProg(player->number)) < 0) // while
	{
		writeL("new prog failed");
		sleep(5);
		return (-1);
	}
	d->players++;
	prog = lastProg(d);
	copyProg(d, player, prog); // add new prog before 1st elem
	// writeL("player nbr");
	// writeL(ft_itoa(player->number));
	// writeL("arg");
	// writeL(player->opArgs[0]);
	// writeL("result");
	// writeL(ft_itoa(result));
	// writeL("ret");
	// writeL(ft_itoa(ret));
	// sleep(10);
	result = get_arg_modulo(result - 1, IDX_MOD);
	// writeL("move");
	// writeL(ft_itoa(result));
	// writeL(ft_itoa(ret));
	// sleep(10);
	pcAdvance(d, prog, result);
	pcAdvance(d, player, ret);
	return (0);
}
*/