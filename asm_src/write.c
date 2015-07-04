/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:13:52 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/13 13:03:44 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"
#include "asm_fn.h"
#include "libft.h"

static void	write_magic(int fd)
{
	int	magic;

	magic = COREWAR_EXEC_MAGIC;
	magic = ((magic >> 24) & 0xff) | ((magic << 8) & 0xff0000) |
		((magic >> 8) & 0xff00) | ((magic << 24) & 0xff000000);
	write(fd, (char *)&magic, 4);
}

static void	write_name_comment(int fd, t_header header)
{
	char	buf[8];

	ft_bzero(buf, 8);
	write(fd, header.prog_name, PROG_NAME_LENGTH);
	write(fd, buf, 8);
	write(fd, header.comment, COMMENT_LENGTH);
	write(fd, buf, 4);
}

static void	write_text_section(t_file *file)
{
	t_list	*tmp;

	tmp = file->lines;
	while (tmp)
	{
		if (LINE->bytecode)
			write(file->fd_cor, LINE->bytecode, LINE->code_len);
		tmp = tmp->next;
	}
}

void		write_cor(t_file *file)
{
	if (file->nb_line == 0)
		asm_error("No instruction in the file.\n");
	if (!(file->fd_cor = open(file->name_cor,
				O_WRONLY | O_CREAT | O_TRUNC, 0644)))
		asm_error("Couldln't create the .cor file.\n");
	write_magic(file->fd_cor);
	write_name_comment(file->fd_cor, file->header);
	write_text_section(file);
}
