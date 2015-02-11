/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:19:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/11 16:27:30 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
# include <stdio.h>

// afficher 0 si le char est seul

void	getHexa(char *str[2], unsigned char n)
{
	int	x;

	x = 0;
	while(n >= 16)
	{
		if (n % 16 < 10)
			(*str)[x] = n % 16 + '0';
		else
		{
			if ((n % 16) == 10)
				(*str)[x] = 'a';
			else if ((n % 16) == 11)
				(*str)[x] = 'b';
			else if ((n % 16) == 12)
				(*str)[x] = 'c';
			else if ((n % 16) == 13)
				(*str)[x] = 'd';
			else if ((n % 16) == 14)
				(*str)[x] = 'e';
			else if ((n % 16) == 15)
				(*str)[x] = 'f';
		}
		n = n / 16;
		x++;
	}
}

void	ft_putnbrhexaa(unsigned char n, bool test)
{
	if (n < 10 && test == true)
		ft_putchar('0');
	if (n >= 16)
		ft_putnbrhexaa(n / 16, false);
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
	int		print = 1;
	char	str[2];

	ft_strclr(buff);
	while ((ret = read(fd, buff, BUFFSIZE)) > 0)
	{
		// printf("%d\n", buff[0]);
		// getHexa(&str, 62);
		// ft_putstr(str);
		ft_putnbrhexaa(buff[0], true);
		if (print % 2 == 0)
		{
			print = 0;
			ft_putchar(' ');
		}
		print++;
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