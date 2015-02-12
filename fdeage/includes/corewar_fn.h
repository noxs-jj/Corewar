/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_fn.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 16:45:33 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/11 16:47:39 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_FN_H
# define COREWAR_FN_H

# include "corewar.h"
# include "op.h"
# include "libft.h"

/*
** parsing_main
*/

void	push_eol(t_list *root, int nb_line);
void	parse_file_tests(t_list *root, char *line, t_line *new, int nb_line);
void	parse_file(t_list *root, int fd_file);
void	get_others(t_list *root, char *line, t_line *st_line, int nb_line);

/*
** parsing_fn
*/

char	*get_name_comment(char *line);
char	*get_label(char **line);
char	*get_cmd(char **line);
void	get_args(t_list *root, char **par, t_line *new, int nb_line);

/*
** main
*/

char	*get_file_name(char *filename);
int		asm_init(int ac, char **av, t_list *root);
void	print_file(t_list *root, int fd_cor);
int		test_open(int *fd_file, char *file, int *fd_cor);

/*
** list utilities
*/

t_list	*list_new(t_line *line);
void	list_pushback(t_list *begin_list, t_line *line);
void	list_free(t_list **root);
void	list_print(t_list *root, int fd_cor);

/*
** check utilities
*/

void	convert_params(t_list *new, int i);
int		analyse_parsing(t_list *root);

/*
** conversion utilities
*/

void	get_param_opcode(t_list *new);
void	get_label_opcode(t_list *new);
void	get_cmd_opcode(t_list *new, int i);
int		get_cmd_parambyte(t_list *new, int bin);
void	convert_file(t_list *root);

/*
** print utilities
*/

void	str_to_code(t_list *new, char *str);
void	print_0(int n, int fd);
void	print_hex(unsigned int hex, int fd);

#endif
