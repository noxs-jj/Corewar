/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fn.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:30:05 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/27 14:59:05 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_FN_H
# define ASM_FN_H

/*
** read.c - OK, no leaks
*/

int		read_file(t_file *file);

/*
** write.c - OK
*/

void	write_cor(t_file *file);

/*
** parse.c - OK
*/

int		parse_file(t_file *file);

/*
** tokenize - OK
*/

int		tokenize_line(t_line *line);

/*
** convert.c - OK
*/

int		convert_file(t_file *file);

/*
** error.c - OK
*/

int		asm_error(const char *str);
void	print_detailed_error(t_file *file, const char *av1);

/*
** exit.c - OK, no leaks
*/

void	exit_asm(t_file *file);

/*
** utilities.c - OK
*/

char	*get_code(unsigned char n, char tab[2]);

/*
** check.c - OK
*/

int		has_name(t_file *file);
int		is_only_whitespace(const char *s);
int		has_right_params(t_line *line);
int		check_param(t_token *token, const char *s);

/*
** get_param_value.c - OK
*/

int		get_param_value(t_list *tokens, t_line *line, t_token *token);

#endif
