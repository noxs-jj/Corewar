/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:35:40 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/09 14:29:39 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (src > dest)
		ft_memcpy(s1, s2, n);
	else
	{
		while (n > 0)
		{
			dest[n - 1] = src[n - 1];
			n--;
		}
	}
	return (s1);
}
