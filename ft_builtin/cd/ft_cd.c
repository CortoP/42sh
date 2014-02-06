/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:18:43 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/06 15:42:31 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_sh2.h>
#include <sys/stat.h>
#include <dirent.h>

static void			ft_go_to_home(t_sh *sh);
static void			ft_go_to_last(t_sh *sh);
static void			with_arg(t_sh *sh, char **av);
static void			ft_go_to_root(t_sh *sh, char **av);

void				ft_cd(t_sh *sh, char **av)
{
	if (!av[1] || ft_strcmp(av[1], "~") == 0)
		ft_go_to_home(sh);
	else if (ft_strcmp(av[1], "-") == 0)
		ft_go_to_last(sh);
	else if (av[1][0] == '/')
		ft_go_to_root(sh, av);
	else
		with_arg(sh, av);
}

static void			ft_go_to_home(t_sh *sh)
{
	int				i;

	i = 0;
	while (sh->env[i])
	{
		if (ft_strcmp(ft_strsub(sh->env[i], 0, 5), "HOME=") == 0)
		{
				if (sh->env[i][5])
					chdir(sh->env[i] + 5);
		}
		i++;
	}
}

static void			with_arg(t_sh *sh, char **av)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		buf;

	dir = opendir(".");
	while ((entry = readdir(dir)) != NULL)
	{
		if (ft_strcmp(entry->d_name, av[1]) == 0)
		{
			if (entry->d_type == DT_DIR)
			{
				stat(entry->d_name, &buf);
				if (buf.st_mode & S_IXUSR)
				{
					chdir(av[1]);
					ft_change_pwd(sh, av[1]);
				}
				else
					ft_error(PER_DEN, av[1]);
			}
			else
				ft_error(NOT_DIR, av[1]);
			return ;
		}
	}
	closedir(dir);
	ft_error(N_F_D, av[1]);
}

static void			ft_go_to_last(t_sh *sh)
{
	char			**tmp_array;
	
	ft_putendl(sh->last_pwd);
	tmp_array = (char **)malloc(sizeof(char *) * 4);
	if (tmp_array)
	{
		tmp_array[0] = ft_strdup("setenv");
		tmp_array[1] = ft_strdup("PWD");
		tmp_array[2] = ft_strdup(sh->last_pwd);
		tmp_array[3] = NULL;
		chdir(sh->last_pwd);
		ft_setenv(sh, tmp_array);
	}
}


static void			ft_root_env(t_sh *sh, char **av)
{
	char			**tmp_array;

	tmp_array = (char **)malloc(sizeof(char *) * 4);
	if (tmp_array)
	{
		tmp_array[0] = ft_strdup("setenv");
		tmp_array[1] = ft_strdup("PWD");
		tmp_array[2] = ft_strdup(av[1]);
		tmp_array[3] = NULL;
		ft_setenv(sh, tmp_array);
	}
}

static void			ft_go_to_root(t_sh *sh, char **av)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		buf;

	if (ft_strcmp(av[1], "/") == 0)
	{
		chdir(av[1]);
		ft_root_env(sh, av);
	}
	else
	{
		dir = opendir("/");
		while ((entry = readdir(dir)) != NULL)
		{
			if (ft_strcmp(entry->d_name, av[1] + 1) == 0)
			{
				if (entry->d_type == DT_DIR)
				{
					stat(entry->d_name, &buf);
					chdir(av[1]);
					ft_root_env(sh, av);
				}
				else
					ft_error(NOT_DIR, av[1] + 1);
				return ;
			}
		}
		closedir(dir);
		ft_error(N_F_D, av[1] + 1);
	}
}
