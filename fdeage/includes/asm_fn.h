/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fn.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:30:05 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/20 18:46:33 by fdeage           ###   ########.fr       */
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
** convert.c - TODO
*/

int		convert_file(t_file *file);

/*
** error.c - OK
*/

int		asm_error(const char *str);
void	print_detailed_error(t_file *file, const char *av1);

/*
** exit.c - OK (TODO: complete) - no leaks
*/

void	exit_asm(t_file *file);

/*
** utilities.c
*/

char	*get_code(unsigned char n, char tab[2]);

/*
** check.c
*/

int		is_only_whitespace(const char *s);
int		has_final_comment(t_line *line);

/*
** int get_label_value(t_list *tokens, t_token *token)
*/

//void	get_param_value(t_list *tokens, t_token *token);
void	get_param_value(t_list *tokens, t_line *line, t_token *token);

#endif
