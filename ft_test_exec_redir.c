/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_exec_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:35:33 by vlehuger          #+#    #+#             */
/*   Updated: 2014/01/24 17:22:06 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>

void				ft_test_exec_redir(t_cmd *cmd, t_sh *p)
{
//	if (cmd->in_redir != 0 && cmd->out_redir != 0)
//		ft_in_and_out_exec(cmd, p);
//	else if (cmd->in_redir != 0 && cmd->out_redir == 0)
//		ft_in_exec(cmd, p);
//	else if (cmd->in_redir == 0 && cmd->out_redir != 0)
//		ft_out_exec(cmd, p);
//	else
		ft_reg_exec(cmd, p);
}
