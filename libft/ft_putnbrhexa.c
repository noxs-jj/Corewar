/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 15:05:34 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/04/18 15:06:11 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbrhexa(unsigned long n)
{
	if (n >= 16)
		ft_putnbrhexa(n / 16);
	if ((n % 16) < 10)
		ft_putchar((n % 16) + '0');
	else
	{
		if ((n % 16) == 10)
			ft_putchar('a');
		else if ((n % 16) == 11)
			ft_putchar('b');
		else if ((n % 16) == 12)
			ft_putchar('c');
		else if ((n % 16) == 13)
			ft_putchar('d');
		else if ((n % 16) == 14)
			ft_putchar('e');
		else if ((n % 16) == 15)
			ft_putchar('f');
	}
}
