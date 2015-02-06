/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:20:13 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/09 14:32:03 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_next_char(char *c)
{
	size_t	i;

	i = 0;
	while ((c[i] == ' ' || c[i] == '\n' || c[i] == '\t') && c[i] != '\0')
	{
		i++;
	}
	if (c[i] == '\0')
		return (0);
	return (1);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	char	*tmp;

	i = 0;
	k = 0;
	if (s != NULL)
	{
		tmp = ft_strnew(ft_strlen(s) + 1);
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		while (s[i + k] != '\0' && (ft_next_char(&((char *)s)[i + k]) == 1))
		{
			tmp[k] = s[k + i];
			k++;
		}
		tmp[k] = '\0';
		return (tmp);
	}
	return (NULL);
}
