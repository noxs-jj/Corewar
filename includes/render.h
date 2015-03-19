/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 11:47:09 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/19 15:32:41 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "corewar.h"

# define MAP_WIDTH 254
# define MAP_HEIGHT 68

# define L_Y_MAP_START 2
# define L_X_MAP_START 2
# define L_Y_MAP_END 66
# define L_X_MAP_END 194

# define L_X_START 196
# define L_X_END 195

# define L_X_WRITE 199
# define L_Y_START 0
# define L_Y_STATUS 2

# define L_Y_SEC_CLE 4
# define L_X_SEC_CLE_VALUE 221

# define L_Y_CYCLE 7
# define L_X_CYCLE_VALUE 207

# define L_Y_PROCES 9
# define L_X_PROCES_VALUE 211

# define L_Y_PLAY_1 11
# define L_X_PLAY1_VALUE 211
# define L_Y_P1_LAST 12
# define L_X_P1_LAST_VALUE 233
# define L_Y_P1_LIVE 13
# define L_X_P1_LIVE_VALUE 233

# define L_Y_PLAY_2 15
# define L_X_PLAY2_VALUE 211
# define L_Y_P2_LAST 16
# define L_X_P2_LAST_VALUE 233
# define L_Y_P2_LIVE 17
# define L_X_P2_LIVE_VALUE 233

# define L_Y_PLAY_3 19
# define L_X_PLAY3_VALUE 211
# define L_Y_P3_LAST 20
# define L_X_P3_LAST_VALUE 233
# define L_Y_P3_LIVE 21
# define L_X_P3_LIVE_VALUE 233

# define L_Y_PLAY_4 23
# define L_X_PLAY4_VALUE 211
# define L_Y_P4_LAST 24
# define L_X_P4_LAST_VALUE 233
# define L_Y_P4_LIVE 25
# define L_X_P4_LIVE_VALUE 233

# define L_Y_BR_CURR 27
# define L_Y_BR_CURR_LINE 28
# define L_Y_BR_LAST 30
# define L_Y_BR_LAST_LINE 31

# define L_Y_DIE 33
# define L_X_DIE_VALUE 214

# define L_Y_DELTA 35
# define L_X_DELTA_VALUE 213

# define L_Y_N_LIVE 37
# define L_X_N_LIVE_VALUE 210

# define L_Y_N_CHECK 39
# define L_X_N_CHECK_VALUE 212

# define L_Y_MINUS 59
# define L_Y_PLUS 61

# define L_Y_PAUSE 63
# define L_Y_EXIT 65

# define S_DEFAULT_VALUE	"0x0 Data"
# define S_LAST_LIVE 		"  Last live :"
# define S_LIVE_CURR 		"  Lives in current period :"
# define S_BREAK_CURR		"Live breakdown for current period :"
# define S_BREAK_LAST		"Live breakdown for last period :"
# define S_RUNNING 			"** RUNNING ** "
# define S_PAUSE 			"** PAUSED **"
# define S_MAX_CHECKS 		"MAX_CHECKS :"
# define S_NBR_LIVE			"NBR_LIVE :"
# define S_CYCLE_DELTA 		"CYCLE_DELTA :"
# define S_CYCLE_DIE 		"CYCLE_TO_DIE :"
# define S_PROCESS 			"Processes :"
# define S_CYCLE 			"Cycle :"
# define S_CYCLE_SECOND 	"Cycles/second limit :"
# define S_PLAYER_1			"Player 1 ->"
# define S_PLAYER_2			"Player 2 ->"
# define S_PLAYER_3			"Player 3 ->"
# define S_PLAYER_4			"Player 4 ->"
# define S_DEFAULT_BAR "[--------------------------------------------------]"
# define S_KEY_PLUS			"SLOWER: +"
# define S_KEY_MINUS		"FASTER: -"
# define S_KEY_PAUSE		"PAUSE:  P or SPACE"
# define S_KEY_EXIT			"EXIT:   E, Q or ECHAP"

# define S_C_BYTES			" bytes, "

#endif
