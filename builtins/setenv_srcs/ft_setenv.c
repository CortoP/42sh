/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:00:04 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:00:04 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				ft_setenv(int ac, char **av)
{
	if (!ac)
		ft_printenv();
	else if (ac > 2)
	{
		ft_putendl_fd("setenv: Too many arguments.", 2);
		exit(1);
	}
	else if (ft_strchr(av[0], '='))
	{
		ft_putendl_fd("setenv: Syntax Error.", 2);
		exit(1);
	}
	else if (ac == 2)
		ft_putenv(av[0], av[1]);
	else
		ft_putenv(av[0], "");
	return (0);
}
