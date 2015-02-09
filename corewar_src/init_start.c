/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 11:55:15 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/09 13:30:23 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		init_start(t_data *d, int ac, char **av)
{
	if (ac < 3 || ac > MAX_ARGS_NUMBER)
	{
		ft_putendl_fd(ERR_PARAM, 2);
		return (-1);
	}
	if (LOG == 1)
	{
		d->fdDebugg = open(PATH_DEBUGG, O_WRONLY|O_CREAT|O_TRUNC, 0777);
		if (d->fdDebugg < 0)
		{
			ft_putendl_fd(ERR_FILE_DEBUGG, 2);
			return (-1);
		}
	}
	return (0);
}