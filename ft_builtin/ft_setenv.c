/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:22:55 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 14:40:12 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_sh2.h>

static void	ft_setenv_valid(t_sh *p, char **av);

void		ft_setenv(t_sh *p, char **av)
{
	int		i;

	if ((av[1] || (av[1] && av[2]))
		&& !av[3])
		ft_setenv_valid(p, av);
	else if (!av[1])
	{
		i = 0;
		while (p->env[i])
		{
			ft_putendl(p->env[i]);
			i++;
		}
	}
	else
		write (1, "setenv: Too many arguments.\n", 29);
}

static void	ft_setenv_valid(t_sh *p, char **av)
{
	int		i;

	i = 0;
	while (p->env[i])
	{
		if (ft_cmp_env(p->env[i], av[1]) == 0)
		{
			if (av[2])
				p->env[i] = ft_strjoin(ft_strjoin(av[1], "="),
										av[2]);
			return ;
		}
		i++;
	}
	p->env = ft_array_add(p->env, av);
}
