/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:19:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/03/16 14:17:01 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int	read_prog_comment(t_data *d, int fd, t_header *prog)
{
	char buff[BUFFSIZE];
	int		ret;
	int		index;

	(void)d;
	index = 0;
	if (lseek(fd, 135 - ft_strlen(prog->prog_name), SEEK_CUR) < 0)
		return (-1);
	ft_bzero(buff, BUFFSIZE);
	while ((ret = read(fd, buff, BUFFSIZE)) > 0 && index + 1 < COMMENT_LENGTH + 1)
	{
		if (buff[0] == 0)
			return (0);
		ft_strncpy(&prog->comment[index], buff, 1);
		index += 1;
		ft_bzero(buff, BUFFSIZE);
	}
	return (ret);
}

static int	checkMagic(t_data *d, int fd)
{
	char buff[16];
	char cmp[16];
	int ret;

	(void)d;
	ft_bzero(buff, 16);
	ft_bzero(cmp, 16);
	if ((ret = read(fd, buff, 4)) < 0)
		return (-1);
	ft_put_hex_nbr(buff[0], (unsigned char (*)[])cmp);
	ft_put_hex_nbr(buff[1], (unsigned char (*)[])&cmp[2]);
	ft_put_hex_nbr(buff[2], (unsigned char (*)[])&cmp[4]);
	ft_put_hex_nbr(buff[3], (unsigned char (*)[])&cmp[6]);
	if (ft_strcmp(COREWAR_EXEC_MAGIC, (char *)cmp) != 0)
		return (-1);
	return (0);
}

static int	read_prog_name(t_data *d, int fd, t_header *prog)
{
	char buff[BUFFSIZE];
	int		ret;
	int		index;

	index = 0;
	if (checkMagic(d, fd) < 0)
		return (print_error(INV_FILE));
	ft_bzero(buff, BUFFSIZE);
	while ((ret = read(fd, buff, BUFFSIZE)) > 0 && index + 1 < PROG_NAME_LENGTH + 1)
	{
		if (buff[0] == 0)
			return (read_prog_comment(d, fd, prog));
		ft_strncpy(&prog->prog_name[index], buff, 1);
		index += 1;
		ft_bzero(buff, BUFFSIZE);
	}
	return (-1);
}

static int	read_file(t_data *d, int fd, t_header *prog)
{
	char	buff[BUFFSIZE];
	int		ret;
	int 	index;
	char	str[3];

	index = 0;
	if (read_prog_name(d, fd, prog) < 0 || lseek(fd, 2192, SEEK_SET) < 0)
		return (-1);
	ft_bzero(buff, BUFFSIZE);
	ft_bzero(str, 3);
	while ((ret = read(fd, buff, BUFFSIZE)) > 0)
	{
		ft_put_hex_nbr(buff[0], (unsigned char (*)[])&str);
		ft_strncpy((char *)&prog->prog[index], str, 2);
		index += 2;
		prog->prog_size += 2;
		if (prog->prog_size > CHAMP_MAX_SIZE)
			return (print_error("Champions too big"));
		ft_bzero(buff, BUFFSIZE);
		ft_bzero(str, 3);
	}
	prog->prog_size /= 2;
	prog->alive = true;
	prog->reg[1][REG_SIZE - 1] = prog->number;
	if (ret == -1)
		return (print_error(ERR_READ));
	return (ret);
}

int		read_files(t_data *d)
{
	t_header *tmp;
	int		fd;

	tmp = d->prog;
	while (tmp != NULL)
	{
		if ((fd = open(tmp->filename, O_RDONLY)) < 0)
			return (print_error(ERR_FILE));
		if (read_file(d, fd, tmp) < 0)
		{
			close(fd);
			return (print_error(ERR_READ));
		}
		close(fd);
		tmp = tmp->next;
	}
	d->players++;
	return (0);
}
