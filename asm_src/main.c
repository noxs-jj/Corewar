/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:15:30 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/27 20:24:27 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "asm_fn.h"
#include "op.h"

/*
** main
** init_file
** check_file
** read_file
** parse_file -> tokenize_line
** convert_file
** write_cor
** print_header
*/

static int	check_file_1(t_file *file, const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 3 || filename[len - 2] != '.' || filename[len - 1] != 's')
		asm_error("The file doesn't end with .s.\n");
	if ((file->fd_s = open(filename, O_RDONLY)) == -1)
		asm_error("Couldln't open the .s file\n");
	if (!(file->name_s = ft_strdup(filename)))
		asm_error("Strdup() failed.\n");
	if (!(file->name_cor = (char *)ft_memalloc(sizeof(file->name_s))))
		asm_error("Malloc() failed.\n");
	ft_strncpy(file->name_cor, file->name_s,
		ft_strstr(file->name_s, ".s") - file->name_s);
	ft_strcat(file->name_cor, ".cor");
	return (EXIT_SUCCESS);
}

static void	init_file(t_file *file)
{
	file->header.magic = COREWAR_EXEC_MAGIC;
	ft_bzero(file->header.prog_name, PROG_NAME_LENGTH + 1);
	file->header.prog_size = 0;
	ft_bzero(file->header.comment, COMMENT_LENGTH + 1);
	file->lines = NULL;
	file->name_s = NULL;
	file->name_cor = NULL;
	file->nb_line = 0;
	file->has_name = 0;
	file->ret = 1;
	file->fd_s = -1;
	file->fd_cor = -1;
	file->options = 0;
	return ;
}

static void	print_header(t_header *header, char *file_s, char *file_cor)
{
	ft_putstr("Assembling ");
	ft_putstr_color(file_s, COL_LIGHT_YELLOW);
	ft_putendl(":");
	ft_putchar('\t');
	ft_putstr("Name:      ");
	ft_color_switch_fd(COL_LIGHT_RED, 1);
	ft_putendl(header->prog_name);
	ft_putchar('\t');
	ft_putstr_color("Comment:   ", COL_RESET);
	ft_color_switch_fd(COL_LIGHT_RED, 1);
	ft_putendl(header->comment);
	ft_putstr_color(file_cor, COL_LIGHT_YELLOW);
	ft_putstr(" successfully created!\n");
	return ;
}

static void	check_asm_params(t_file *file, int ac, char *av[])
{
	if (ac == 1)
		asm_error("No file entered. Use: ./asm filename [-l].\n");
	else if (ac == 3)
	{
		if (!ft_strcmp(av[2], "-l"))
			file->options |= T_OPTION_LEAKS;
		else if (!(av[2][0]) == '-')
			asm_error("Option not recognized. Use: ./asm filename [-l].\n");
		else
			asm_error("Too many files. Use: ./asm filename [-l].\n");
	}
	else if (ac != 2)
		asm_error("Too many files entered. Use: ./asm filename [-l].\n");
	return ;
}

int			main(int ac, char **av)
{
	t_file	*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (EXIT_FAILURE);
	init_file(file);
	check_asm_params(file, ac, av);
	if (check_file_1(file, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (read_file(file) == EXIT_FAILURE)
		asm_error("Failed to read the file.\n");
	if (parse_file(file) == EXIT_FAILURE)
	{
		print_detailed_error(file, av[1]);
		exit_asm(file);
		return (EXIT_FAILURE);
	}
	if (has_name(file) && convert_file(file) == EXIT_SUCCESS)
	{
		write_cor(file);
		print_header(&(file->header), av[1], file->name_cor);
	}
	else
		print_detailed_error(file, av[1]);
	exit_asm(file);
	return (EXIT_SUCCESS);
}
