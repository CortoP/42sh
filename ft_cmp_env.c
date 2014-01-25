/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 14:36:14 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 14:38:52 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

char			ft_cmp_env(char *env, char *cmd)
{
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	while (env[i] != '=' && env[i] != '\0')
	{
		if (env[i] != cmd[i])
			ret = 1;
		i++;
	}
	return (ret);
}
