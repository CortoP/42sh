/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:23:57 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 15:16:52 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_sh2.h>

void		ft_unsetenv(t_sh *p, char **av)
{
	int		i;
	int		j;

	if (p->env[1])
	{
		j = 0;
		while (av[j])
		{
			i = 0;
			while (p->env[i])
			{
				if (ft_cmp_env(av[j], p->env[i]) == 0)
				{
					p->env = ft_array_rem(p, av[j]);
					break ;
				}
				i++;
			}
			j++;
		}
	}
	else
		write(1, "unsetenv: Too few arguments.\n", 29);
}
