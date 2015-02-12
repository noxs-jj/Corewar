/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:57:51 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/03 20:57:59 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s1, int c, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char*)s1;
	while (n--)
		*(s2 + n) = (unsigned char)c;
	return (s1);
}

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}
