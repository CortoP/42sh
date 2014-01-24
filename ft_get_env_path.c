/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 10:10:56 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/23 10:17:51 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

char					**ft_get_env_path(char *var)
{
	char				**paths;

	paths = ft_strsplit(var, ':');
	return (paths);
}
