/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 16:08:04 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 17:30:58 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

char			***ft_separe_in(char **av)
{
	char		***cmd_line;
	int			i;
	int			j;

	cmd_line = (char ***)malloc(sizeof(char **) * 3);
	cmd_line[2] = NULL;
	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "<") == 0)
		{
			i++;
			break ;
		}
		i++;
	}
	cmd_line[0] = ft_array_sub(av, 0, i, "<");
	j = 0;
	while (av[i + j])
		j++;
	cmd_line[1] = ft_array_sub(av, i, j, "<");
	return (cmd_line);
}

char			**ft_array_sub(char **array, int start, int len, char *c)
{
	char		**new_array;
	int			i;

	new_array = (char **)malloc(sizeof(char *) * len + 1);
	if (new_array)
	{
		i = 0;
		while (i < len)
		{
			if (ft_strcmp(array[start], c) != 0)
				new_array[i] = ft_strdup(array[start]);
			else
				break ;
			i++;
			start++;
		}
		new_array[i] = NULL;
		return (new_array);
	}
	return (NULL);
}
