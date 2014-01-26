/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_pipe_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 13:07:57 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/26 17:33:36 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

int				ft_test_pipe_cmd(t_cmd *cmd, t_sh *p)
{
	char		***cmd1_cmd2;

	cmd1_cmd2 = (char ***)malloc(sizeof(char **) * 2);
	if (cmd1_cmd2)
	{
		cmd1_cmd2[0] = ft_split_trim(cmd->cmd_line, ' ');
		cmd1_cmd2[1] = ft_split_trim(cmd->next->cmd_line, ' ');
		ft_test_pipe_path(p->paths, p, cmd1_cmd2);
		return (0);
	}
	return (-1);
}
