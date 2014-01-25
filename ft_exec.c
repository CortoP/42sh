/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:40:12 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/25 19:01:04 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

void				ft_reg_exec(t_cmd *cmd, t_sh *p)
{
	ft_test_path(p->paths, p, ft_strsplit(cmd->cmd_line,' '));
}

void				ft_in_exec(t_cmd *cmd, t_sh *p)
{
	char			***cmd_file;
	int				fd;

	(void)p;
	if (ft_valid_redir(cmd->cmd_line, '<') == 0)
	{
		cmd_file = ft_separe_in(ft_split_trim(cmd->cmd_line, ' '));
		fd = open(cmd_file[1][0], O_RDONLY);
		dup2(fd, 0);
		ft_test_path(p->paths, p, cmd_file[0]);
		close(fd);
	}
	else
		write(2, "./ft_minishell2: Unvalid infile redirection\n", 45);
}




void				ft_out_exec(t_cmd *cmd, t_sh *p)
{
	(void)p;
	if (ft_valid_redir(cmd->cmd_line, '>') == 0)
		ft_putchar('O');
	else
		write(2, "./ft_minishell2: Unvalid outfile redirection\n", 46);
}
