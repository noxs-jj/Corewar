/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_compil.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:30:20 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/07 13:30:22 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"

# define LOGS true

typedef struct s_cmd
{
	char			*line;
	struct s_cmd	*next;
}t_cmd;

typedef struct s_asm
{
	int		fdSource;
	char	*name;

}t_asm;

t_asm	*getASMdata( void );

t_cmd	*s_lstCreate(char *string);
void	s_lstFreeLink(t_cmd *toDel);
void	s_lstAddEnd(t_cmd **lst, t_cmd *new);
void	s_lstDelAll(t_cmd **lst);

int		s_sti(void);
int 	init_start(char **av);

#endif
