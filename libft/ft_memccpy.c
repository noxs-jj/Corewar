/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 14:48:51 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/02/05 18:37:54 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	if (s2 != NULL)
	{
		src = s2;
		dest = s1;
		i = 0;
		while (i < n * sizeof(unsigned char))
		{
			dest[i] = src[i];
			if (dest[i] == (unsigned char)c)
				return (dest + i + 1);
			i++;
		}
	}
	return (NULL);
}
