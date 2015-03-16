/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getOpArgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:36:26 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/16 14:35:05 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewarOpTab.h"


static void getValue(t_header *player, int argNbr, int *index, int len)
{
	t_case * arg;
	int i;
	int tmp;

	i = 0;

	// writeL("----args-----");
	if (len == DIR && op_tab[player->nextOp].has_idx == 1)
		len = 2;
	tmp = T_LAB - len;
	while (i < len)
	{
		arg = ((player->PC) + *index + 1 + op_tab[player->nextOp].has_pcode);
		// ft_strncpy(&player->opArgs[argNbr][i * 2], arg->hex, 2);
		player->opArgs[argNbr][tmp] = ft_hex2intdec(arg->hex);
		writeL("[getValue] arg:");
		writeL(ft_itoa(argNbr));
		writeL(arg->hex);
		writeL(ft_itoa(ft_hex2intdec(arg->hex)));
		writeL(ft_itoa(player->opArgs[argNbr][tmp]));
		// sleep(1);
		// writeL(arg->hex);
		// writeL(&player->opArgs[argNbr][i * 2]);
		(*index)++;
		tmp++;
		i++;
	}
}


static void clear_arg(t_header *prog)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_bzero(prog->opArgs[i], T_LAB);
		i++;
	}
}

/*
** read Op args and put them in d->prog[player].opArgs
** must correct return (index) value
*/


int		getOpArgs(t_data *d, t_header *prog)
{
	int index;
	int i;
	t_case *args;

	i = 0;
	clear_arg(prog);
	// ft_bzero(prog->opArgs, T_LAB * 4 * sizeof(char));
	index = 0;

	// writeL("getOpArgs");
	// writeL(op_tab[prog->nextOp].name);
	// writeL("needed args");
	// writeL(ft_itoa(op_tab[prog->nextOp].nb_params));
	// writeL("codage");
	writeL(prog->codage);
	//sleep(1);
	while (i < op_tab[prog->nextOp].nb_params)
	{
		if (ft_strncmp(&prog->codage[i * 2], "01", 2) == 0)
			getValue(prog, i, &index, REG);
		else if (ft_strncmp(&prog->codage[i * 2], "10", 2) == 0)
			getValue(prog, i, &index, DIR);
		else if (ft_strncmp(&prog->codage[i * 2], "11", 2) == 0)
		{
			getValue(prog, i, &index, IND);
			// writeL("get op arg 11");
			// writeL(ft_itoa(i));
			// writeL(prog->opArgs[i]);
		}
		else if (i + 1 == op_tab[prog->nextOp].nb_params)
		{
			index += op_tab[prog->nextOp].has_pcode;
			return (index);
		}
		else
			return (-1);
		i++;
	}
	// writeL("get op args return");
	// sleep(5);
	// writeL("get op arg");
	// writeL(prog->opArgs[0]);
	index += op_tab[prog->nextOp].has_pcode;
	return (index);
}
