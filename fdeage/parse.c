/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:08:19 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 17:51:39 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_fn.h"
#include "libft.h"

static void	check_name(t_file *file, t_list *tmp)
{
	t_list	*tmp2;
	char	*tmp_str;
	char	*tmp_str2;

	tmp_str = ft_strtrim(LINE->str);
	//if

	if (ft_strncmp(LINE->str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		LINE->type = T_NAME;
		tmp2 = tmp->next;
        if (!(tmp2->next))
            asm_error("Name is not here.\n");
        else
            ft_strcpy(file->header.prog_name, ((t_line *)(tmp2->content))->str);
	}
	return ;
}

static void	check_comment(t_file *file, t_list *tmp)
{
	t_list	*tmp2;

	if (ft_strncmp(LINE->str, COMMENT_CMD_STRING,
		ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		LINE->type = T_INIT_COMMENT;
		tmp2 = tmp->next;
		if (!(tmp2->next))
			asm_error("Comment is not here.\n");
		else
			ft_strcpy(file->header.comment, ((t_line *)(tmp2->content))->str);
	}
	return ;
}

void		parse_file(t_file *file)
{
	t_list  *tmp;

	tmp = file->lines;
	while (tmp)
	{
		check_name(file, tmp);
		check_comment(file, tmp);
		//check_inst(file, tmp);
		tmp = tmp->next;
	}
	return ;
}


//COMMENT_CMD_STRING ".comment"
/*
	if (line[0] == COMMENT_CHAR || line[0] == COMMENT_CHAR2)
	{
		free(new);
		free(line);
		return ;
	}
	else if (ft_strcmp(NCS, ft_strtrunc(line, ft_strlen(NCS))) == 0)
	{
		new->str = ft_strdup(get_name_comment(line));
		new->type = ".name      ";
		list_pushback(root, new);
	}
	else if (ft_strcmp(CCS, ft_strtrunc(line, ft_strlen(CCS))) == 0)
	{
		new->str = ft_strdup(get_name_comment(line));
		new->type = ".comment   ";
		list_pushback(root, new);
	}
	else
		get_others(root, line, new, nb_line);
*/
