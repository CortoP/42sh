/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:18:43 by vlehuger          #+#    #+#             */
/*   Updated: 2013/12/29 12:47:24 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <shell.h>
#include <sys/stat.h>

static void		without_arg(t_sh *sh);
static void		with_arg(t_sh *sh);

void		ft_cd(t_sh *sh)
{
	if (!sh->cmd_arg[1] || ft_strcmp(sh->cmd_arg[1], "~") == 0)
		without_arg(sh);
	else
		with_arg(sh);
		return ;
}

static void		without_arg(t_sh *sh)
{
	int			i;

	i = 0;
	while (sh->envp[i])
	{
		if (ft_strcmp(ft_strsub(sh->envp[i], 0, 5), "HOME=") == 0)
		{
				if (sh->envp[i][5])
					chdir(sh->envp[i] + 5);
		}
		i++;
	}
}

static void		with_arg(t_sh *sh)
{
	DIR			*dir;
	struct dirent	*entry;
	struct stat		buf;

	dir = opendir(".");
	while ((entry = readdir(dir)) != NULL)
	{
		if (ft_strcmp(entry->d_name, sh->cmd_arg[1]) == 0)
		{
			if (entry->d_type == DT_DIR)
			{
				stat(entry->d_name, &buf);
				if ((buf.st_mode & S_IXUSR) && (buf.st_mode & S_IXOTH))
					chdir(sh->cmd_arg[1]);
				else
					error(PER_DEN, sh->cmd_arg[1]);
			}
			else
				error(NOT_DIR, sh->cmd_arg[1]);
			return ;
		}
	}
	closedir(dir);
	error(N_F_D, sh->cmd_arg[1]);
}
