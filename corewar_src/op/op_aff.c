/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:27:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/17 16:42:04 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

/*
** tested OK
** T_REG
*/

int		op_aff(t_data *d, t_header *player)
{
	int ret;
	char value;
	
	writeL("--- op_aff ---");
	if ((ret = getOpArgs(d, player)) < 0
		|| isValidRegister(get_int_from_dec((char *)player->opArgs[0], T_LAB)) < 0)
		return (ret);
	value = reg_to_int(d, player, get_int_from_dec((char *)player->opArgs[0], T_LAB));
	value = value % 256;
	ft_putstr("Player ");
	ft_putstr(player->prog_name);
	ft_putstr(" OP>aff: [");
	ft_putchar(value);
	ft_putstr("]\n");
	pcAdvance(d, player, ret);
	return (0);
}
