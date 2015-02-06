/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:36:53 by jmoiroux          #+#    #+#             */
/*   Updated: 2013/12/07 16:30:44 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n >= 0)
		{
			if (n >= 10)
			{
				ft_putnbr_fd((n / 10), fd);
			}
			ft_putchar_fd((n % 10 + '0'), fd);
		}
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd((-n), fd);
		}
	}
}
