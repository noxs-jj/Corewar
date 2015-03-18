/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:36:26 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/16 14:35:05 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewarOpTab.h"


/*
** read Op args and put them in d->prog[player].opArgs
** must correct return (index) value
*/

static void getValue(t_header *player, int argNbr, int *index, int len)
{
	t_case * arg;
	int i;
	int tmp;

	i = 0;
	if (len == DIR && op_tab[player->nextOp].has_idx == 1)
		len = 2;
	tmp = T_LAB - len;
	while (i < len)
	{
		arg = ((player->PC) + *index + 1 + op_tab[player->nextOp].has_pcode);

		player->opArgs[argNbr][tmp] = ft_hex2intdec(arg->hex);
		(*index)++;
		tmp++;
		i++;
	}
}

static void clear_arg(t_data *d, t_header *prog)
{
	int i;

	(void)d;
	i = 0;
	while (i < 4)
	{
		ft_bzero(prog->opArgs[i], T_LAB);
		i++;
	}
}

int		get_op_args(t_data *d, t_header *prog)
{
	int index;
	int i;

	i = 0;
	clear_arg(d, prog);
	index = 0;
	while (i < op_tab[prog->nextOp].nb_params)
	{
		if (ft_strncmp(&prog->codage[i * 2], "01", 2) == 0)
			getValue(prog, i, &index, REG);
		else if (ft_strncmp(&prog->codage[i * 2], "10", 2) == 0)
			getValue(prog, i, &index, DIR);
		else if (ft_strncmp(&prog->codage[i * 2], "11", 2) == 0)
			getValue(prog, i, &index, IND);
		else if (i + 1 == op_tab[prog->nextOp].nb_params)
		{
			index += op_tab[prog->nextOp].has_pcode;
			return (index);
		}
		else
			return (-1);
		i++;
	}
	index += op_tab[prog->nextOp].has_pcode;
	return (index);
}