/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_reg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:00:50 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 16:00:51 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	init_reg(t_header *new)
{
	int i;
	
	i = 0;
	while (i < REG_NUMBER + 1)
	{
		ft_bzero(new->reg[i], REG_SIZE);
		i++;
	}
}
