/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:46:11 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/24 13:50:47 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

t_cmd				*ft_test_in_redir(t_cmd *cmd);
t_cmd				*ft_test_out_redir(t_cmd *cmd);

t_cmd				*ft_test_redir(t_cmd *cmd)
{
	t_cmd			*first;

	first = cmd;

	while (cmd)
	{
		if (cmd->split_type != CMD)
			cmd->split_cmd = ft_test_redir(cmd->split_cmd);
		else
		{
			cmd = ft_test_in_redir(cmd);
			cmd = ft_test_out_redir(cmd);
		}
		cmd = cmd->next;
	}
	return (first);
}

t_cmd				*ft_test_in_redir(t_cmd *cmd)
{
	t_cmd			*first;
	int				i;

	first = cmd;
	while (cmd)
	{
		i = 0;
		while (cmd->cmd_line[i])
		{
			if (cmd->in_redir == 0 && cmd->cmd_line[i] == '<')
			{
				if (cmd->cmd_line[i + 1] && cmd->cmd_line[i + 1] == '<')
					cmd->in_redir = 2;
				else
					cmd->in_redir = 1;
				break ;
			}
			i++;
		}
		cmd = cmd->next;
	}
	return (first);
}

t_cmd				*ft_test_out_redir(t_cmd *cmd)
{
	t_cmd			*first;
	int				i;

	first = cmd;
	while (cmd)
	{
		i = 0;
		while (cmd->cmd_line[i])
		{
			if (cmd->out_redir == 0 && cmd->cmd_line[i] == '>')
			{
				if (cmd->cmd_line[i + 1] && cmd->cmd_line[i + 1] == '>')
					cmd->out_redir = 2;
				else
					cmd->out_redir = 1;
				break ;
			}
			i++;
		}
		cmd = cmd->next;
	}
	return (first);
}
