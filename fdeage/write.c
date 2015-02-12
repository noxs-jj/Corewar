/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:13:52 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/12 19:27:02 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	write_cor(t_file *file)
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
