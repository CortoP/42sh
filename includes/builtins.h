/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:01:08 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/27 14:01:08 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define ENV_OPT "i"
# define ENV_ERROR "usage: env [-i] [name=value ...] [utility [argument ...]]\n"

# define CD_OPT "LP"
# define CD_ERROR "usage: cd [-L|-P] [dir]\n"
# define CD_TOMANY "cd: too many arguments"
# define CD_NOSUCH "cd: no such file or directory: "
# define CD_NOSTR "cd: string not in pwd: "

int			ft_env(int ac, char **av);
int			ft_setenv(int ac, char **av);
int			ft_unsetenv(int ac, char **av, int i, int j);

int			ft_exit(int ac, char **av);

int			ft_echo(int ac, char **av);

int			ft_cd(int ac, char **av);
char		*get_path(char *name);
char		*cd_replace(int ac, char **av);
void		cd_env_change(char *newpwd);
char		*parse_pwd(char *path);
char		*trim_bs(char *newpwd);

#endif
