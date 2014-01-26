/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:51:43 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/26 17:57:47 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

void		ft_error(int error, char *str)
{
	if (error == CMD_NOT_FOUND)
	{
		ft_putstr_fd("ft_minishell2: command not found: ", 2);
		ft_putendl_fd(str, 2);
	}
}
