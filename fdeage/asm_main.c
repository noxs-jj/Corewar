/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:15:45 by fdeage            #+#    #+#             */
/*   Updated: 2014/02/02 23:21:30 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "corewar.h"

char	*get_file_name(char *filename)
{
	char	*cor;
	int		i;

	i = 0;
	while (filename[i + 1] && filename[i + 2])
		++i;
	if ((filename[i] != '.') || (filename[i + 1]) != 's')
	{
		ft_putstr("Bad file format: '");
        ft_putstr(filename);
		ft_putstr("'. 'file.s' expected.\n");
		return (NULL);
	}
	if (!(cor = (char *)malloc((ft_strlen(filename) + 3) * sizeof(char))))
		exit(EXIT_FAILURE);
	cor = ft_strncpy(cor, filename, ft_strlen(filename) - 2);
	cor[ft_strlen(filename) - 2] = '\0';
	cor = ft_strcat(cor, ".cor");
	return (cor);
}

int		asm_init(int ac, char **av, t_list *root)
{
	av++;
	if (ac != 2)
		return (EXIT_FAILURE);
	if (!(root->line = (t_line *)malloc(sizeof(t_line))))
		exit(EXIT_FAILURE);
	root->line->str = NULL;
	root->line->line = 0;
	root->prev = NULL;
	root->next = NULL;
	return (EXIT_SUCCESS);
}

void	print_file(t_list *root, int fd_cor)
{
	print_hex(COREWAR_EXEC_MAGIC, fd_cor);
	list_print(root, fd_cor);
}

int		test_open(int *fd_file, char *file, int *fd_cor)
{
	char	*cor;

	*fd_file = open(file, O_RDONLY);
	if ((cor = get_file_name(file)) == NULL)
		return (EXIT_FAILURE);
	*fd_cor = open(cor, O_WRONLY | O_CREAT, 0644);
	free(cor);
	if (*fd_file == -1)
	{
		ft_putstr("No file matching ");
		ft_putstr(file);
		ft_putchar('\n');
		return (EXIT_FAILURE);
	}
	if (*fd_cor == -1)
	{
		ft_putstr("Couldn't create the file: ");
		ft_putstr(cor);
		ft_putchar('\n');
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	int		fd_file;
	int		fd_cor;
	t_list	*root;

	if (!(root = (t_list *)malloc(sizeof(t_list))))
		return (EXIT_FAILURE);
	if (asm_init(ac, av, root) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (test_open(&fd_file, av[1], &fd_cor) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	parse_file(root, fd_file);
	if (analyse_parsing(root) == EXIT_SUCCESS)
	{
		convert_file(root);
		print_file(root, fd_cor);
	}
	list_free(&root);
	return (EXIT_SUCCESS);
}

