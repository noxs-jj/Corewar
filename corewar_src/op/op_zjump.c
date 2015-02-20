/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/20 16:39:20 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** not tested
** T_DIR
** has idx
*/

int		op_zjump(t_data *d, t_header *player, int id)
{
	int		ret;
	char	tmp[DIR + 1];
	
	ft_memset(tmp, 'f', DIR);
	tmp[DIR] = '\0';
	// writeL("---zjump---");
	// ft_bzero(player->codage, 9);
	// ft_strcpy(player->codage, "10000000");
	// writeL(player->codage);
	// sleep(10);
	if ((ret = getOpArgs(d, id)) < 0)
		return (ret);
	if (player->carry == 0)
	{
		writeL("carry == 0");
		writeL(ft_itoa(ret));
		pcAdvance(d, player, ret);
	}
	else
	{
		writeL("carry == 1");
		writeL(player->opArgs[0]);
		writeL(ft_itoa(ft_hex2Dec(player->opArgs[0]) - ft_hex2Dec(tmp) - 1));
		if (ft_hex2Dec(player->opArgs[0]) - ft_hex2Dec(tmp) - 1 < 0)
			pcAdvance(d, player, (ft_hex2Dec(player->opArgs[0]) - ft_hex2Dec(tmp) - 1) % -IDX_MOD);
		else
			pcAdvance(d, player, (ft_hex2Dec(player->opArgs[0]) - ft_hex2Dec(tmp) - 1) % IDX_MOD);
	}
	return (0);
}