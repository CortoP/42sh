/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 10:38:11 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/19 15:43:04 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_sh2.h>

char		*ft_get_env(char **env, char *var)
{
	char	*val;
	int		i;

	var = ft_strjoin(var, "=");
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var) - 1) == 0)
		{
			val = ft_strsub(env[i], ft_strlen(var),
							ft_strlen(env[i]) - ft_strlen(var));
			return (val);
		}
		i++;
	}
	return (NULL);
}
