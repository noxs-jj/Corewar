/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:11:22 by jmoiroux          #+#    #+#             */
/*   Updated: 2013/12/13 11:54:14 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_clean_str(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' '
			|| str[i] == '\t'
			|| str[i] == '\n'
			|| str[i] == '\v'
			|| str[i] == '\f'
			|| str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	negative;

	i = ft_clean_str(str);
	result = 0;
	negative = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
		{
			result = result * 10 + str[i] - '0';
			i++;
		}
		return (result * negative);
	}
	return (0);
}
