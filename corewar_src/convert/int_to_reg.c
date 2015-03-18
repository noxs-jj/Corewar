/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:54:24 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 15:54:25 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewarOpTab.h"

void	int_to_reg(t_data *d, t_header *player, int n, int reg)
{
	char	str[(REG_SIZE * 2) + 1];

	ft_bzero(str, (REG_SIZE * 2) + 1);
	nbr2hex((unsigned int)n, (unsigned char (*)[])&str);
	str_to_reg(d, player, reg, str);
}