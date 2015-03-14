/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 11:47:09 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/02/27 21:43:27 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "corewar.h"

/* set WINDOWS */
# define MAP_WIDTH 254			/* default 254 */
# define MAP_HEIGHT 68			/* default 68 */

/* Memory Map */
# define L_Y_MAP_START 2 		/* default 2 */
# define L_X_MAP_START 2 		/* default 2 */
# define L_Y_MAP_END 66			/* default 66 */
# define L_X_MAP_END 194		/* default 194 */

/* L = Legends */
# define L_X_START 196			/* default 197 */
# define L_X_END 195			/* default 195 */

# define L_X_WRITE 199			/* default 199 column */
# define L_X_WRITE_value 233	/* default 233 */
# define L_Y_START 0 			/* default 0 */
# define L_Y_STATUS 2 			/* default 2 "** RUNNING **" || "** PAUSED **" */

# define L_Y_SEC_CLE 4			/* default 4 "Cycles/second limit :" */
# define L_X_SEC_CLE_VALUE 221	/* default 221 "value Cycle/second limit : 0" */

# define L_Y_CYCLE 7			/* default 7 "Cycle :" */
# define L_X_CYCLE_VALUE 207	/* default 207 "value of Cycle: 0" */

# define L_Y_PROCES 9			/* default 10 "Processes :" */
# define L_X_PROCES_VALUE 211	/* default 211 "value of processes : 0" */

/* Player 1 */
# define L_Y_PLAY_1 11			/* default 11 "Player 1" */
# define L_X_PLAY1_VALUE 211	/* default 211 "Player 1 -> champName" */
# define L_Y_P1_LAST 12			/* default 12 "Last live :" */
# define L_X_P1_LAST_VALUE 233	/* default 233 "Last live : value" */
# define L_Y_P1_LIVE 13			/* default 13 "Lives in current period :" */
# define L_X_P1_LIVE_VALUE 233	/* default 233 "Lives period : value" */

/* Player 2 */
# define L_Y_PLAY_2 15			/* default 15 "Player 2" */
# define L_X_PLAY2_VALUE 211	/* default 211 "Player 2 -> champName" */
# define L_Y_P2_LAST 16			/* default 20 "Last live :" */
# define L_X_P2_LAST_VALUE 233	/* default 233 "Last live : value" */
# define L_Y_P2_LIVE 17			/* default 21 "Lives in current period :" */
# define L_X_P2_LIVE_VALUE 233	/* default 233 "Lives period : value" */

/* Player 3 */
# define L_Y_PLAY_3 19			/* default 19 "Player 3" */
# define L_X_PLAY3_VALUE 211	/* default 211 "Player 2 -> champName" */
# define L_Y_P3_LAST 20			/* default 20 "Last live :" */
# define L_X_P3_LAST_VALUE 233	/* default 233 "Last live : value" */
# define L_Y_P3_LIVE 21			/* default 21 "Lives in current period :" */
# define L_X_P3_LIVE_VALUE 233	/* default 233 "Lives period : value" */

/* Player 4 */
# define L_Y_PLAY_4 23			/* default 23 "Player 4" */
# define L_X_PLAY4_VALUE 211	/* default 211 "Player 2 -> champName" */
# define L_Y_P4_LAST 24			/* default 24 "Last live :" */
# define L_X_P4_LAST_VALUE 233	/* default 233 "Last live : value" */
# define L_Y_P4_LIVE 25			/* default 25 "Lives in current period :" */
# define L_X_P4_LIVE_VALUE 233	/* default 233 "Lives period : value" */

/* Legends bottom after player UI */
# define L_Y_BR_CURR 27			/* default 27 "Live breakdown for current period : " */
# define L_Y_BR_CURR_LINE 28	/* default 28 "[---]" */
# define L_Y_BR_LAST 30			/* default 30 "Live breakdown for last period :" */
# define L_Y_BR_LAST_LINE 31	/* default 31 "[---]" */

# define L_Y_DIE 33				/* default 33 "CYCLE_TO_DIE :" */
# define L_X_DIE_VALUE 214		/* default 214 "CYCLE_TO_DIE : value" */

# define L_Y_DELTA 35			/* default 35 "CYCLE_DELTA :" */
# define L_X_DELTA_VALUE 213	/* default 213 "CYCLE_DELTA : value" */

# define L_Y_N_LIVE 37			/* default 37 "NBR_LIVE :" */
# define L_X_N_LIVE_VALUE 210	/* default 210 "NBR_LIVE : value" */

# define L_Y_N_CHECK 39			/* default 39 "MAX_CHECKS :" */
# define L_X_N_CHECK_VALUE 212	/* default 212 "MAX_CHECKS : value" */

# define L_Y_MINUS 59			/* default 59 - MOIN */
# define L_Y_PLUS 61			/* default 61 + PLUS */

# define L_Y_PAUSE 63			/* default 63 Pause */
# define L_Y_EXIT 65			/* default 65 exit */

/* Strings */
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
# define S_KEY_MINUS		"SLOWER: -"
# define S_KEY_PLUS			"FASTER: +"
# define S_KEY_PAUSE		"PAUSE:  P or SPACE"
# define S_KEY_EXIT			"EXIT:   E, Q or ECHAP"

/* Console drawing */
# define S_C_BYTES			" bytes, "

#endif
