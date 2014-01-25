/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:00:21 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 15:19:42 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_sh2.h>

char		**array_dup(char **array)
{
	char	**new_array;
	int		i;

	i = 0;
	while (array[i])
		i++;
	new_array = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}

char		**ft_array_add(char **env, char **av)
{
	char	**new_a;
	int		i;

	i = 0;
	while (env[i])
		i++;
	new_a = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (env[i])
	{
		new_a[i] = ft_strdup(env[i]);
		free(env[i]);
		i++;
	}
	if (av[2])
		new_a[i] = ft_strjoin(ft_strjoin(av[1], "="), av[2]);
	else
		new_a[i] = ft_strjoin(av[1], "=");
	new_a[i + 1] = NULL;
	return (new_a);
}

char		**ft_array_rem(t_sh *p, char *name)
{
	char	**new_array;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (p->env[i])
		i++;
	k = i;
	new_array = (char **)malloc(sizeof(char *) * (i - 1));
	j = 0;
	i = 0;
	while (i < k)
	{
		if (ft_cmp_env(name, p->env[i]) != 0)
		{
			new_array[j] = ft_strdup(p->env[i]);
			j++;
		}
		i++;
	}
	new_array[j] = NULL;
	return (new_array);
}
