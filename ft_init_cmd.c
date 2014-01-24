/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 11:55:11 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/23 18:03:30 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

t_cmd				*ft_init_cmd(char *line, char flag)
{
	t_cmd			*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd)
	{
		cmd->cmd_line = ft_strdup(line);
		cmd->split_cmd = NULL;
		cmd->next = NULL;
		cmd->split_type = flag;
		cmd->in_redir = 0;
		cmd->out_redir = 0;
		return (cmd);
	}
	return (NULL);
}
