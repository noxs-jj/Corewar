/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 10:19:16 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/01/09 14:31:48 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static size_t	ft_check_line(char *str, char **end, char **line)
{
	size_t	i;

	i = 0;
	if (ft_strchr(str, '\n') != NULL)
	{
		*end = ft_strdup(ft_strchr(str, '\n') + 1);
		while (str[i] != '\n')
			i++;
		str[i] = '\0';
		*line = str;
		return (1);
	}
	return (0);
}

static int		ft_check_end(char **str, char **buf, char *rest)
{
	char	*tmp;

	if (rest == NULL)
	{
		tmp = *str;
		*str = ft_strjoin(tmp, *buf);
		ft_memdel((void **)buf);
		return (1);
	}
	if (rest != NULL)
	{
		tmp = rest;
		*str = ft_strjoin(tmp, *buf);
		ft_memdel((void **)buf);
		return (0);
	}
	return (-1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*end = NULL;
	char		*str;
	char		*buf;
	size_t		ret;
	char		*tmp;

	ret = 1;
	str = ft_strnew(BUFF_SIZE);
	while (ret > 0)
	{
		buf = ft_strnew(BUFF_SIZE);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		tmp = end;
		if (!ft_check_end(&str, &buf, tmp))
			ft_memdel((void**)&end);
		if (ft_check_line(str, &end, line) == 1)
			return (1);
	}
	*line = str;
	return (0);
}
