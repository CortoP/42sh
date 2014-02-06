/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ft_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:31:45 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/06 11:24:29 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

int				ft_test_ft_functions(t_sh *p, char **av)
{
	if (ft_strcmp(av[0], "exit") == 0)
		ft_exit(av[1]);
	else if (ft_strcmp(av[0], "setenv") == 0)
	{
		ft_setenv(p, av);
		return (0);
	}
	else if (ft_strcmp(av[0], "unsetenv") == 0)
	{
		ft_unsetenv(p, av);
		return (0);
	}
	else if (ft_strcmp(av[0], "cd") == 0)
	{
		ft_cd(p, av);
		return (0);
	}
	return (-1);
}
