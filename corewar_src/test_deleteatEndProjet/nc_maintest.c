/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_maintest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:01:42 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/09 15:01:43 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"
#include "../../includes/render.h"

int	main(void)
{
	t_data *d = getData();

	ft_putstr("1\n");
	renderInit(d);
	ft_putstr("2\n");
	renderDraw(d);
	while (1)
		;
	ft_putstr("3\n");
	renderInit(d);
	ft_putstr("4\n");

	return (0);
}
