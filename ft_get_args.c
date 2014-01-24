/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:25:24 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/24 14:42:51 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

t_cmd				*ft_get_args(char *str)
{
	t_cmd			*cmd;
	int				i;

	cmd = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == ';')
		{
			cmd = ft_get_separated_cmd(ft_split_trim(str, ';'));
			cmd->split_type = SEMIC;
			break ;
		}
		i++;
	}
	if (!cmd)
		cmd = ft_init_cmd(str, CMD);
	ft_test_pipe(cmd);
	ft_test_redir(cmd);
	return (cmd);
}
