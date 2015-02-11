/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:19:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/11 13:21:20 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
# include <stdio.h>

// afficher 0 si le char est seul

void	ft_putnbrhexaa(unsigned char n)
{
	if (n >= 16)
		ft_putnbrhexaa(n / 16);
	if ((n % 16) < 10)
		ft_putchar((n % 16) + '0');
	else
	{
		if ((n % 16) == 10)
			ft_putchar('a');
		else if ((n % 16) == 11)
			ft_putchar('b');
		else if ((n % 16) == 12)
			ft_putchar('c');
		else if ((n % 16) == 13)
			ft_putchar('d');
		else if ((n % 16) == 14)
			ft_putchar('e');
		else if ((n % 16) == 15)
			ft_putchar('f');
	}
}

static int	read_file(t_data *d, int fd)
{
	char buff[BUFFSIZE];
	int		ret;

	ft_strclr(buff);
	while ((ret = read(fd, buff, BUFFSIZE)) > 0)
	{
		// printf("%d\n", buff[0]);
		ft_putnbrhexaa(buff[0]);
		// if (ft_isalnum(buff[0]))
		// 	ft_putstr(buff);

		ft_strclr(buff);
	}
	return (ret);


}

int		read_files(t_data *d)
{
	int		i;
	int		fd;

	i = 0;
	while (i <= d->players)
	{
		if ((fd = open(d->prog[i].filename, O_RDONLY)) < 0)
			return (print_error(ERR_FILE));
		if (read_file(d, fd) < -1)
			return (print_error(ERR_READ));
		close(fd);
		i++;
	}
	return (0);
}