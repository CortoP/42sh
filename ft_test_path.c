/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 09:59:08 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/26 17:56:16 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

void				ft_execute_pipe(char *path, char ***av, char **env, t_sh *p);


void				ft_test_path(char **env_path, t_sh *p, char **av)
{
	int				i;
	char			*path;

	if (av[0][0] == '/' && ft_test_direct_access(p, av) == 0)
		return ;
	else
	{
		i = 0;
		while (env_path[i])
		{
			path = ft_strjoin(env_path[i], "/");
			path = ft_strjoin(path, av[0]);
			if (access(path, X_OK) == 0)
			{
				ft_execute(path, av, p->env);
				free(path);
				return ;
			}
			free(path);
			i++;
		}
	}
	if (ft_test_ft_functions(p, av) != 0)
		ft_error(CMD_NOT_FOUND, av[0]);
}

char				ft_test_pipe_path(char **env_path, t_sh *p, char ***av)
{
	int				i;
	char			*path;

	if (av[0][0][0] == '/' && ft_test_direct_access(p, av[0]) == 0)
		return (0);
	else
	{
		i = 0;
		while (env_path[i])
		{
			path = ft_strjoin(env_path[i], "/");
			path = ft_strjoin(path, av[0][0]);
			if (access(path, X_OK) == 0)
			{
				ft_execute_pipe(path, av, p->env, p);
				free(path);
				return (0);
			}
			free(path);
			i++;
		}
	}
	if (ft_test_ft_functions(p, av[0]) == 0)
		return (0);
	return (1);
}

void				ft_execute(char *path, char **av, char **env)
{
	pid_t			father;

	father = fork();
	if (father > 0)
		wait(NULL);
	if (father == 0)
		execve(path, av, env);
}

void				ft_execute_pipe(char *path, char ***av, char **env, t_sh *p)
{
	int				fd[2];
	pid_t			father;
	
	father = fork();
    pipe(fd);
	if (father > 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		execve(path, av[0], env);
	}
	else if (father == 0)
	{
		wait(NULL);
		dup2(fd[0], 0);
		close(fd[1]);
		ft_test_path(p->paths, p, av[1]);
	}
	dup2(p->reg_fd[0], 0);
	dup2(p->reg_fd[1], 1);
}

int					ft_test_direct_access(t_sh *p, char **av)
{
	if (access(av[0], X_OK) == 0)
	{
		ft_execute(av[0], av, p->env);
		return (0);
	}
	return (1);
}
