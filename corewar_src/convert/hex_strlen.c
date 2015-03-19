/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 14:43:08 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/18 14:43:10 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar_op_tab.h"

int		hex_strlen(unsigned char *str, int size)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (i < size && str[i] == 0)
		i++;
	while (i < size)
	{
		len++;
		i++;
	}
	return (len);
}
