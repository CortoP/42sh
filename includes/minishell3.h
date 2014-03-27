/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:01:14 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/27 14:08:20 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL3_H
# define MINISHELL3_H

# include <libft.h>
# include <sys/ioctl.h>

# define GREEN write(1, "\033[32;40m", 9)
# define DEFCOLOR write(1, "\033[0m", 5)
# define INDEX us->cursor
# define KEY_1 {{10, K_LF}, {27, K_ESC}, {12, K_CTRL_L},
# define KEY_2 {127, K_DELETE}, {0, K_NONE}}
# define KEY KEY_1 KEY_2
# define MSG_PROMPT {"bquote>", "dquote>", "quote>", "cursh>", "subsh>"}
# define KEY_BIS KEY_BIS_1 KEY_BIS_2
# define KEY_BIS_1 {{65, K_UP}, {66, K_DOWN}, {67, K_RIGHT}, {68, K_LEFT},
# define KEY_BIS_2 {51, K_SUPPR}, {70, K_END}, {72, K_HOME}, {0, K_NONE},}
# define KEY_TER KEY_TER_1 KEY_TER_2 KEY_TER_3 KEY_TER_4 KEY_TER_5 KEY_TER_6
# define KEY_TER_1 {{K_ESC, sh_pk_esc}, {K_LF, sh_pk_linefeed},
# define KEY_TER_2 {K_DELETE, sh_pk_delete}, {K_SUPPR, sh_pk_suppr},
# define KEY_TER_3 {K_HOME, sh_pk_home}, {K_END, sh_pk_end},
# define KEY_TER_4 {K_CTRL_L, sh_pk_ctrl_l}, {K_LEFT, sh_pk_arrow_lft_rght},
# define KEY_TER_5 {K_RIGHT, sh_pk_arrow_lft_rght}, {K_UP, sh_pk_arrow_up},
# define KEY_TER_6 {K_DOWN, sh_pk_arrow_dn}}
# define FLAG_PROMPT {"``", "\"\"", "\'\'", "{}", "()"}

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

/*
** Structures for user entry
*/

/*
** Type of key entry.
*/

typedef enum		e_k_type
{
	K_ESC,
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_LF,
	K_DELETE,
	K_CTRL_L,
	K_SUPPR,
	K_END,
	K_HOME,
	K_NONE
}					t_k_type;

/*
** History struct for user entry
*/

typedef struct		s_hist
{
	struct s_hist	*next;
	struct s_hist	*prev;
	char			*entry;
}					t_hist;

/*
** Main struct for user entry
** cursor : index of the current charactere aimed by the cursor in the
**          current edit string.
** c_size : current size of the string, to know if it needs to be remade bigger
** edit_limit : current end of the string. maybe should be replaced by '\0'
*/
typedef struct winsize		t_swin;

typedef struct		s_usent
{
	char			buf[6];
	t_k_type		key;
	t_bool			leave;
	char			*edit;
	t_hist			*hist;
	char			*tmp;
	int				cursor;
	int				c_size;
	t_swin			*winsize;
	int				prompt_size;
	int				curs_col;
	int				curs_line;
	int				edit_limit;
	t_bool			insert;
	char			pf[5];
}					t_usent;

/*
** Struct for key processing
*/

typedef struct		s_key
{
	t_k_type		k_type;
	void			(*f)(t_usent *us);
}					t_key;

typedef struct		s_simp_key
{
	char			c;
	t_k_type		k_type;
}					t_simp_key;

/*
** user_entry_init.c
*/
void				user_entry_init(t_hist **hist, t_usent *us);
void				sh_init_prompt_flag(t_usent *us);
/*
** cursor_move.c
*/
void				go_right(t_usent *us);
void				go_left(t_usent *us);
void				go_back_up_right(t_usent *us);
void				carriage_ret(void);

void				set_cursor_position(t_usent *us, int direction);
void				go_right_to(t_usent *us, int start, int end);
void				go_left_to(t_usent *us, int start, int end);
/*
** sh3_termios.c
*/
void				sh_set_termios(void);
void				sh_reset_termios(void);
void				set_winstruct(struct winsize **win, int destroy);
/*
** sh3_error.c
*/
void				sh_error_quit(char *str);

/*
** sh3_signals.c
*/
void				set_signals(void);

/*
**sh3_quit.c
*/
void				sh_quit(void);

/*
**sh3_signals
*/
void				set_signals(void);

/*
**sh3_user_entry.c
*/

void				sh_init_usent(t_usent *us, t_hist *hist);
void				sh_init_hist(t_hist **hist);
char				*get_user_entry(void);

/*
**sh3_prompt.c
*/
void				print_main_prompt(t_usent *us);
void				sh_prompt(t_usent *us);

/*
** sh3_user_entry_get_key.c
*/
t_k_type			sh_key_get(t_usent *us);

/*
**sh_tputchar.c
*/
int					tputchar(int c);

/*
**sh3_user_entry_process_key.c
*/
void				sh_process_key_entry(t_usent *us, int i);

/*
**sh3_user_entry_process_key2.c
*/
void				sh_pk_suppr(t_usent *t);
void				sh_pk_home(t_usent *us);
void				sh_pk_end(t_usent *us);
void				sh_pk_ctrl_l(t_usent *us);
/*
**sh3_user_entry_edition.c
*/
void				sh_edition(t_usent *us);

/*
**sh3_user_entry_display.c
*/
int					read_print_user_entry(t_usent *us);

/*
**sh3_user_entry_history.c
*/
void				sh_add_history(t_hist **hist);
void				sh_pk_arrow_dn(t_usent *us);
void				sh_pk_arrow_up(t_usent *us);

/*
**sh3_user_entry_state_flag.c  A SUPPRIMER PROCHAINEMENT
*/

void				sh_entry_prompt_flag(t_usent *us, char key);
void				sh_entry_linefeed(t_usent *us);

#endif
