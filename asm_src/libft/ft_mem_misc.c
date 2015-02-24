/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:58:47 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/12 12:43:42 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** do not check if the pointers exists but might check if they are equal...
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;

	if (!s || !n)
		return (NULL);
	s2 = (unsigned char *)s;
	while (n--)
	{
		if (*s2 == (unsigned char)c)
			return ((void *)s2);
		++s2;
	}
	return (NULL);
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n || !s1 || !s2)
		return (0);
	while (--n && *(char *)s1 == *(char *)s2)
	{
		s1 = (char *)s1 + 1;
		s2 = (char *)s2 + 1;
	}
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	register size_t	i;

	if (!dest || !src || dest == src || n == 0)
		return (dest);
	else if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			++i;
		}
	}
	else
	{
		i = n - 1;
		while (i < SIZE_MAX)
		{
			((char *)dest)[i] = ((char *)src)[i];
			--i;
		}
	}
	return (dest);
}
