/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:41:47 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/25 10:58:34 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *s1, void const *s2, size_t n)
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
			i++;
		}
	}
	return (dest);
}
