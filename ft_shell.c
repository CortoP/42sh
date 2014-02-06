/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 15:45:24 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/06 15:26:27 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

void				ft_shell(t_sh *p)
{
	while (42)
	{
		if (ft_strcmp(p->pwd, ft_get_env(p->env, "PWD")) != 0)
		{
			p->last_pwd = ft_strdup(p->pwd);
			p->pwd = ft_get_env(p->env, "PWD");
		}
		ft_putstr(PROMPT);
		ft_cmd(p);
	}
}
