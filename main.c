/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:58:17 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/24 13:21:04 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

int				main(int ac, char **av, char **envp)
{
	t_sh		*p;

	av = av;

	if (ac == 1 && (p = ft_get_params(envp)) != NULL)
		ft_shell(p);
	else
	{
		write(2, "./ft_minishell2 : usage ./ft_minishell2\n", 40);
		return (-1);
	}
	return (0);
}
