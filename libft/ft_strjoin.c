/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:06:09 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/02 15:45:32 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] != '\0')
		{
			tmp[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			tmp[i] = s2[j];
			i++;
			j++;
		}
		i++;
		tmp[i] = '\0';
	}
	return (tmp);
}
