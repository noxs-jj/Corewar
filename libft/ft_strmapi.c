/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:07:08 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/02 15:47:16 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*tmp;

	i = 0;
	s_len = ft_strlen(s);
	tmp = (char *)malloc(sizeof(s) * s_len + 1);
	if ((s != NULL) || (f != NULL))
	{
		while (s[i] != '\0')
		{
			tmp[i] = f(i, s[i]);
			i++;
		}
		return (tmp);
	}
	else
		return (NULL);
}
