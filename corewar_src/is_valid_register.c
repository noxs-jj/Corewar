/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_register.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 12:09:46 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/27 13:36:10 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		is_valid_register(unsigned int reg)
{
	if (reg <= REG_NUMBER)
		return (0);
	else
		return (-1);
}
