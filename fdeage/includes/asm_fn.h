/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fn.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:30:05 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/12 17:33:07 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_FN_H
# define ASM_FN_H

//# include "asm.h"
//# include "op.h"
//# include "libft.h"

/*
** exit.c
*/

void	exit_asm(t_file *file);

/*
** read.c
*/

int		read_file(t_file *file);

/*
** write.c
*/

void	write_cor(t_file *file);

/*
** parse.c
*/

void	parse_file(t_file *file);


/*
** parsing_fn
*/

char	*get_name_comment(char *line);
char	*get_label(char **line);
char	*get_cmd(char **line);
void	get_args(t_list *root, char **par, t_line *new, int nb_line);

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

/*
** error.c
*/

void	asm_error(const char *str);

#endif