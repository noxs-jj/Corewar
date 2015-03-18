/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 11:46:06 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/23 11:46:07 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	arg_dump(t_data *d)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_putstr((char *)d->map[i].hex);
		ft_putchar(' ');
		i++;
		if (i % 32 == 0)
			ft_putchar('\n');
	}
}
