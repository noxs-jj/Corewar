/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 13:11:47 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** OK
** T_DIR
** has idx
*/

int		op_zjump(t_data *d, t_header *player)
{
	int		ret;
	int		result;

	writeL("---zjump---");
	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = getOpArgs(d, player)) < 0)
		return (ret);
	if (player->carry == 0)
		pcAdvance(d, player, ret);
	else
	{
		result = get_int_from_dec((char *)player->opArgs[0], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			result = result - 65536;
		result = get_arg_modulo(result - 1, IDX_MOD);
		pcAdvance(d, player, result);
	}
	return (0);
}


/*

int		op_zjump(t_data *d, t_header *player)
{
	int		ret;
	int		result;

	writeL("---zjump---");
	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	// writeL(player->codage);
	// sleep(10);
	if ((ret = getOpArgs(d, player)) < 0)
		return (ret);
	if (player->carry == 0)
	{
		// writeL("carry == 0");
		// writeL(ft_itoa(ret));
		pcAdvance(d, player, ret);
	}
	else
	{
		// writeL("carry == 1");
		// writeL(player->opArgs[0]);
		// writeL(ft_itoa((int)(ft_hex2intdec(player->opArgs[0]) & (1 << 15))));
		// writeL(ft_itoa((1 << 15))));

		result = get_arg_int(player->opArgs[0]);
		result = get_arg_modulo(result - 1, IDX_MOD); // need -2 in result < 0 and -1 in result >0
		pcAdvance(d, player, result);
		// if (player->opArgs[0][0] == 'f')
		// {
		// 	writeL("adv < 0");
		// 	pcAdvance(d, player, (int)(ft_hex2Dec(player->opArgs[0]) - ft_hex2Dec(tmp) - 2) % -IDX_MOD);
		// }
		// else
		// {
		// 	writeL("adv > 0");
		// 	pcAdvance(d, player, ((ft_hex2Dec(player->opArgs[0]) - 1) %IDX_MOD));
		// }
		// usleep(10000);
	}
	return (0);
}

*/
