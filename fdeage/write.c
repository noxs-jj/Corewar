/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:13:52 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 15:44:25 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static void	write_magic(int fd)
{
	int	magic;

	magic = COREWAR_EXEC_MAGIC;
	//fprintf(stderr, "TEST1 - %d\n", magic);
	magic = ((magic >> 24) & 0xff) | ((magic << 8) & 0xff0000) |
		((magic >> 8) & 0xff00) | ((magic << 24) & 0xff000000);
	//fprintf(stderr, "TEST2 - %d\n", magic);
	write(fd, (char *)&magic, 8);
	return ;
}

static void	write_name_comment(int fd, t_header header)
{
//	size_t			len;

//	len = ft_strlen(header.prog_name);
//	write(fd, header.prog_name, len);
	write(fd, header.prog_name, PROG_NAME_LENGTH);
//	if (len < PROG_NAME_LENGTH)
//		write(fd, header.name + len, PROG_NAME_LENGTH - len);

//	len = ft_strlen(header.comment);
	write(fd, header.comment, COMMENT_LENGTH);
//	write(fd, header.comment, len);
//	if (len < COMMENT_LENGTH)
//		write(fd, header.name + len, COMMENT_LENGTH - len);
	return ;
}


void		write_text_section(t_file *file)
{
	t_list	*tmp;

	tmp = file->lines;
	while (tmp)
	{
		//ft_printhex_fd(LINE->bytecode, file->fd_cor, 0);
		LINE->bytecode = "tito";
		if (LINE->bytecode)
			write(file->fd_cor, LINE->bytecode, ft_strlen(LINE->bytecode));
		//ft_putstr_fd(LINE->bytecode, file->fd_cor);
		fprintf(stderr, "line: %s\n", LINE->bytecode);
		//ft_printhex_fd(LINE->bytecode, file->fd_cor, 0);
		tmp = tmp->next;
	}
}

void		write_cor(t_file *file)
{
	write_magic(file->fd_cor);
	write_name_comment(file->fd_cor, file->header);
	write_text_section(file);
}

