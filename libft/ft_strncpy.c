/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:58:10 by jmoiroux          #+#    #+#             */
/*   Updated: 2013/12/07 16:36:40 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	if (i != n)
		s1[i] = '\0';
	return (s1);
}
