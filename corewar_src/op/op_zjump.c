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

	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = get_op_args(d, player)) < 0)
		return (ret);
	if (player->carry == 0)
		pc_advance(d, player, ret);
	else
	{
		result = get_int_from_dec((char *)player->opArgs[0], T_LAB);
		if (player->opArgs[0][T_LAB - 2] >= 240)
			result = result - 65536;
		result = get_arg_modulo(result - 1, IDX_MOD);
		pc_advance(d, player, result);
	}
	return (0);
}
