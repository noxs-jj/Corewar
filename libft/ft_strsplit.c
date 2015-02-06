/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:27:35 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/17 12:18:08 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	strlen_word(char const *s, char c)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		y++;
	}
	return (y);
}

static int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			y++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (y);
}

static int	init(char const *s, char c, char ***tab)
{
	size_t nbr_s;

	if (s == NULL)
		return (-1);
	nbr_s = count_word(s, c);
	*tab = (char **)malloc(sizeof(char *) * nbr_s + 1);
	if (tab == NULL)
		return (-1);
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	y;
	size_t	s_len;
	char	**tab;

	if (init(s, c, &tab) == -1)
		return (NULL);
	y = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			tab[y] = ft_strsub(s, i, strlen_word(&s[i], c));
			y++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[y] = '\0';
	return (tab);
}
