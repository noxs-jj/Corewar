/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 17:39:15 by vjacquie         ###   ########.fr       */
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
	char	tmp[DIR + 1];

	ft_memset(tmp, 'f', DIR);
	tmp[DIR] = '\0';

	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, player)) < 0) // check reg valid registre
		return (ret);
	if ((ret = getOpArgs(d, player)) < 0)
	{
		writeL("arg wrong");
		//sleep(5);
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
		//sleep(5);
		return (-1);
	}
	prog = lastProg(d);
	d->players++;
	copyProg(d, player, prog);
	pcAdvance(d, prog, result);
	pcAdvance(d, player, ret);
	return (0);
}