/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 17:30:23 by vlehuger          #+#    #+#             */
/*   Updated: 2013/12/28 19:39:03 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <shell.h>

void		ft_env(t_sh *sh)
{
	int		i;

	i = 0;
	if (!sh->cmd_arg[1])
	{
		while (sh->envp[i])
		{
			ft_putendl(sh->envp[i]);
			i++;
		}
	}
	else
	{
		sh->cmd_arg = sh->cmd_arg + 1;
		if (test_ft_cmd(sh) == 0)
		{
			if (test_path(sh) == 0)
			error(CMD_NOT_F, sh->cmd_arg[0]);
		}
	}
}
