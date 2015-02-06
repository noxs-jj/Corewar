/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 10:57:13 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/15 11:39:52 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest;

	if (b != NULL)
	{
		i = 0;
		dest = b;
		while (i < len)
		{
			dest[i] = (unsigned char)c;
			i++;
		}
		return (dest);
	}
	else
		return (b);
}
