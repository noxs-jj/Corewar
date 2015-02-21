/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 12:10:21 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/21 12:33:34 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*us1;
// 	unsigned char	*us2;

// 	us1 = (unsigned char *)s1;
// 	us2 = (unsigned char *)s2;
// 	i = 0;
// 	while (us1[i] != '\0' && us2[i] != '\0' && i < n - 1)
// 		i++;
// 	return (us1[i] - us2[i]);
// }


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
