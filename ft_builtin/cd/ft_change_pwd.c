/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:38:04 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/06 13:36:14 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

static void			ft_rm_last_dir(t_sh *p);

void				ft_change_pwd(t_sh *p, char *dir)
{
	char			**tmp_array;

	if (ft_strcmp(dir, ".") == 0)
		return ;
	else if (ft_strcmp(dir, "..") == 0)
		ft_rm_last_dir(p);
	else
	{
		tmp_array = (char **)malloc(sizeof (char *) * 4);
		if (tmp_array)
		{
			tmp_array[0] = ft_strdup("setenv");
			tmp_array[1] = ft_strdup("PWD");
			tmp_array[2] = ft_strjoin(ft_get_env(p->env, "PWD"), "/");
			tmp_array[2] = ft_strjoin(tmp_array[2], dir);
			tmp_array[3] = NULL;
			ft_setenv(p, tmp_array);
		}
	}
}

static void			ft_rm_last_dir(t_sh *p)
{
	char			**tmp_array;
	char			*path;
	int				i;
	
	path = ft_get_env(p->env, "PWD");
	i = ft_strlen(path) - 1;
	while (i > 0)
	{
		if (path[i] == '/')
			break ;
		i--;
	}
	path = ft_strsub(path, 0, i);
	tmp_array = (char **)malloc(sizeof (char *) * 4);
	if (tmp_array)
	{
		tmp_array[0] = ft_strdup("setenv");
		tmp_array[1] = ft_strdup("PWD");
		tmp_array[2] = ft_strdup(path);
		tmp_array[3] = NULL;
		ft_setenv(p, tmp_array);
	}
}
