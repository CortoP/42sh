/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_miniprompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:03:27 by dcojan            #+#    #+#             */
/*   Updated: 2014/03/27 14:03:27 by dcojan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				print_miniprompt(t_cmd *cmd)
{
	int				i;
	static char		*strings[6] = STRINGS;
	int				flag;

	flag = 0;
	i = 5;
	while (i >= 0)
	{
		if (cmd->state_bool[i])
		{
			ft_putstr_fd(strings[i], 2);
			flag = 1;
		}
		i--;
	}
	if (flag)
		ft_putstr_fd("> ", 2);
}
