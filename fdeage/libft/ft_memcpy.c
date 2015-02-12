/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:58:00 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/21 12:58:11 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	test;

	if (!n || !s1 || !s2)
		return (NULL);
	i = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	test = (unsigned char)c;
	while (i < n)
	{
		*(str1 + i) = *(str2 + i);
		if (*(str2 + i) == test)
			return (str1 + i + 1);
		++i;
	}
	return (NULL);
}

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*s3;
	char	*s4;

	if (!s1 || !s2)
		return (s1);
	s3 = (char *)s1;
	s4 = (char *)s2;
	while (n--)
		*s3++ = *s4++;
	return (s1);
}
