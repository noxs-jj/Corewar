/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:19:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/11 18:36:15 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_putnbrhexaa(unsigned char n, bool test, int index, char (*str)[])
{
	if (n < 10 && test == true)
	{
		(*str)[index] = '0';
		index--;
	}
	if (n >= 16)
		ft_putnbrhexaa(n / 16, false, index - 1, str);
	if ((n % 16) < 10)
		(*str)[index] = (n % 16) + '0';
	else
	{
		if ((n % 16) == 10)
			(*str)[index] = 'a';
		else if ((n % 16) == 11)
			(*str)[index] = 'b';
		else if ((n % 16) == 12)
			(*str)[index] = 'c';
		else if ((n % 16) == 13)
			(*str)[index] = 'd';
		else if ((n % 16) == 14)
			(*str)[index] = 'e';
		else if ((n % 16) == 15)
			(*str)[index] = 'f';
	}
}

static int	read_prog_comment(t_data *d, int fd, int number)
{
	char buff[BUFFSIZE];
	int		ret;
	int		index;

	index = 0;
	if (lseek(fd, 140, SEEK_SET) < 0)
		return (-1);
	ft_bzero(buff, BUFFSIZE);
	ft_bzero(d->prog[number].comment, COMMENT_LENGTH + 1);
	while ((ret = read(fd, buff, BUFFSIZE)) > 0 && index + 1 < COMMENT_LENGTH + 1)
	{
		if (buff[0] == 0)
			return (0);
		strncpy(&d->prog[number].comment[index], buff, 1);
		index += 1;
		ft_bzero(buff, BUFFSIZE);
	}
	return (ret);
}

static int	read_prog_name(t_data *d, int fd, int number)
{
	char buff[BUFFSIZE];
	int		ret;
	int		index;

	index = 0;
	if (lseek(fd, 4, SEEK_SET) < 0)
		return (-1);
	ft_bzero(buff, BUFFSIZE);
	ft_bzero(d->prog[number].prog_name, PROG_NAME_LENGTH + 1);
	while ((ret = read(fd, buff, BUFFSIZE)) > 0 && index + 1 < PROG_NAME_LENGTH + 1)
	{
		if (buff[0] == 0)
			return (read_prog_comment(d, fd, number));
		strncpy(&d->prog[number].prog_name[index], buff, 1);
		index += 1;
		ft_bzero(buff, BUFFSIZE);
	}
	return (-1);
}

static int	read_file(t_data *d, int fd, int number)
{
	char buff[BUFFSIZE];
	int		ret;
	int 	index;
	char	str[3];

	index = 0;
	//must read .name and .comment
	if (read_prog_name(d, fd, number) < 0)
		return (-1);
	if (lseek(fd, 2192, SEEK_SET) < 0)
		return (-1);

	ft_bzero(buff, BUFFSIZE);
	ft_bzero(str, 3);
	ft_bzero(d->prog[number].prog, MEM_SIZE / 6);
	while ((ret = read(fd, buff, BUFFSIZE)) > 0 && (index + 2) < MEM_SIZE / 6) // read prog only
	{
		ft_putnbrhexaa(buff[0], true, 1, &str);
		strncpy(&d->prog[number].prog[index], str, 2);
		// ft_putstr(str);
		index += 2;
		ft_bzero(buff, BUFFSIZE);
		ft_bzero(str, 3);
	}
	if (ret == -1 || (index + 2) >= MEM_SIZE / 6)
		return (-1);
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
		if (read_file(d, fd, i) < -1)
			return (print_error(ERR_READ));
		close(fd);
		i++;
	}
	return (0);
}