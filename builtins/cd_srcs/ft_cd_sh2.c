/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_sh2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:59:14 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 13:59:14 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					ft_cd(int ac, char **av)
{
	char			*path;

	path = NULL;
	if (ac == 0)
		path = get_path("HOME");
	else if (ac == 1)
	{
		if (ft_strequ(av[0], "-"))
			path = get_path("OLDPWD");
		else
			path = av[0];
	}
	else if (ac == 2)
		cd_replace(ac, av);
	else if (ac > 2)
		ft_putendl_fd(CD_TOMANY, 2);
	if (path)
		cd_env_change(path);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char				*trim_bs(char *newpwd)
{
	int				i;

	i = 0;
	while (newpwd[i] && newpwd[i] == '/')
		i++;
	return (newpwd + i - 1);
}
