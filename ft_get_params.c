/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:19:30 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/06 15:27:06 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

t_sh				*ft_get_params(char **envp)
{
	t_sh			*params;
	char			*var;

	params = (t_sh *)malloc(sizeof(t_sh));
	if (params)
	{
		params->env = array_dup(envp);
		var = ft_get_env(envp, "PATH");
		params->paths = ft_get_env_path(var);
		free(var);
		params->cmd = NULL;
		params->reg_fd[0] = dup(0);
		params->reg_fd[1] = dup(1);
		params->pwd = ft_get_env(envp, "PWD");
		params->last_pwd = ft_get_env(envp, "PWD");
		return (params);
	}
	return (NULL);
}
