/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 10:32:43 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/24 17:39:42 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_SH_2
# define FT_SH_2

# define PROMPT "$> "
# define SEMIC 1
# define PIPE 2
# define CMD 3

# include <libft.h>

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
	char			**paths;
	t_cmd			*cmd;
}					t_sh;


char				**array_dup(char **array);
void				ft_cmd(t_sh *p);
void				ft_execute(char *path, char **av, char **env);
void				ft_exec_cmd(t_sh *p);
t_cmd				*ft_get_args(char *str);
void				ft_get_cmd(t_sh *p);
char				*ft_get_env(char **env, char *var);
char				**ft_get_env_path(char *var);
t_sh				*ft_get_params(char **envp);
t_cmd				*ft_get_separated_cmd(char **s_semic_split);
t_cmd				*ft_init_cmd(char *line, char flag);
void				ft_reg_exec(t_cmd *cmd, t_sh *p);
void				ft_shell(t_sh *p);
char				**ft_split_trim(char *arg, char c);
void				ft_test_cmd_exec(t_cmd *cmd, t_sh *p);
void				ft_test_exec_redir(t_cmd *cmd, t_sh *p);
char				ft_test_path(char **env_path, t_sh *p, char **av);
t_cmd				*ft_test_pipe(t_cmd *cmd);
t_cmd				*ft_test_redir(t_cmd *cmd);

#endif /* !FT_SH_2 */
