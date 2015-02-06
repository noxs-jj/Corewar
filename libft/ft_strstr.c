/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:07 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/02 15:55:57 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	y = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s2[y] == s1[i])
		{
			while ((s2[y] == s1[i + y]) && (s2[y] != '\0'))
			{
				y++;
			}
			if (y == ft_strlen(s2))
				return ((char *)s1 + i);
			y = 0;
		}
		i++;
	}
	return (NULL);
}
