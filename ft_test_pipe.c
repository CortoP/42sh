/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:25:51 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/24 14:45:03 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

t_cmd			*ft_test_pipe(t_cmd *cmd)
{
	int			i;
	t_cmd		*first;

	first = cmd;
	while (cmd)
	{
		i = 0;
		while (cmd->cmd_line[i])
		{
			if (cmd->cmd_line[i] == '|')
			{
				cmd->split_type = PIPE;
				cmd->split_cmd = ft_get_separated_cmd(
					ft_split_trim(cmd->cmd_line, '|'));
				break ;
			}
			i++;
		}
		if (cmd->split_type != PIPE)
			cmd->split_type = CMD;
		cmd = cmd->next;
	}
	return (first);
}
