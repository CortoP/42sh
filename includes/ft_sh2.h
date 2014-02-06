/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 10:32:43 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/06 15:21:55 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SH_2
# define FT_SH_2

# define PROMPT "$> "
# define SEMIC 1
# define PIPE 2
# define CMD 3
# define CMD_NOT_FOUND 1
# define PER_DEN 2
# define N_F_D 3
# define NOT_DIR 4
# include <libft.h>
# include <stdio.h>

typedef struct		s_cmd
{
	char			*cmd_line;
	char			split_type;
	char			**argv;
	char			in_redir;
	char			out_redir;
	struct s_cmd	*split_cmd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_sh
{
	char			**env;
	char			*last_pwd;
	char			*pwd;
	char			**paths;
	int				reg_fd[2];
	t_cmd			*cmd;
}					t_sh;


char				**array_dup(char **array);
char				**ft_array_add(char **env, char **av);
char				**ft_array_rem(t_sh *p, char *name);
char				**ft_array_sub(char **array, int start, int len, char *c);
void				ft_cd(t_sh *sh, char **av);
void				ft_change_pwd(t_sh *p, char *dir);
void				ft_cmd(t_sh *p);
char				ft_cmp_env(char *env, char *cmd);
void				ft_error(int error, char *name);
void				ft_execute(char *path, char **av, char **env);
void				ft_exec_cmd(t_sh *p);
void				ft_exit(char *str);
t_cmd				*ft_get_args(char *str);
void				ft_get_cmd(t_sh *p);
char				*ft_get_env(char **env, char *var);
char				**ft_get_env_path(char *var);
t_sh				*ft_get_params(char **envp);
t_cmd				*ft_get_separated_cmd(char **s_semic_split);
void				ft_in_exec(t_cmd *cmd, t_sh *p);
t_cmd				*ft_init_cmd(char *line, char flag);
void				ft_out_exec(t_cmd *cmd, t_sh *p);
void				ft_reg_exec(t_cmd *cmd, t_sh *p);
char				***ft_separe_in(char **av);
char				***ft_separe_out(char **av);
void				ft_setenv(t_sh *p, char **av);
void				ft_shell(t_sh *p);
char				**ft_split_trim(char *arg, char c);
void				ft_test_cmd_exec(t_cmd *cmd, t_sh *p);
int					ft_test_direct_access(t_sh *p, char **av);
void				ft_test_exec_redir(t_cmd *cmd, t_sh *p);
int					ft_test_ft_functions(t_sh *p, char **av);
void				ft_test_path(char **env_path, t_sh *p, char **av);
t_cmd				*ft_test_pipe(t_cmd *cmd);
int					ft_test_pipe_cmd(t_cmd *cmd, t_sh *p);
char				ft_test_pipe_path(char **env_path, t_sh *p, char ***av);
t_cmd				*ft_test_redir(t_cmd *cmd);
void				ft_unsetenv(t_sh *p, char **av);
int					ft_valid_redir(char *str, char c);

#endif /* !FT_SH_2 */
