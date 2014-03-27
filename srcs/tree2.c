/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:04:26 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/27 14:04:26 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				ft_and(t_sh *sh, t_node *cur, t_node *left, t_node *right)
{
	int			left_ret;
	int			right_ret;
	int			ret;

	left_ret = ft_seminode(sh, left) / 256;
	if (left_ret == EXIT_SUCCESS)
		right_ret = ft_seminode(sh, right) / 256;
	if (cur->dad)
	{
		if (right->flag == 6 || left_ret != EXIT_SUCCESS)
			exit(left_ret);
		exit(right_ret);
	}
	ret = (right->flag == 6 || left_ret != EXIT_SUCCESS) ? left_ret : right_ret;
	ft_putenv("?", ft_itoa(ret));
	return (ret);
}

int				ft_or(t_sh *sh, t_node *cur, t_node *left, t_node *right)
{
	int			left_ret;
	int			right_ret;
	int			ret;

	left_ret = ft_seminode(sh, left) / 256;
	if (left_ret == EXIT_FAILURE)
		right_ret = ft_seminode(sh, right) / 256;
	if (cur->dad)
	{
		if (right->flag == 6)
			exit(left_ret);
		exit(right_ret);
	}
	ret = (right->flag == 6) ? left_ret : right_ret;
	ft_putenv("?", ft_itoa(ret));
	return (ret);
}
