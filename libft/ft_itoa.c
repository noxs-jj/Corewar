/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 12:35:24 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/25 15:26:19 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_nbrlen(int f)
{
	int	i;

	i = 0;
	if (f < 0)
	{
		i++;
		f = f * (-1);
	}
	while (f != 0)
	{
		f = f / 10;
		i++;
	}
	return (i);
}

static char	*ft_putnbr_char(long f)
{
	char	*tmp;
	int		i;
	int		negative;

	negative = 0;
	i = ft_nbrlen(f);
	tmp = (char *)malloc(sizeof(tmp) * i + 1);
	tmp[i] = '\0';
	if (f < 0)
	{
		negative = 1;
		f = f * (-1);
	}
	while (i > 0)
	{
		tmp[i - 1] = (f % 10) + '0';
		f = f / 10;
		i--;
	}
	if (negative == 1)
		tmp[i] = '-';
	return (tmp);
}

char		*ft_itoa(int n)
{
	char	*tmp;
	long	f;

	f = n;
	if (n != 0)
	{
		tmp = ft_putnbr_char(f);
		return (tmp);
	}
	if (n == 0)
	{
		tmp = "0";
		return (tmp);
	}
	return (NULL);
}
