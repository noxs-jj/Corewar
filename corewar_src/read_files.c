/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:19:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/12 17:19:10 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int	read_prog_comment(t_data *d, int fd, int number)
{
	char buff[BUFFSIZE];
	int		ret;
	int		index;

	index = 0;
	if (lseek(fd, 135 - ft_strlen(d->prog[number].prog_name), SEEK_CUR) < 0)// 140, SEEK_SET
		return (-1);
	ft_bzero(buff, BUFFSIZE);
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
	if (lseek(fd, 4, SEEK_CUR) < 0)
		return (-1);
	ft_bzero(buff, BUFFSIZE);
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
	if (read_prog_name(d, fd, number) < 0)
		return (-1);
	if (lseek(fd, 2192, SEEK_SET) < 0) // 2192
		return (-1);
	ft_bzero(buff, BUFFSIZE);
	ft_bzero(str, 3);
	while ((ret = read(fd, buff, BUFFSIZE)) > 0 && (index + 2) < MEM_SIZE / 6) // read prog only
	{
		ft_putHexNbr(buff[0], &str);
		strncpy(&d->prog[number].prog[index], str, 2);
		index += 2;
		ft_bzero(buff, BUFFSIZE);
		ft_bzero(str, 3);
	}
	// ft_putchar('\n');
	// ft_putendl(d->prog[number].prog_name);
	// ft_putchar('\n');
	// ft_putendl(d->prog[number].comment);
	// ft_putchar('\n');
	// ft_putendl(d->prog[number].prog);
	// ft_putchar('\n');
	// ft_putchar('\n');
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