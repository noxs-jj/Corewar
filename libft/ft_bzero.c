/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:33:08 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/24 15:41:21 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*tmp;

	if (n > 0)
	{
		tmp = s;
		i = 0;
		while (i < n)
		{
			tmp[i] = 0;
			i++;
		}
	}
}
