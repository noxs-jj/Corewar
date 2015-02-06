/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 10:15:01 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/15 10:55:53 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*tmp;

	if (s != NULL && f != NULL)
	{
		i = 0;
		tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		while (s[i] != '\0')
		{
			tmp[i] = f(s[i]);
			i++;
		}
		return (tmp);
	}
	else
		return (NULL);
}
