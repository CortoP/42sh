/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ft_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 11:31:45 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 11:43:57 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

int				ft_test_ft_functions(t_sh *p, char **av)
{
	(void)p;
	if (ft_strcmp(av[0], "exit") == 0)
		ft_exit(av[1]);
	return (-1);
}
