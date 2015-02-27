/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidRegister.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 12:09:46 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/27 13:36:10 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		isValidRegister(unsigned int reg)
{
	if (reg >= 0 && reg <= REG_NUMBER)
		return (0);
	else
		return (-1);
}