/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:20:33 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/07 13:41:05 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int main(int ac, char **av)
{
	int		fdDebugg;

	if (ac < 3 || ac > 9)
		ft_putendl_fd(ERR_PARAM, 2);
	if (1 == LOG)
	{
		fdDebugg = open(PATH_DEBUGG, O_WRONLY || O_CREAT || O_APPEND);
		if (fdDebugg < 0)
		{
			ft_putendl_fd(ERR_FILE_DEBUGG, 2);
			return (-1);
		}
	}

	close(fdDebugg);
	return (0);
}