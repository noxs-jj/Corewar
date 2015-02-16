/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getOpArgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:36:26 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/16 18:44:33 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewarOpTab.h"

int		getOpArgs(t_data *d, int player)
{
	int argNbr;
	int i;
	t_case *args;

	i = 0;
	ft_bzero(d->prog[player].opArgs, T_LAB * 4 * sizeof(char));
	d->prog[player].wait = op_tab[d->prog[player].nextOp].nb_params;
	args = ((d->prog[player].PC) + 2);
	while (i < argNbr)
	{
		if (ft_strncmp(&d->prog[player].codage[i * 2], "01", 2) == 0)
		{
			getValue(&d->prog[player], i, args, T_REG);
			args += T_REG;
		}
		else if (ft_strncmp(&d->prog[player].codage[i * 2], "10", 2) == 0)
		{
			getValue(d->prog[player], i, args, T_IND);
			args += T_IND;
		}
		else if (ft_strncmp(&d->prog[player].codage[i * 2], "11", 2) == 0)
		{
			getValue(d->prog[player], i, args, T_DIR);
			args += T_DIR;
		}
		else if (i + 1 == argNbr)
			return (0);
		else
			return (-1);
		i++;
	}
}

void	getValue(t_header *player, int index, t_case *arg, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_strncpy(player->opArgs[index], (arg + i)->hex, 2);
		i++;
	}
}





// void	getRegValue(t_data *d, int player, int index, t_case *arg)
// {
// 	int i;

// 	i = 0;
// 	while (i < T_REG)
// 	{
// 		ft_strncpy(d->prog[player].opArgs[index], (arg + i)->hex, 2);
// 		i++;
// 	}
// }

// void getIndValue(t_data *d, int player, int index, t_case *arg)
// {
// 	int i;

// 	i = 0;
// 	while (i < T_IND)
// 	{
// 		ft_strncpy(d->prog[player].opArgs[index], (arg + i)->hex, 2);
// 		i++;
// 	}
// }

// void	getDIRValue(t_data *d, int player, int index, t_case *arg)
// {
// 	int i;

// 	i = 0;
// 	while (i < T_DIR)
// 	{
// 		ft_strncpy(d->prog[player].opArgs[index], (arg + i)->hex, 2);
// 		i++;
// 	}
// }