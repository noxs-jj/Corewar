/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getOpArgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:36:26 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/20 11:24:42 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewarOpTab.h"


static void getValue(t_header *player, int argNbr, int *index, int len)
{
	t_case * arg;
	int i;

	i = 0;

	// writeL("----args-----");
	while (i < len)
	{
		arg = ((player->PC) + *index + 1 + op_tab[player->nextOp].has_pcode);
		ft_strncpy(&player->opArgs[argNbr][i * 2], arg->hex, 2);
		// writeL(arg->hex);
		// writeL(&player->opArgs[argNbr][i * 2]);
		(*index)++;
		i++;
	}
}

/*
** read Op args and put them in d->prog[player].opArgs
*/


int		getOpArgs(t_data *d, int player)
{
	int index;
	int i;
	t_case *args;

	i = 0;
	ft_bzero(d->prog[player].opArgs, T_LAB * 4 * sizeof(char));
	index = 0;

	// writeL("getOpArgs");
	// writeL(op_tab[d->prog[player].nextOp].name);
	// writeL("needed args");
	// writeL(ft_itoa(op_tab[d->prog[player].nextOp].nb_params));
	// writeL("codage");
	// writeL(d->prog[player].codage);
	while (i < op_tab[d->prog[player].nextOp].nb_params)
	{
		if (ft_strncmp(&d->prog[player].codage[i * 2], "01", 2) == 0)
		{
			getValue(&d->prog[player], i, &index, T_REG);
			// writeL("after get value arg 0");
			// writeL(d->prog[player].opArgs[0]);
		}
		else if (ft_strncmp(&d->prog[player].codage[i * 2], "10", 2) == 0)
			getValue(&d->prog[player], i, &index, T_DIR);
		else if (ft_strncmp(&d->prog[player].codage[i * 2], "11", 2) == 0)
			getValue(&d->prog[player], i, &index, T_IND);
		else if (i + 1 == op_tab[d->prog[player].nextOp].nb_params)
		{
			// writeL("get op arg");
			// writeL(d->prog[player].opArgs[0]);
			return (index);
		}
		else
			return (-1);
		i++;
	}
	// writeL("get op args return");
	// sleep(5);
	// writeL("get op arg");
	// writeL(d->prog[player].opArgs[0]);
	return (index);
}
