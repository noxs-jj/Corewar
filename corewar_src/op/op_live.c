/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 12:53:46 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

/*
** OK
** T_DIR
*/
int		op_live(t_data *d, t_header *player)
{
	int				ret;
	unsigned int	value;
	t_header		*prog;

	ft_bzero(player->codage, 9);
	ft_strcpy(player->codage, "10000000");
	if ((ret = get_op_args(d, player)) < 0)
		return (ret);
	value = get_int_from_dec((char *)player->op_args[0], T_LAB);
	if ((prog = search_prog(d, value)) != NULL)
	{
		prog->last_live = d->cycle;
		prog->live_nbr++;
		d->lives_current++;
	}
	player->pc->live = 10;
	pc_advance(d, player, ret);
	return (0);
}
