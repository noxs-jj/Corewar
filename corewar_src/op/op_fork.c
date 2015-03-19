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

#include "../../includes/corewar_op_tab.h"

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
	if ((ret = get_op_args(d, player)) < 0)
		return (ret);
	result = get_int_from_dec((char *)player->op_args[0], T_LAB);
	if (player->op_args[0][T_LAB - 2] >= 240)
		result = result - 65536;
	if (add_prog(d, new_prog(player->number)) < 0)
		return (-1);
	d->players++;
	prog = last_prog(d);
	copy_prog(d, player, prog);
	result = get_arg_modulo(result - 1, IDX_MOD);
	pc_advance(d, prog, result);
	pc_advance(d, player, ret);
	return (0);
}
