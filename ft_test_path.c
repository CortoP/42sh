/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 09:59:08 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 11:41:41 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

char					ft_test_path(char **env_path, t_sh *p, char **av)
{
	int					i;
	char				*path;

	if (av[0][0] == '/' && ft_test_direct_access(p, av) == 0)
		return (0);
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
				return (0);
			}
			free(path);
			i++;
		}
	}
	if (ft_test_ft_functions(p, av) == 0)
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

int					ft_test_direct_access(t_sh *p, char **av)
{
	if (access(av[0], X_OK) == 0)
	{
		ft_execute(av[0], av, p->env);
		return (0);
	}
	return (1);
}
