/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:59:29 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 13:59:29 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					ft_echo(int ac, char **av)
{
	int				i;
	int				n;

	n = 0;
	i = 0;
	if (ft_strequ(av[0], "-n"))
	{
		n++;
		i++;
	}
	while (i < ac)
	{
		ft_putstr(av[i]);
		if (i != ac - 1)
			ft_putchar(' ');
		i++;
	}
	if (!n)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
