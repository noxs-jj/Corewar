/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_op_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 15:20:27 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/26 14:26:09 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewarOpTab.h"

/*
** Read OP Code, convert it into binary (8 chars)
*/
static int	read_op_code_2(t_header *prog, t_case *args)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (!(args->hex[1] >= 'a' && args->hex[1] <= 'f')
			&& !(args->hex[1] >= '0' && args->hex[1] <= '9'))
			return (-1);
		if (bin_tab[i].hex == args->hex[1])
			ft_strncpy(&prog->codage[4], bin_tab[i].bin, 4);
		i++;
	}
	return (0);
}

int			read_op_code(t_data *d, t_header *prog)
{
	int		i;
	t_case	*args;

	(void)d;
	args = ((prog->pc) + 1);
	ft_bzero(prog->codage, 9);
	i = 0;
	while (i < 16)
	{
		if (!(args->hex[0] >= 'a' && args->hex[0] <= 'f')
			&& !(args->hex[0] >= '0' && args->hex[0] <= '9'))
			return (-1);
		if (bin_tab[i].hex == args->hex[0])
			ft_strncpy(prog->codage, bin_tab[i].bin, 4);
		i++;
	}
	if (read_op_code_2(prog, args) < 0)
		return (-1);
	return (0);
}
