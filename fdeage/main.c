/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:15:30 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 17:29:44 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <Stdlib.h>
#include "asm.h"
#include "asm_fn.h"
#include "op.h"

static int	check_file(t_file *file, const char *filename)
{
	fprintf(stderr, "TEST1 - %s end=%s\n", filename, ft_strsub(filename, ft_strlen(filename) - 2, 2));
	if (ft_strcmp(ft_strsub(filename, ft_strlen(filename) - 2, 2), ".s") != 0)
		asm_error("The file doesn't end with .s.\n");
	if (!(file->fd_s = open(filename, O_RDONLY)))
		asm_error("Couldln't open the .s file\n");
	file->name_s = ft_strdup(filename);
	if (!(file->name_cor = (char *)ft_memalloc(sizeof(file->name_s))))
		asm_error("Malloc failed.\n");
	ft_strcpy(file->name_cor, ft_strsub(file->name_s, 0
		, ft_strstr(file->name_s, ".s") - file->name_s));
	ft_strcat(file->name_cor, ".cor");
	fprintf(stderr, "TEST1 - s: %s cor: %s\n", file->name_s, file->name_cor);
	if (!(file->fd_cor = open(file->name_cor
		, O_WRONLY | O_CREAT | O_EXCL, 0644)))
		asm_error("Couldln't create the .cor file\n");
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

int     	main(int ac, char **av)
{
	t_file	*file;

    if (ac == 1)
		asm_error("No file entered. Use: ./asm filename.\n");
	else if (ac > 2)
		asm_error("Too many files entered. Use: ./asm filename.\n");
	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (EXIT_FAILURE);
	fprintf(stderr, "\nTEST0 - BEGIN\n");
	init_file(file);
	fprintf(stderr, "\nTEST1 - INIT OK\n");
	if (check_file(file, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fprintf(stderr, "\nTEST2 - CHECK OK\n");
	read_file(file);
	fprintf(stderr, "\nTEST3 - READ OK\n");
	parse_file(file);
	fprintf(stderr, "\nTEST4 - PARSE OK\n");
	convert_file(file);
	fprintf(stderr, "\nTEST5 - CONVERT OK\n");
/*
	if (analyse_parsing(root) == EXIT_SUCCESS)
	{
		convert_file(root);
		print_file(root, fd_cor);
	}
	list_free(&root);
*/
	write_cor(file);
	fprintf(stderr, "\nTEST6 - CONVERT OK\n");
	exit_asm(file);
	fprintf(stderr, "\nTEST7 - EXIT OK\n");
	return (EXIT_SUCCESS);
}
