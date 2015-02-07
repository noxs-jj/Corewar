/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:37:29 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/06 15:37:30 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm_compil.h"

int	main(int ac, char **av)
{
	t_asm	*d;

	if (ac != 2)
	{
		ft_putendl_fd(ERR_NBR_ARGS, 2);
		return (-1);
	}
	if (init_start(av) < 0)
	{
		ft_putendl_fd(ERR_INIT_FAILED, 2);
		return (-1);
	}




	d = getASMdata();
	/* END */
	close(d->fdSource);
	close(d->debugg);
	return (0);
}
