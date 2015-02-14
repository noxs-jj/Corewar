/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:15:30 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/14 19:44:30 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "asm_fn.h"
#include "op.h"

static int	check_file(t_file *file, const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 3 || filename[len - 2] != '.' || filename[len - 1] != 's')
		asm_error("The file doesn't end with .s.\n");
	if (!(file->fd_s = open(filename, O_RDONLY)))
		asm_error("Couldln't open the .s file\n");
	file->name_s = ft_strdup(filename);
	if (!(file->name_cor = (char *)ft_memalloc(sizeof(file->name_s))))
		asm_error("Malloc failed.\n");
	ft_strncpy(file->name_cor, file->name_s,
		ft_strstr(file->name_s, ".s") - file->name_s);
	ft_strcat(file->name_cor, ".cor");
	//if (!(file->fd_cor = open(file->name_cor, O_WRONLY | O_CREAT, 0644)))
	//	asm_error("Couldln't create the .cor file\n");
	return (EXIT_SUCCESS);
}

static void	init_file(t_file *file)
{
	file->header.magic = COREWAR_EXEC_MAGIC;
	ft_bzero(file->header.prog_name, PROG_NAME_LENGTH + 1);
	file->header.prog_size = 0;
	ft_bzero(file->header.comment, COMMENT_LENGTH + 1);
	file->lines = NULL;
	file->lines = NULL;
	file->name_s = NULL;
	file->name_cor = NULL;
	file->size = 0;
	file->nb_line = 0;
	file->fd_s = -1;
	file->fd_cor = -1;
}

static void	print_header(t_header *header, char *s_file, char *cor_file)
{
	ft_putstr("Assembling ");
	ft_putstr_color(s_file, COL_LIGHT_YELLOW);
	ft_putendl(":");
	ft_putchar('\t');
	ft_putstr("Name:      ");
	ft_color_switch_fd(COL_LIGHT_RED, 1);
	ft_putendl(header->prog_name);
	ft_putchar('\t');
	ft_putstr_color("Comment:   ", COL_RESET);
	ft_color_switch_fd(COL_LIGHT_RED, 1);
	ft_putendl(header->comment);
	ft_putstr_color(cor_file, COL_LIGHT_YELLOW);
	ft_putstr(" successfully created!\n");
	return ;
}

int			main(int ac, char **av)
{
	t_file	*file;

	if (ac == 1)
		asm_error("No file entered. Use: ./asm filename.\n");
	else if (ac > 2 && ft_strcmp(av[ac - 1], "leaks"))
		asm_error("Too many files entered. Use: ./asm filename.\n");
	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (EXIT_FAILURE);
fprintf(stderr, "\nTEST0 - BEGIN\n");
	init_file(file);
fprintf(stderr, "\nTEST1 - INIT OK\n");
	if (check_file(file, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
fprintf(stderr, "\nTEST2 - CHECK OK\n");
	if (read_file(file) == EXIT_FAILURE)
		asm_error("Failed to read the file.\n");
fprintf(stderr, "\nTEST3 - READ OK\n");
	if (parse_file(file) == EXIT_FAILURE)
	{
		print_detailed_error(file, av[1]);
		exit_asm(file);
		return (EXIT_SUCCESS);
	}
fprintf(stderr, "\nTEST4 - TOKENIZE OK\n");
	if (convert_file(file) == EXIT_SUCCESS)
	{
fprintf(stderr, "\nTEST5 - CONVERT OK\n");
		write_cor(file);
fprintf(stderr, "\nTEST6 - WRITE OK\n");
		print_header(&(file->header), av[1], file->name_cor);
	}
	else
		print_detailed_error(file, av[1]);
	//prepare to exit but doesnt exit itself
	exit_asm(file);

	//TODO: virer
	if (!ft_strcmp(av[ac - 1], "leaks"))
		while (42);
	return (EXIT_SUCCESS);
}
