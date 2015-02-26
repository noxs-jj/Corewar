/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 17:38:43 by vjacquie         ###   ########.fr       */
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
	int				result;
	t_header		*prog;
	char	tmp[DIR + 1];

	ft_memset(tmp, 'f', DIR);
	tmp[DIR] = '\0';

	writeL("--- op_fork ---");
	// sleep(1);
	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, player)) < 0)
	{
		writeL("arg wrong");
		sleep(5);
		return (ret);
	}

	if (player->opArgs[0][0] == 'f')
	{
		writeL("yes");
		result = (int)(ft_hex2Dec(player->opArgs[0]) - ft_hex2Dec(tmp) - 1);
	}
	else
	{
		writeL("no");
		result = ft_hex2Dec(player->opArgs[0]);
	}
	writeL("test");
	if (addProg(d, newProg(player->number)) < 0)
	{
		writeL("new prog failed");
		sleep(5);
		return (-1);
	}
	d->players++;
	prog = lastProg(d);
	copyProg(d, player, prog);
	writeL("player nbr");
	writeL(ft_itoa(player->number));
	writeL("arg");
	writeL(player->opArgs[0]);
	writeL("result");
	writeL(ft_itoa(result));
	writeL("ret");
	writeL(ft_itoa(ret));
	// sleep(10);
	result--;	
	if (result < 0)
		pcAdvance(d, prog, result % -IDX_MOD);
	if (result > 0)
		pcAdvance(d, prog, result % IDX_MOD);
	pcAdvance(d, player, ret);
	// sleep(5);
	return (0);
}