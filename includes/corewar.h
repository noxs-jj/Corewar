/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 12:56:32 by vjacquie          #+#    #+#             */
/*   Updated: 2015/02/12 16:21:47 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>

# define LOG				1
# define PATH_DEBUGG		"../log/corewar.log"

# define ERR_PARAM "./corewar [-dump nbr_cycles] [[-n number] champion.cor]..."
# define ERR_FILE_DEBUGG "core corewar.log open error."
# define ERR_FILE "File doesn't exist"
# define ERR_READ "Read file error"

# define BUFFSIZE 1

// #define IND_SIZE				2
#define REG_SIZE				4
// #define DIR_SIZE				REG_SIZE

// # define REG_CODE				1
// # define DIR_CODE				2
// # define IND_CODE				3

#define MAX_PLAYERS				4
#define MAX_ARGS_NUMBER			(3 + 3 * MAX_PLAYERS)

#define MEM_SIZE				(4 * 1024)
// #define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / MAX_PLAYERS + 2)

// #define COMMENT_CHAR				'#'
// #define LABEL_CHAR				':'
// #define DIRECT_CHAR				'%'
// #define SEPARATOR_CHAR			','

// #define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

// #define NAME_CMD_STRING			".name"
// #define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

// typedef char	t_arg_type;

// #define T_REG					1
// #define T_DIR					2
// #define T_IND					4
// #define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		128	// 128
# define COMMENT_LENGTH			2048// 2048
// # define COREWAR_EXEC_MAGIC		0xea83f3


typedef struct	s_case
{
	unsigned char 		hex[2];
	short int 			champ; // champions's number ( 0 1 2 3 4 )
	short int 			present; //is present ( 0 1 2 3 4 )
	bool 				used; // true : yes, false : no


}				t_case;

typedef struct		s_header
{
	// unsigned int		magic;
	//	stocker le prog
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		number;
	char 				*filename; // no malloc
	unsigned int		prog_size;
	
	unsigned char		prog[MEM_SIZE / 6];
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef	struct	s_data
{
	t_header	prog[MAX_PLAYERS];
	int 		players;
	int 		dump;
	WINDOW		*window;
	int			fdDebugg;
}				t_data;


int		init_start(t_data *d, int ac, char **av);
int		print_error(char *str);
t_data	*getData(void);
void	writeL(char *str);
int		read_files(t_data *d);

// NCurses
void	renderClose(t_data *d);
void	renderDraw(t_data *d);
int 	renderInit(t_data *d);
void	renderLegendColumn(t_data *d);
void	renderLegendSentence(t_data *d);
void 	renderLegendPlayerSentence(t_data *d);
void	renderLegendPlayerValue(t_data *d);
void	renderLegendInfoValue(t_data *d);

#endif
